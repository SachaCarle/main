//
// testmodule.cpp for python module creation in cpp in /home/carle_s/main/python/cpp_module
// 
// Made by Sacha Carle
// Login   <carle_s@epitech.net>
// 
// Started on  Mon Feb  1 14:46:07 2016 Sacha Carle
// Last update Mon Feb  1 17:11:47 2016 Sacha Carle
//

#include "Python.h"

static PyObject * test_CALL(PyObject *self, PyObject *args)
{
  const char *txt;

  if (!PyArg_ParseTuple(args, "s", &txt))
    return NULL;
  printf("test(): %s\n", txt);
  return Py_None;
}

static PyObject * test_func(PyObject *self, PyObject *args)
{
  const char *txt;

  if (!PyArg_ParseTuple(args, "s", &txt))
    return NULL;
  printf("test_func: %s\n", txt);
  return Py_None;
}

static PyMethodDef testmethods[] = {
  {"__call__", test_CALL, METH_VARARGS, NULL},
  {"func", test_func, METH_VARARGS, NULL},
  {NULL, NULL, 0, NULL},
};

static struct PyModuleDef testmodule = {
  PyModuleDef_HEAD_INIT,
  "test",
  NULL,
  -1,
  testmethods,
};

static PyObject * TestError;

PyMODINIT_FUNC
PyInit_test(void)
{
  PyObject *m;

  m = PyModule_Create(&testmodule);
  if (m == NULL) return NULL;
  TestError = PyErr_NewException("test.error", NULL, NULL);
  Py_INCREF(TestError);
  PyModule_AddObject(m, "error", TestError);
  return m;
}
