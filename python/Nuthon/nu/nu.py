#!/usr/bin/env python
from sys import argv, stdin, stdout
import string
import code
import shlex
from shlex_test import shlex_test
from code import InteractiveInterpreter, InteractiveConsole

NO_EXEC = True

banner = "\n ~ Nuthon Dev version ~\n"

_compile_command = code.compile_command
def compile_command(source, filename='<input>', symbole='single'):
    print(source)
    print("YYAAAYYYYYY ")
    return _compile_command(source, filename, symbole)
code.compile_command = compile_command

syntax_error = None

_showsyntaxerror = InteractiveInterpreter.showsyntaxerror
def showsyntaxerror(self, filename=None):
    if NO_EXEC:
        return 
    _showsyntaxerror(self, filename)
    if self._raise:
        raise Exception("SyntaxError")
InteractiveInterpreter.showsyntaxerror = showsyntaxerror

def is_usable(a, b, plain, splitted, i):
    if ((a[-1] in string.ascii_letters + string.digits) and
        (b[0] in string.ascii_letters + string.digits + "{[")):
        return True
    return False

def test(s):
    shlex_test(s)
    return
    ss = s.split(' ')
    ss = [s for s in ss if s != '']
    if len(ss) == 0:
        return
    for i in range(len(ss) - 1):
        if is_usable(ss[i], ss[i + 1], s, ss, i):
            print(s, '\n\t', ss[i], ss[i+1], '\n')

def parse(l):
    test(l)
    return l

def nu_raw_input(ic, prompt="nu>"):
    stdout.write(prompt)
    stdout.flush()
    s = stdin.readline()
    s = s.split('\n')[0]
    s = parse(s)
    return ""
    return s
InteractiveConsole.raw_input = nu_raw_input

class Locals(dict):

    def __getitem__(self, key):
        #print('locals >> access ', key)
        return dict.__getitem__(self, key)

def main(i=False, fil=None, local=Locals(), filename='<console>'):
    ic = InteractiveConsole(local, filename)
    ic._raise = True
    ic.push('from Nuthon import *')
    try:
        if fil != None:
            ic.push('try:')
            src = fil.read()
            for l in src.split('\n'):
                l = parse(l)
                ic.push('\t' + l)
            ic.push('except:')
            ic.push('\traise')
    except Exception as e:
        if not "SyntaxError" in str(e):
            raise
    if i:
        ic.resetbuffer()
        ic._raise = False
        if fil != None:
            ic.interact("")
        else:
            ic.interact(banner)
                
    
    
a = 0
i = False
if '-i' in argv:
    a += 1
    i = True

if __name__ == '__main__':
    if len(argv) > 1:
        with open(argv[a + 1]) as f:
            main(i=i,
                 fil=f,
                 filename=argv[a + 1])
    else:
        i = True
        main(i=i)
