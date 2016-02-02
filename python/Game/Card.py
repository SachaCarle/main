from Ninja.Chunk import MetaChunk, Chunk
from Game.Element import Element

class Card(metaclass=MetaChunk):
    mana = []
    name = "Void Card"
    element = Element
