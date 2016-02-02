deco_legacy = []

def decoLegacy(new, old):
    for s in deco_legacy:
        if hasattr(old, s):
            setattr(new, s, getattr(old, s))

def Flag(**kwargs):
    def deco(f):
        if not hasattr(f, '_flags'):
            f._flags = {}
        for k in kwargs:
            f._flags[k] = kwargs[k]
        return f
    return deco

def hasFlag(f, **kwargs):
    if not hasattr(f, '_flags'):
        return False
    for k in kwargs:
        if not k in f._flags:
            return False
        if f._flags[k] != kwargs[k]:
            return False
    return True

def appendDeco(l):
    def append_decorator(f):
        l.append(f.__name__ if hasattr(f, '__name__') else str(f))
        return f
    return append_decorator
