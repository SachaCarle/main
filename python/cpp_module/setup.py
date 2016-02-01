#!/usr/bin/env python3
from distutils.core import setup, Extension

module_test = Extension('test',
                        sources = ['testmodule.cpp'],
                        include_dirs = [],
                        libraries = [],
                        library_dirs = [],
                        define_macros = [('MACRO_TEST_A', 'A'),
                                         ('MACRO_TEST_B', 'B')]
                    )

setup(name = 'test',
      version = '1.0',
      description = 'etst module for python in cpp',
      ext_modules = [module_test]
  )
