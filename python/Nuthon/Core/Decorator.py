from Nuthon.Core.Object import *

class MetaDecorator(Meta):

    def __call__(deco, *args, **kwargs):
        obj = deco.__new__(deco, *args, **kwargs)
        if isinstance(obj, deco):
            obj.__init__(*args, **kwargs)
        return obj

class Decorator(Object, metaclass=MetaDecorator):

    def __new__(deco, fct):
        fct = deco.__decorate__(deco, fct)
        fct.__bound__ = deco.__bound__
        return fct

    def __decorate__(deco, fct):
        def _(*args, **kwargs):
            print(">> before")
            fct(*args, **kwargs)
            print(">> after")
        return _

    def __bound__(fct, obj):
        return fct        

class Modificator(Object, metaclass=MetaDecorator):

    @classmethod
    def __bounding__(cls, obj, name, value):
        if value == cls:
            return
        setattr(obj, name, value.__bound__(value, obj))

    def __new__(deco, fct):
        dec = Object.__new__(Modificator)
        return dec

    def __init__(self, fct):
        self.__funct__ = fct
        self.__bounded__ = False

    def __bound__(self, fct, obj):
        self.__self__ = obj
        self.__bounded__ = True
        return self

    def __call__(self, *args, **kwargs):
        if self.__bounded__:
            return self.__funct__(self.__self__, *args, **kwargs)
        else:
             return self.__funct__(*args, **kwargs)

