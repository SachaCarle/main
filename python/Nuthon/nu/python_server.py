#!/usr/bin/env python3

def server_loop():
    __name__ = '__server__'
    import os
    from time import sleep
    if not os.path.exists('pytt'):
        os.mkfifo('pytt')
    fifo = open('pytt')
    i = 0
    while True:
        s = fifo.read()
        while s == '':
            sleep(0.01)
            s = fifo.read()
        print('<INPUT:%s>%s<INPUT>' % (i, s))
        try:
            res = exec(s)
        except Exception as e:
            res = e
        print('<OUTPUT:%s>%s<OUTPUT>' % (i, res))
        i += 1

if __name__ == '__main__':
    server_loop()


# INPUT
#       > [EXEC]
#                > STDOUT
#                > STDERR
#                > PY_RESULT
