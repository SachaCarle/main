from Game.Mana import Mana

# Head
class Element:
    def __new__(cls, *args, **kwargs):
        return Mana(cls, *args, **kwargs)
    def __str__(self):
        return type(self).__name__

# Elements
class Water(Element): pass
class Vegetal(Element): pass
class Fire(Element): pass
class Light(Element): pass
class Shadow(Element): pass

# SPecial
class Neutral(Element): pass
