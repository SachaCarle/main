#!/usr/bin/env python3

old_import = __builtins__.__import__

def __import__(name, *args):
    print ("IMPORT ", name)
    return old_import(name, *args)

__builtins__.__import__ = __import__
