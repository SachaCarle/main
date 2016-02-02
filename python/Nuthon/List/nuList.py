from Nuthon.Core.Object import *

class nuList(list, Object):
    
    def append(self, obj):
        list.append(self, obj)
        return obj
