class Meta(type):

    # Creation Meta

    @classmethod
    def __new_attrs__(meta, name, bases, attrs):
        attrs['_nuthon_legacy'] = []
        for base in bases:
            if hasattr(base, '_nuthon_legacy') and len(getattr(base, '_nuthon_legacy')):
                attrs['_nuthon_legacy'].extend(base._nuthon_legacy)
        for attr in attrs.keys():
            if isinstance(attrs[attr], property):
                attrs['_nuthon_legacy'].append(attr)
        return attrs

    @classmethod
    def __new_init__(meta, name, bases, new):
        pass
        
    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        return dict()

    def __new__(meta, name, bases, attrs):
        attrs = meta.__new_attrs__(name, bases, attrs)
        new = type.__new__(meta, name, bases, dict(attrs))
        meta.__new_init__(name, bases, new)
        return new

    # New Class Behavior

    def __call__(cls, *args, **kwargs):
        obj = cls.__new__(cls, *args, **kwargs)
        if type(obj) == cls:
            obj.__init__(*args, **kwargs)
            if hasattr(obj, '__setting__'):
                obj.__setting__(*args, **kwargs)
        return obj

    def __add__(cls, obj):
        print("Meta.__call__ : %s + %s" % (cls, obj))
