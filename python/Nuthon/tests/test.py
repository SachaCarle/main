#!/usr/bin/env python3

from Nuthon.Meta import *

# A
class Object(metaclass=Meta, typ=list):
    class nu:
        def test(*args):
            print("nope")
    a = 10

a = Object()
assert isinstance(a, a.nu.typ)
assert isinstance(a, Object)
assert issubclass(Object, Object.nu.typ)

# B
class SubObject(Object):
    b = 20

b = SubObject(typ=int)
assert isinstance(b, SubObject)
assert isinstance(b, Object)
assert isinstance(b, SubObject.nu.typ)
assert isinstance(b, Object.nu.typ)
assert issubclass(SubObject, Object)
assert issubclass(SubObject, SubObject.nu.typ)
assert issubclass(SubObject, Object.nu.typ)

# Make more tests
