from Nuthon.Core.ClassDecorator import *

class innerDefinition(Object):

    def __init__(self, *args, **kwargs):
        self.args = args
        self.kwargs = kwargs

    def __inner__(self, value, obj, name=None):
        inner = ClassDecorator.__call__(*self.args, **self.kwargs)
        inner.outer = obj
        inner.inner_as = name
        obj = inner
        return obj

class innerClass(ClassDecorator):
    
    def __call__(self, *args, **kwargs):
        return innerDefinition(self, *args, **kwargs)
