from time import sleep
from threading import Thread

#-Meta-Class-Time-Manager----------------#
class ClassTime(type):

    def __str__(cls):
        return 'Global turn: ' + str(cls.turn)
    
    def __int__(cls):
        return cls.turn

    __repr__ = __str__

    def __iter__(cls):
        return Time()

#-Class-Time-Manager---------------------#
class Time(metaclass=ClassTime):
    turn = 0
    passTurn = staticmethod(lambda: sleep(1))
    uwait = staticmethod(lambda: sleep(0.1))
    started = False
    locals = []

    def __init__(self, turn=None):
        if turn == None:
            self.turn = Time.turn
        else:
            self.turn = turn

    def __str__(self):
        return 'turn:' + str(self.turn)
    
    __repr__ = __str__
    
    def __next__(self):
        while self.turn >= Time.turn:
            self.uwait()
        self.turn += 1
        return self.turn

    def __iter__(self):
        return Time(self.turn)

    @classmethod
    def daemon(cls, funct, name=None, *args, **kwargs):
        if name == None:
            name = str(funct)
        t = Thread(target=funct, name=name, args=args, kwargs=kwargs, daemon=True)
        if not loop:
            loop.call(t.start)
        else:
            t.start()
        return t

        
    @classmethod
    def register(cls, local):
        assert isinstance(local, Time)
        cls.locals.append(local)

    @classmethod
    def update(cls):
        for local in cls.locals:
            if local.activ:
                local.update(Time.turn)

@Time.daemon
def timeDaemon():
    daemon << 'Global time launched.' << None
    while True:
        Time.turn += 1
        Time.update()
        if True:
            daemon << Time << None
        Time.passTurn()
