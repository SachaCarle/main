class Mana:
    
    def __init__(self, element, value):
        self.element = element
        self.value = value

    def __str__(self):
        return '%s(%s)' % (self.element.__name__, self.value)
