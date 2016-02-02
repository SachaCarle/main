from Engine import Organ, Environ

@ORGAN.append
class MyOrgan(Organ):
    need = {Water:1}
    hidden_chuncks = list(Organ.hidden_chuncks)
    hidden_chuncks.append('environ')

    class Stockage(Organ):
        need = {Light:2}

    class Finder(Organ):
        need = {Organic:3}

    class environ(Organ):

        def __set__(self, value):
            assert isinstance(value, Environ)
            self.environ = value
