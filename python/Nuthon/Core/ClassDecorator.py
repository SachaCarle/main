from Nuthon.Core.Decorator import *

class ClassDecorator(Object, metaclass=MetaDecorator):

    def __new__(deco, cls):
        obj = Object.__new__(deco)
        return obj
    
    def __init__(self, cls):
        self.__cls__ = cls
        self._is_inner = False

    def __call__(self, *args, **kwargs):
        if self._is_inner:
            return self.__cls__(self.__celf__, *args, **kwargs)
        else:
            return self.__cls__(*args, **kwargs)
