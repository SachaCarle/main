from Core.Builtins import Builtins

def _str(obj):
    if hasattr(obj, 'name'):
        return obj.name
    elif hasattr(obj, '__name__'):
        return obj.__name__
    return str(obj)

class Build:
    dct = {}
    data_dict = {}

    @classmethod
    def register(cls, obj):
        cls.data_dict[_str(obj)] = obj
        if not hasattr(obj, '_build'):
            obj._build = {}
            for field in ('need', 'type', 'use'):
                obj._build[field] = []
        return obj

    @classmethod
    def use(cls, target):
        target = _str(target)
        def _(funct):
            cls.register(funct)
            funct._build['use'].append(target)
            return funct
        return _
    
    def __init__(self, name, objectinstance=None, classinstance=None, make=None):
        Build.dct[name] = self
        Builtins[name] = self
        self.name = name
        self.builded = False
        self.list = []
        self.classinstance = classinstance
        self.objectinstance = objectinstance
        if make != None:
            self.make = make
        self.data_depends = {}
        self.all = []

    def __str__(self):
        return self.name

    def make(self, obj):
        Builtins[_str(obj)] = obj
        self.all.append(obj)
        
    def _type(self):
        assert not self.builded,\
            "Adding new instance to type %s but it's already builded" % self.name
        data << self.name + ' :' << None
        for obj in self.list:
            if self.objectinstance:
                assert isinstance(obj, self.objectinstance),\
                    "%s only accept instance of %s" % (self.name, self.objectinstance)
            if self.classinstance:
                assert isinstance(obj, type),\
                    "%s only accept class, get %s(%s)" % (self.name, type(obj).__name__, obj)
                assert issubclass(obj, self.classinstance),\
                    "%s only accept subclass of %s" % (self.name, self.classinstance)
            self.make(obj)
            data << '\t+' << _str(obj) << None
        self.list = []

    def _build(self):
        self.builded = True
        data << '%s builded.' % self.name << None

    def append(self, obj):
        self.list.append(obj)
        return obj
        
    def type(self, funct):
        Build.register(funct)
        funct._build['type'].append(self)
        self.data_depends[_str(funct)] = funct
        return funct

    def need(self, funct):
        Build.register(funct)
        funct._build['need'].append(self)
        return funct
