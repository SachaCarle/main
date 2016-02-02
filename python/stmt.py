#!/usr/bin/env python3

from types import SimpleNamespace
import sys

keyword = ['class', 'def', 'for', 'if', 'in', 'elif', 'else', 'and', 'or', 'id', 'not']
varchar = "aqwzsxedcrfvtgbyhnujikolpmAQWZSXEDCRFVTGBYHNUJIKOLPM_"
numchar = "0123456789"
spacetab = " \t"
block_list = [varchar, numchar, spacetab]

class MulSplit:

    def __init__(self, l, *blocks):
        self.isact = None
        self.list = []
        self.blocks = []
        for b in blocks:
            s = SimpleNamespace()           
            s.str = ""
            s.blc = b
            self.blocks.append(s)
        for c in l:
            self.addchar(c)

    def addtoblock(self, c, block):
        if self.isact == None or c in self.isact.blc:
            block.act = True
            self.isact = block
            block.str += c
            return
        self.endblock()
        self.addtoblock(c, block)
        return
            
    def addchar(self, c):
        for block in self.blocks:
            if c in block.blc:
                self.addtoblock(c, block)
                return
        if self.isact != None:
            self.endblock()
        self.list.append(c)
        return
                
    def endblock(self):
        assert self.isact != None
        self.list.append(self.isact.str)
        self.isact.str = ''
        self.isact = None
        
    def tolist(self):
        return list(self.list)

def mulsplit(l, *args):
    return MulSplit(l, *args).tolist()

def parse(l):
    return mulsplit(l, *block_list)

def modify(l):
    s = ''.join(parse(l)[1:])
    return s

def process(f=sys.stdin):
    while True:
        l = f.readline()
        if l == '':
            return
        yield modify(l)
        
for l in process():
    print(l, end='')
