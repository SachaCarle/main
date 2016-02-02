import sys

from Core.Builtins import states, Builtins, IOBuiltin
from Core.Build.Build import _str
from Core.Decorator import decoLegacy

class BuildTime(IOBuiltin):

    def __init__(self, name):
        self.name = name
        self.__str__ = lambda: "BuilTime(%s)" % name
        states.enter('BUILD_TIME', name)(self.enter)
        states.quit('BUILD_TIME', name)(self.quit)
        setattr(Builtins, name, self)
        if not ('--' + name in sys.argv or '--all' in sys.argv):
            self.out = lambda x: None
        self.on = False
        self.callist = []

    def enter(self):
        assert not self.on
        self.on = True
        self << ">" << self.name.upper() << None
        [o() for o in self.callist]

    def __lshift__(self, obj):
        assert self.on, 'Can only use this output when at %s time' % self.name
        return IOBuiltin.__lshift__(self, obj)

    def quit(self):
        assert self.on
        self << "> END" << self.name.upper() << None
        self.on = False

    def __bool__(self):
        return self.on

    def only(self, obj):
        def _(*args, **kwargs):
            assert self.on, 'Object %s can only be used at %s time' % (_str(obj), self.name)
            return obj(*args, **kwargs)
        decoLegacy(obj, _)
        return _

    def call(self, obj):
        self.callist.append(obj)
        return obj
