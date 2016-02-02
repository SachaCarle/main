#!/usr/bin/env python3

import os, time, shutil, sys

failed = []

root = '.'

if len(sys.argv) > 1:
    root = sys.argv[1]

while True:
    for path, dirs, files in os.walk(root):
        for f in files:
            f = path + '/' + f
            if f in failed:
                continue
            if f.endswith('~') or f.endswith('.pyc') or f.endswith('#'):
                try:
                    os.remove(f)
                except Exception as e:
                    print('failed:', f)
                    print('\t%s' % e)
                    failed.append(f)
                else:
                    print('deleted:', f)
        for d in dirs:
            _d = d
            d = path + '/' + d
            if d in failed:
                continue
            if d == '__pycache__':
                try:
                    shutil.rmtree(d)
                except Exception as e:
                    print('failed:', d)
                    print('\t%s' % e)
                    failed.append(d)
                else:
                    print('deleted:', d)
    time.sleep(10)
