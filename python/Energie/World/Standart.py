import time
from random import choice
from Engine import Time, Stock, Environ

def clear():
    loop << "\033[0;0H" << chr(27) + "[2J" 

organ = MyOrgan()
environ = Environ()

print << organ << None << None

organ.ensure()

print << organ << None << None

environ.add(organ)

print << organ << None << None  << environ << None << None

@loop.call
def mainloop():
    for turn in Time:
        if turn > 20:
            return
        clear()
