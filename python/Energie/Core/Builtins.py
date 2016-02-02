from types import ModuleType
import sys

from Core.States import *

states = States()
def stdprint(obj):
    if obj != None:
        sys.stdout.write(str(obj) + ' ')
    else:
        sys.stdout.write('\n')

class MetaBuiltins(type):

    def keys(self):
        if isinstance(__builtins__, dict):
            return __builtins__.keys()
        elif isinstance(__builtins__, ModuleType):
            return dir(__builtins__)
        else:
            assert False, "Unknow __builtins__ type: %s" % str(type(__builtins__))

    def __getattr__(self, name):
        if name in states.keys():
            return states[name]
        if isinstance(__builtins__, dict):
            return __builtins__[name]
        elif isinstance(__builtins__, ModuleType):
            return getattr(__builtins__, name)
        else:
            assert False, "Unknow __builtins__ type: %s" % str(type(__builtins__))

    def __delattr__(self, name):
        if name in states.keys():
            del states[name]
        if isinstance(__builtins__, dict):
            del __builtins__[name]
        elif isinstance(__builtins__, ModuleType):
            delattr(__builtins__, name)
        else:
            assert False, "Unknow __builtins__ type: %s" % str(type(__builtins__))

    def __setattr__(self, name, value):
        if name in states.keys():
            states[name] = value
        if isinstance(__builtins__, dict):
            __builtins__[name] = value
        elif isinstance(__builtins__, ModuleType):
            setattr(__builtins__, name, value)
        else:
            assert False, "Unknow __builtins__ type: %s" % str(type(__builtins__))

    __getitem__ = __getattr__
    __setitem__ = __setattr__
    __delitem__ = __delattr__

class Builtins(metaclass=MetaBuiltins):
    
    @staticmethod
    def newIO(funct=None):
        io = IOBuiltin()
        if funct != None:
            io.out = funct
        return io

    @classmethod
    def registerState(cls, name):
        states[name] = None
        
class IOBuiltin(Builtins):
    out = staticmethod(stdprint)
    def __lshift__(self, x):
        self.out(x)
        return self
    def __call__(self, *args):
        for arg in args:
            self << arg
        self << None

def onArgvPrint(name):
    if '--' + name in sys.argv or '--all' in sys.argv:
        return None
    def argvPrint(obj):
        return None
    return argvPrint
