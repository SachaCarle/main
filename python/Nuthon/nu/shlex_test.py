#!/usr/bin/env python
import sys

__builtins__.line = 0

from shlex import shlex
import string

def get_line():
    return __builtins__.line
def incr_line():
    __builtins__.line += 1

class nuToken:
    def action(self):pass
    def __init__(self, s):
        self.s = s
        self.action()
        self.line = get_line()
    def __str__(self):
        return ' "%s"  > %s' % (self.s, self.__class__.__name__)

class UnknowToken(nuToken):
    def __init__(self, t):
        self.s = t
        print("Token not set |%s|" % t)
    



class strToken(nuToken):pass
class nameToken(nuToken):pass
class keywordToken(nuToken):pass
class spaceToken(nuToken):pass
class opToken(nuToken):pass

class simpleToken(nuToken):pass

class dotToken(simpleToken):pass
class doubleDotToken(simpleToken):pass
class atToken(simpleToken):pass
class comaToken(simpleToken):pass
class dotComaToken(simpleToken):pass
class returnToken(simpleToken):
    def action(self):
        incr_line()



class openToken(simpleToken):pass

class parentOpen(openToken):pass
class crochOpen(openToken):pass
class bracketOpen(openToken):pass


class closeToken(simpleToken):pass
    
class parentClose(closeToken):pass
class crochClose(closeToken):pass
class bracketClose(closeToken):pass


simple_tokens = (
    (dotToken, '.'),
    (doubleDotToken, ':'),
    (atToken, '@'),
    (dotComaToken, ';'),
    (comaToken, ','),
    (parentOpen, '('),
    (parentClose, ')'),
    (crochOpen, '['),
    (crochClose, ']'),
    (bracketOpen, '{'),
    (bracketClose, '}'),
    (returnToken, '\n'),
)

keyword = "from import if else except try catch class def for in not with as elif and lambda return raise"
keyword = keyword.split(' ')
ops = "= + - += -= == != ^ & ~ ^= &= ~= | |= < > << >> <= >= % / // *".split(' ')

alphanum = string.ascii_letters + string.digits + '_'

rules = {
    opToken: lambda t: t in ops,
    spaceToken: lambda t: not (False in [c in ' \t' for c in t]),
    strToken: [lambda t: t[0] == '"' and t[-1] == '"',
               lambda t: t[0] == "'" and t[-1] == "'",
           ],
    keywordToken: lambda t: t in keyword,
    nameToken: lambda t: not (False in [(c in alphanum) for c in t]),
}
sptk_d = _ = {name: value.__eq__ for (name, value) in simple_tokens}
rules.update(_)

priority = [opToken, spaceToken, strToken, keywordToken, nameToken]
sptk_p = [_[0] for _ in simple_tokens]
priority.extend(sptk_p)

def token(t, test=False):
    for c in priority:
        r = rules[c]
        if isinstance(r, (list, tuple)):
            for f in r:
               if f(t):
                   return c(t)
        else:
            if r(t):
                return c(t)
    return UnknowToken(t)
        

def nu_tokenize(l):
    return [token(t) for t in l]

def nu_is_object(ntk, i):
    if isinstance(ntk[i], (keywordToken, opToken, spaceToken)):
        return False
    return True

def nu_detect_usable(ntk):
    l = list()
    for i in range(len(ntk) - 1):
        if not isinstance(ntk[i], nameToken):
            continue
        if not isinstance(ntk[i + 1], spaceToken):
            continue
        res = nu_is_object(ntk, i + 2)
        if not res:
            continue
        l.append(i)
    return l

def get_info(s, l, ntkl, ntk):
    if len(ntkl) == 0:
        return
    #print(s)
    for i in ntkl:
        print('>', l[i], ntk[i + 2], ntk[i].line)

def first_parse(s):
    shx = shlex(s, posix=False)
    shx.whitespace = ""
    try:
        l = list(shx)
    except ValueError:
        print(s, '\n')
        raise
    nl = []
    for i in range(len(l)):
        if l[i].startswith("u'") or l[i].startswith('u"'):
            print("OOOOZODOZJDOZJDOJ")
            print(l[i])
            #nl.append('')
            nl.append(l[i][1:])
        else:
            nl.append(l[i])
    return ''.join(nl)

def shlex_test(s):
    s = first_parse(s)
    shx = shlex(s, posix=False)
    shx.whitespace = ""
    try:
        l = list(shx)
    except ValueError:
        print(s, '\n')
        raise
    ntk = nu_tokenize(l)
    ntkl = nu_detect_usable(ntk)
    get_info(s, l, ntkl, ntk)
    #print(*ntk, sep='\n')

if __name__=='__main__':
    import sys
    with open(sys.argv[1]) as f:
        shlex_test(f.read())
