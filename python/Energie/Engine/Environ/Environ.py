from Core import Build, Chunck

class Environ(Chunck):
    
    def __init__(self, host=None):
        Chunck.__init__(self, host=host)
        self.list = []

    def add(self, obj):
        self.list.append(obj)
        obj.environ = self

    def remove(self, obj):
        self.list.remove(obj)
        obj.environ = None

    def has(self, obj):
        return obj in self.list

    def __repr__(self):
        return type(self).__name__

    def __str__(self):
        return repr(self) + ' : { ' +\
            ', '.join([repr(o) for o in self.list]) + ' }'

Build('ENVIRON', classinstance=Environ)
