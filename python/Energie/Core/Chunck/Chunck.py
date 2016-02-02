from Core.String import _deep

class MetaChunck(type):
    
    @classmethod
    def apply_chunck(meta, bases, attrs, chuncks):
        for base in bases:
            if hasattr(base, 'chuncks'):
                for c in base.chuncks:
                    chunks.add(c)
            for attr_name in attrs:
                if attr_name in chuncks:
                    continue
                attr = attrs[attr_name]
                if isinstance(attr, type) and issubclass(attr, Chunck):
                    chuncks.add(attr_name)        

    def __new__(meta, name, bases, attrs):
        chunks = set()
        attrs['chuncks'] = chunks
        if name != 'Chunck':
            meta.apply_chunck(bases, attrs, chunks)
        new = type.__new__(meta, name, bases, dict(attrs))
        return new        

class Chunck(metaclass=MetaChunck):
    hidden_chuncks = []

    def __init__(self, host=None):
        for c in self.chuncks:
            getattr(self, c).guest_name = c
            setattr(self, c, getattr(self, c)(self))
        self.host = host
        if hasattr(type(self), 'guest_name'):
            del type(self).guest_name

    def __repr__(self):
        return type(self).__name__

    def __str__(self, deep=0):
        if len(self.chuncks):
            return self.dump(deep)
        return repr(self)

    def dump(self, deep):
        s = _deep(deep)+ repr(self) + ' {\n'
        for c in self.chuncks:
            if not c in self.hidden_chuncks:
                s += _deep(deep + 1) + getattr(self, c).__str__(deep + 1) + '\n'
        s += _deep(deep) + '}'
        return s

    def __setattr__(self, key, value):
        if not key in self.chuncks or not key in self.__dict__:
            self.__dict__[key] = value
            return
        return self.__dict__[key].__set__(value)
        assert False, "%r setattr %r = %r" % (self, key, value)

    def __getattr__(self, key):
        if not key in self.chuncks:
            raise AttributeError('%r has no attribute %r' % (self, key))
        if key in self.__dict__:
            return self.__dict__[key].__get__()
        if hasattr(type(self), key):
            return getattr(type(self), key)
        return self.__dict__[key].__get__()

    def __set__(self, value):
        assert self.host != None
        assert False, "%s don't have create set access" % repr(self)
    
    def __get__(self):
        assert self.host != None
        return self
