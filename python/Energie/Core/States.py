
class States:

    _dict = {}
    _edict = {}
    _qdict = {}

    def _add(self, dct, key, value, obj):
        if not key in dct:
            dct[key] = {}
        if not value in dct[key].keys():
            dct[key][value] = []
        dct[key][value].append(obj)

    def _exec(self, dct, key):
        if not key in dct:
            return
        if not self._dict[key] in dct[key]:
            return
        [f() for f in dct[key][self._dict[key]]]

    def __getitem__(self, key):
        return self._dict[key]

    def __setitem__(self, key, value):
        self._exec(self._qdict, key)
        self._dict[key] = value
        self._exec(self._edict, key)

    def __delitem__(self, key):
        self[key] = None
        del self._dict[key]

    def enter(self, key, value):
        def _(f):
            self._add(self._edict, key, value, f)
        return _

    def quit(self, key, value):
        def _(f):
            self._add(self._qdict, key, value, f)
        return _
        
    __getattr__ = _dict.__getattribute__

