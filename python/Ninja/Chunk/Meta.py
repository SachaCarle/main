from Ninja.Chunk.Chunk import Chunk

class MetaChunk(type):

    def __new__(meta, name, bases, attrs, **kwds):
        attrs['chunks'] = {an:av for an, av in attrs.items()
                           if isinstance(av, type) and issubclass(av, Chunk)}
        cls = type.__new__(meta, name, bases, attrs)
        return cls

    def __call__(cls, **kwargs):
        obj = type.__call__(cls, **kwargs)
        for cn, cv in obj.chunks.items():
            setattr(obj, cn, cv(master=obj, **kwargs))
        return obj
