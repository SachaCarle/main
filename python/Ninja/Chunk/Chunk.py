class NoValue: pass

class Chunk:

    def __init__(self, master=None, **kwargs):
        self.master = master
        self.kwargs = kwargs

    @classmethod
    def Kwargs(cls, name, default=NoValue):
        def _kwargs(self):
            if not name in self.kwargs:
                if default is not NoValue:
                    return default
                else:
                    raise Exception("%s require %s in kwargs."\
                                    % (type(self.ent).__name__, name))
            return self.kwargs[name]
        return property(_kwargs)
