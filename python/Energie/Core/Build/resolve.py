from Core.Builtins import Builtins, onArgvPrint
from Core.Build import Build

builds = None
datas = None

def _msg(deep, msg):
    return ' ' + '|   ' * deep + '[%s]' % msg

def resolveBuild(build, deep):
    if not build in builds:
        buildtree << _msg(deep, '___Ok___') << build.name << None
        return
    buildtree << _msg(deep, '_Build__') << build.name << None
    if len(build.data_depends):
        buildtree << _msg(deep + 1, '__Type__') << ':' << None
    for data_name in build.data_depends:
        data_value = build.data_depends[data_name]
        resolveData(data_name, data_value, deep + 1)
    build._build()
    builds.remove(build)
    buildtree << _msg(deep, 'Builded_') << build.name << None
    return

def resolveData(name, data, deep):
    if not name in datas:
        buildtree << _msg(deep, '___Ok___') << name << None
        return
    buildtree << _msg(deep, '__Data__') << name << None
    # Need 
    if len(data._build['need']):
        buildtree << _msg(deep + 1, '__Need__') << ':' << None        
    for build in data._build['need']:
        resolveBuild(build, deep + 1)
    # Use
    if len(data._build['use']):
        buildtree << _msg(deep + 1, '__Use___') << ':' << None        
    for data_name in data._build['use']:
        resolveData(data_name, Build.data_dict[data_name], deep + 1)
    #
    buildtree << _msg(deep + 1, 'Loading_') << name << None
    data()
    #
    # Type
    if len(data._build['type']):
        buildtree << _msg(deep + 1, 'Updating') << ':' << None
    for build in data._build['type']:
        buildtree << _msg(deep + 1, '___Up___') << build.name << None
        build._type()
    del datas[name]
    buildtree << _msg(deep, 'Builded_') << name << None
    return

def resolveBuildData():
    Builtins.buildtree = Builtins.newIO(onArgvPrint('build'))
    buildtree << ">> BUILD" << None
    global builds
    global datas
    builds = list(Build.dct.values())
    datas = dict(Build.data_dict)
    while len(datas) > 0:
        data_name = tuple(datas.keys())[0]
        data_value = datas[data_name]
        resolveData(data_name, data_value, 0)
    while len(builds) > 0:
        build = builds[0]
        resolveBuild(build, 0)
    buildtree << ">> END BUILD" << None
    buildtree << '[PurityTest] :' << builds << datas << None
    Builtins.buildtree = None
    return
