from Nuthon.Core.Meta import *

def nudir(obj):
    if not hasattr(obj, '_nuthon_legacy'):
        return dir(obj)
    for attr in dir(obj):
        if attr not in obj._nuthon_legacy:
            yield attr

class Object(metaclass=Meta):

    @classmethod
    def __bounding__(cls, obj, name, value):
        if value == cls:
            return
        setattr(obj, name, value.__bound__(value, obj))

    @classmethod
    def __innering__(cls, obj, name, value):
        if value == cls:
            return
        setattr(obj, name, value.__inner__(value, obj, name=name))

    def __new__(cls, *args, **kwargs):
        obj = object.__new__(cls)
        for attr in nudir(obj):
            if hasattr(getattr(obj, attr), '__bound__'):
                cls.__bounding__(obj, attr, getattr(obj, attr))
            if hasattr(getattr(obj, attr), '__inner__'):
                cls.__innering__(obj, attr, getattr(obj, attr))
        return obj

    def __setting__(obj, *args, **kwargs):
        for attr_name in nudir(obj):
            attr_value = getattr(obj, attr_name)
            if hasattr(attr_value, '__setup__'):
                attr_value.__setup__(attr_value)            
