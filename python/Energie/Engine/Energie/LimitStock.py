from Engine.Energie.Energie import Energie
from Engine.Energie.Stock import Stock

class LimitStock(Stock):
    
    def __init__(self, limits=None):
        Stock.__init__(self)
        assert limits != None, '%s.__init__ missing argument %s' % (type(self).__name__, 'limit')
        self.limits = limits
        self.filled = False
        self.limitsUpdate()

    def __str__(self):
        s = '[ '
        for e in self.limits:
            if e in self.d:
                s += e + '(%s/%s)' % (self.d[e], self.limits[e])
            else:
                s += e + '(%s/%s)' % ('-', self.limits[e])
        s += ' ]'
        return s
    
    def onLimits(self):
        pass

    def limitsUpdate(self):
        for e in self.d:
            if not e in self.limits:
                assert False, "%s gets unexepected energie %s" % (type(self).__name__, elfe)
            elif self.d[e] > self.limits[e]:
                assert False, "%s overflow on %s: (%s/%s)" %\
                    (type(self).__name__, e, self.d[e], self.limits[e])
            elif self.d[e] < self.limits[e]:
                self.filled = False
                return
        if len(self.d) == len(self.limits):
            if not self.filled:
                self.onLimits()
            self.filled = True
        else:
            self.filled = False

    def remain(self, e):
        assert isinstance(e, Energie)
        if not e in self.limits:
            return 0
        if not e in self.d:
            return self.limits[e]
        return self.limits[e] - self.d[e]

    def increase(self, ee):
        for e in ee:
            assert isinstance(e, Energie)
            if not e in self.limits:
                self.limits[e] = 0
            self.limits[e] += ee[e]

    @Stock.lock
    def _add(self, e, v):
        res = Stock._add(self, e, v)
        self.limitsUpdate()
        return res

    @Stock.lock
    def _subb(self, e, v):
        res = Stock._subb(self, e, v)
        self.limitsUpdate()
        return res

    @world.only
    def fill(self):
        self.set(self.limits)
        self.limitsUpdate()
        return self
