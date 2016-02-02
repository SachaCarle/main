from time import sleep
from threading import Thread
from Engine.Time.Time import Time, ClassTime

class InstanceLocalTime:
    
    def __init__(self, localTime, turn=None):
        self.local = localTime
        if turn != None:
            self.turn = turn
        else:
            self.turn = localTime.turn
        self.activ = True
        
    def __str__(self):
        return 'turn ' + str(self.turn) + ' of ' + str(self.local)

    def uwait(self):
        sleep(0.1)

    def __int__(self):
        return self.turn

    def __iter__(self):
        turn = self.turn
        while True:
            while turn >= self.turn:
                self.uwait()
                if not self.activ:
                    break
            if not self.activ:
                break
            turn += 1
            yield turn
        return False

    def __next__(self):
        while self.turn >= self.local.turn:
            self.uwait()
            if not self.activ:
                return False
        self.turn += 1
        return self

    def __bool__(self):
        return True

class LocalTime(Time):
    passTurn = None
    __next__ = None

    def __init__(self, name='LocalTime', actual=True,
                 activ=True, parallel=Time):
        if actual:
            self.turn = Time.turn
        self.name = name
        self.activ = activ
        if parallel != None:
            parallel.register(self)

    def __iter__(self):
        return InstanceLocalTime(self)

    def __str__(self):
        return self.name + ': ' + str(self.turn)

    def pause(self):
        self.activ = False

    def resume(self):
        self.activ = True

    def update(self, turn):
        self.turn = turn
