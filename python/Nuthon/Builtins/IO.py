from types import ModuleType
import sys

class IOBuiltin:
    out = lambda self, obj: sys.stdout.write((str(obj) + ' ') if obj != None else '\n') 

    def __lshift__(self, obj):
        self.out(obj)
        return self

def setBuiltin(name, value):    
    if isinstance(__builtins__, dict):
        __builtins__[name] = value
    elif isinstance(__builtins__, ModuleType):
        setattr(__builtins__, name, value)
    else:
        print(type(__builtins__))
        assert False #Unknow Builtins Type

def getBuiltin(name):    
    if isinstance(__builtins__, dict):
        return __builtins__[name]
    elif isinstance(__builtins__, ModuleType):
        return getattr(__builtins__, name)
    else:
        print(type(__builtins__))
        assert False #Unknow Builtins Type

def newIOBuiltin(name, funct=None):
    if name != 'nu':
        nu << 'New IO Builtin :' << name << None
    setBuiltin(name, IOBuiltin())
    if funct != None:
        getBuiltin(name).out = funct

options = []

def onArgvPrint(name):
    options.append('--' + name)
    if '--' + name in sys.argv:
        def argvPrint(obj):
            return IOBuiltin.out(None, obj)
        return argvPrint
    def argvPrint(obj):
        return None
    return argvPrint

newIOBuiltin('nu', onArgvPrint('nuthon'))
