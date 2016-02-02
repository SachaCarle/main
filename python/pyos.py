#!/usr/bin/env python3
import sys, os, code, subprocess, time

class ShadowAttribute:

    def log(self, *args, **kwargs):
        print('[' + self.name + '] ~.' + self.key, *args, **kwargs)

    def __init__(self, master, key, name=None):
        self.name = name
        self.master = master
        self.key = key
        self.log('Access')
        print('nope')

    def __getattr__(self, key):
        self.log('.', key)
        return getattr(self.master, key)

    def __call__(self, *args, **kwargs):
        return getattr(self.master, self.key)(*args, **kwargs)

class localDict(dict):
    
    def __init__(self, name='unknow dict'):
        self.name = name
        self.dict = dict()
        self.__getitem__ = False
        self.__setitem__ = False
        self.__delitem__ = False
        
    def __getattribute__(self, key):
        print('npoe')
        if key in ('name', 'dict'):
            return object.__getattribute__(self, key)
        return ShadowAttribute(master=self.dict, key=key, name=self.name)

# ------------------------------------------ #    
if len(sys.argv) == 1:
    new_locals = localDict()
    new_locals['__builtins__'] = __builtins__
    del new_locals['__builtins__'].__doc__ 
    console = code.InteractiveConsole(new_locals)
    console.interact('Test')
else:
    new_globals = localDict()
    for f in sys.argv[1:]:
        with open(f) as fi:
            txt = fi.read()
            new_locals = localDict()
            exec(txt, new_globals, new_locals)
            
