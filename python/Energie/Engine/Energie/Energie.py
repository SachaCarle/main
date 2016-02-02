from Core import Build, Builtins

class Energie(str): pass

Build('ENERGIE', str)

def make(energie):
    energie = Energie(energie)
    Builtins[str(energie)] = energie
    ENERGIE.all.append(energie)

ENERGIE.make = make
