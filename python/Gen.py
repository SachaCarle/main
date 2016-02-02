from random import choice, randint

class Iter:
    
    def __init__(self, size, funct):
        self.i = 0
        self.size = size
        self.funct = funct

    def __iter__(self):
        return self
    
    def __next__(self):
        if self.i < self.size:
            self.i += 1
            return self.funct()
        raise StopIteration

class Gen:

    def __init__(self, *choices):
        if len(choices) == 1:
            self.choices = choices[0]
        else:
            self.choices = choices

    def __iter__(self):
        return self

    def __next__(self):
        return self.gen()

    def gen(self):
        return choice(self.choices)

    def __call__(self, size):
        return Iter(size, self.gen)

    def __bool__(self):
        return bool(self.gen())

    def __int__(self):
        return int(self.gen())

binGen = Gen(True, False)

class StockGen(Gen):
    
    def __init__(self, choices, last=False):
        Gen.__init__(self, choices);
        self.last = last
        self.sum = sum(self.choices.values())
        
    def gen(self):
        if self.sum == 0:
            return self.last
        x = randint(0, self.sum)
        a = 0
        for k in self.choices.keys():
            a += self.choices[k]
            if a >= x:
                self.sum -= 1
                self.choices[k] -= 1
                return k
        assert False
