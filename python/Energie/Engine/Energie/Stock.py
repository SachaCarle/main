from Core import Builtins, Controller, controllerConstruct

_key = 'StockLegacyController'

class Stock:
    
    nocare, care, lock, reject = controllerConstruct(_key)

    def __init__(self):
        self.d = {}

    def __str__(self):
        s = '[ '
        for e in self.d:
            if self.d[e] != 0:
                s += e + '(%s) ' % self.d[e]
        s += ']'
        return s

    @lock
    def _sub(self, e, v):
        assert self.d[e] >= v, 'This stock do not have enought %s, %s required' % (e, v)
        self.d[e] -= v

    @lock
    def _add(self, e, v):
        if not e in self.d:
            self.d[e] = 0
        self.d[e] += v

    def has(self, ee):
        for e in ee:
            if not e in self.d:
                return False
            if ee[e] > self.d[e]:
                return False
        return True

    @world.only
    def set(self, ee, method='set'):
        assert isinstance(ee, dict)
        if method == 'set':
            self.d = dict(ee)
        else:
            for e in ee:
                if not e in self.d:
                    self.d[e] = 0
                self.d[e] = method(self.d[e], ee[e])
                assert isinstance(self.d[e], int), "Stock's values must be integer"
                assert self.d[e] >= 0, "Stock's values must be greater or equal to zero"

    @classmethod
    @reject
    def give(cls, a, b, ee):
        assert hasattr(a._sub, '_controller') and hasattr(b._add, '_controller'),\
            'Error on _sub(%s) _add(%s) from %s and %s' % (a._sub, b._add, a, b)
        assert a._sub._controller[_key] == True
        assert b._add._controller[_key] == True
        with cls.care:
            for e in ee:
                a._sub(e, ee[e])
                b._add(e, ee[e])
