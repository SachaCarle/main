#!/usr/bin/env python3

from Gen import *
from Node import *

#gen = Gen((True, True, False))
gen = StockGen({True:200, False:100}, last=False)
a = []
b = []

def getbool():
    b = bool(gen)
#    print (b)
    return b

def makeNode():
    global a
    node = Node()
    while getbool():
        a.append(node)
    return node

def makeTree():
    i = 0
    global a
    node = makeNode()
    a.append(node)
    while len(a) > 0:
        b = a
        a = []
        for n in b:
            new = makeNode()
            n + new
        i += 1
        gen.choices[True] += i ** 2
        gen.choices[False] += i ** 2
        gen.sum = sum(gen.choices.values())
        if i > 100:
            return node
    return node

res = makeTree()
print(res.dump(size=True, max_deep=10))
print(res.count())
print(res.max_deep())
