from Core import Chunck, Build
from Engine.Energie import LimitStock, Stock

class OrganStock(LimitStock):

    def __init__(self, organ=None):
        assert organ != None
        LimitStock.__init__(self, limits=organ.need)
        self.organ = organ

    @Stock.lock
    def _sub(self, e, v):
        if self.organ.state != 'dead':
            assert False, "Can't remove energie %r is not dead" % self.organ
        return LimitStock._sub(self, e, v)

class Organ(Chunck):
    need = {}
    no_access = []
    full_access = []

    def __init__(self, host=None):
        Chunck.__init__(self, host=host)
        self.stock = OrganStock(organ=self)
        self.live = True

    def strOrgan(self):
        if not self.stock.filled:
            return ' ' + str(self.stock)
        return ''

    @property
    def state(self):
        if not hasattr(self, 'stock'):
            return 'partial'
        if not self.stock.filled:
            return 'partial'
        if not self.live:
            return 'dead'
        return 'living'

    def die(self):
        self.live = False

    def __str__(self, deep=0):
        if self.state == 'living':
            return Chunck.__str__(self).replace(repr(self), repr(self) + self.strOrgan())
        if self.state == 'dead':
            return '(Dead)' + Chunck.__str__(self, deep=deep)\
                                    .replace(repr(self), repr(self) + self.strOrgan())
        if self.state == 'partial':
            return '(Partial)' + repr(self) + ' ' + self.strOrgan()
        assert "%r has unknow state : %r" % (self, self.state)

    def __getattribute__(self, key):
        if key in ('chuncks', 'no_access', 'full_access'):
            return Chunck.__getattribute__(self, key)
        if not key in self.chuncks and not key in self.no_access:
            return Chunck.__getattribute__(self, key)
        if hasattr(self, 'stock'):
            if not key in self.full_access:
                assert self.stock.filled, "Trying to access %s.%s but %s not filled." %\
                    (repr(self), key, repr(self))
        return Chunck.__getattribute__(self, key)

    @world.only
    def ensure(self):
        self.stock.fill()
        for c in self.chuncks:
            c = getattr(self, c)
            if hasattr(c, 'ensure'):
                c.ensure()
        return self
    
Build('ORGAN', classinstance=Organ)
