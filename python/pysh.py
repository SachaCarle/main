#!/usr/bin/env python

def pysh(cmd, local=None):
    try:
        return eval(cmd)
    except NameError as e:
        a = e
        if not (e.args[0].startswith("name '") and
                e.args[0].endswith("' is not defined")):
            raise
        module = e.args[0].split("'")[1]
        globals()[module] = __import__(module)
        return pysh(cmd, local)
    except RuntimeError as e:
        return(e)

if __name__=='__main__':
    import sys as _sys
    cmd = ' '.join(_sys.argv[1:])
    #print(cmd)
    print(pysh(cmd, {}))
