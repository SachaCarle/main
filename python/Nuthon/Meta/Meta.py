from types import SimpleNamespace


class Meta(type):
    
    def __new__(meta, name, bases, attrs, typ=object, args=(), **kwargs):
        #print('Meta.__new__', meta, name, bases, attrs)
        bases = list(bases)
        bases.append(typ)
        bases = tuple(bases) # check some things about legacy of typ when nuthon's object in bases
        for attr_name in attrs:
            print(attr_name)
        cls = type.__new__(meta, name, bases, dict(attrs))
        # Improve nu object management
        if not hasattr(cls, 'nu'):
            cls.nu = SimpleNamespace()
        cls.nu.typ = typ
        cls.nu.args = args
        cls.nu.kwargs = kwargs
        return cls
    
    def __init__(cls, name, bases, attrs, **kwargs):
        #print('Meta.__init__', cls, name, bases, attrs, kwargs)
        pass

    def __call__(cls, *args, **kwargs):
        #print('Meta.__call__', cls, args, kwargs)
        obj = cls.__new__(cls, *cls.nu.args, **cls.nu.kwargs)
        if not hasattr(obj, 'nu'):
            obj.nu = SimpleNamespace()
        obj.nu.typ = cls.nu.typ
        #obj.__class__ = obj.nu.typ
        return obj
        
