#!/usr/bin/env python3

#-CORE---------------------------------------------------------------#
from Core import *

Builtins.registerState('BUILD_TIME')

for s in ('engine', 'data', 'world', 'loop', 'core'):
    BuildTime(s)

Builtins.BUILD_TIME = 'core'

Builtins.print = Builtins.newIO()
Builtins.daemon = Builtins.newIO(onArgvPrint('daemon'))
#-END-CORE-----------------------------------------------------------#

#-ENGINE-------------------------------------------------------------#
Builtins.BUILD_TIME = 'engine'
import Engine
#-END-ENGINE---------------------------------------------------------#



#-DATA---------------------------------------------------------------#
Builtins.BUILD_TIME = 'data'
import Data
resolveBuildData()
#-END-DATA-----------------------------------------------------------#



#-WORLD--------------------------------------------------------------#
Builtins.BUILD_TIME = 'world'
import World
#-END-WORLD----------------------------------------------------------#



#-LOOP---------------------------------------------------------------#
Builtins.BUILD_TIME = 'loop'
#-END-LOOP-----------------------------------------------------------#



#-END----------------------------------------------------------------#
del Builtins.BUILD_TIME
