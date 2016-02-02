

class Node:
    char = '#'

    def __init__(self):
        self.elems = []

    def __add__(self, obj):
        self.elems.append(obj)

    def __len__(self):
        return len(self.elems)

    def __str__(self):
        c = self.count() - 1
        return self.char + (str(c) if c > 0 else '-')

    def get_size(self, deep, size):
        if deep == 0:
            return ""
        d = str(deep)
        s = ' ' * deep
        if len(d) > len(s):
            return s
        return d + ' ' * (len(s) - len(d))        

    def dump(self, deep=0, size=False, min_size=False, max_deep=False):
        if max_deep != False:
            if deep > max_deep:
                return ''
        s = self.get_size(deep, size) + str(self) + '\n'
        for e in self.elems:
            if min_size != False:
                if e.count() > min_size:
                    s += e.dump(deep + len(self.char), size=size, min_size=min_size, max_deep=max_deep)
            else:
                s += e.dump(deep + len(self.char), size=size, min_size=min_size, max_deep=max_deep)
        return s

    def count(self):
        s = 1
        for e in self.elems:
            s += e.count()
        return s

    def max_deep(self, deep=0):
        l = [e.max_deep(deep + 1) for e in self.elems]
        if len(l) == 0:
            return deep
        return deep + max(l)
