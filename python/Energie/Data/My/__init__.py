from Core import Build

@ENERGIE.type
def MyEnergie():
    [ENERGIE.append(s) for s in ('Water', 'Organic', 'Light', 'Mineral')]

@ORGAN.type
@Build.use(MyEnergie)
def MyOrgan():
    import Data.My.Organ
