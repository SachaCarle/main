from Core.Decorator import deco_legacy

deco_legacy.append('_controller')

state = {}

class ControllerCare:

    def __init__(self, key, init):
        self.key = key
        state[key] = init

    def __enter__(self):
        assert not state[self.key]
        state[self.key] = True

    def __exit__(self, *args):
        assert state[self.key]
        state[self.key] = False

class ControllerNoCare:

    def __init__(self, key, init):
        self.key = key
        state[key] = init

    def __enter__(self):
        assert state[self.key]
        state[self.key] = False

    def __exit__(self, *args):
        assert not state[self.key]
        state[self.key] = True

def ensureController(old, new, name):
    if not hasattr(new, name):
        if hasattr(old, name):
            new._controller = dict(getattr(old, name))
        else:
            new._controller = {}

def ControlDecoratorOn(key):
    def apply(f):
        def ret(*args, **kwargs):
            assert state[key], "%s is unlocked" % key
            return f(*args, **kwargs)
        ensureController(f, ret, '_controller')
        ret._controller[key] = True
        return ret
    return apply        

def ControlDecoratorOff(key):
    def apply(f):
        def ret(*args, **kwargs):
            assert not state[key], "%s is locked." % key
            return f(*args, **kwargs)
        ensureController(f, ret, '_controller')
        ret._controller[key] = False
        return ret
    return apply

def controllerConstruct(key, self=None):
    nocare = ControllerNoCare(key, False)
    care = ControllerCare(key, False)
    lock = ControlDecoratorOn(key)
    reject = ControlDecoratorOff(key)
    if self == None:
        return nocare, care, lock, reject
    else:
        self.nocare, self.care, self.lock, self.reject =\
        nocare, care, lock, reject
        return self

class Controller:
    def __init__(self, key):
        controllerConstruct(key, self)
