/*
 * File: 103-python.c
 * Auth: Type Your Name Here
 */

#include <Python.h>

void print_python_list(PyObject *o);
void print_python_bytes(PyObject *o);
void print_python_float(PyObject *o);

/**
 * print_python_list - Prints basic info about Python lists.
 * @o: A PyObject list object.
 */
void print_python_list(PyObject *o)
{
	Py_ssize_t size, alloc, p;
	const char *type;
	PyListObject *list = (PyListObject *)o;
	PyVarObject *var = (PyVarObject *)o;

	size = var->ob_size;
	alloc = list->allocated;

	fflush(stdout);

	printf("[*] Python list info\n");
	if (strcmp(p->ob_type->tp_name, "list") != 0)
	{
		printf("  [ERROR] Invalid List Object\n");
		return;
	}

	printf("[*] Size of the Python List = %ld\n", size);
	printf("[*] Allocated = %ld\n", alloc);

	for (p = 0; p < size; p++)
	{
		type = list->ob_item[p]->ob_type->tp_name;
		printf("Element %ld: %s\n", p, type);
		if (strcmp(type, "bytes") == 0)
			print_python_bytes(list->ob_item[p]);
		else if (strcmp(type, "float") == 0)
			print_python_float(list->ob_item[p]);
	}
}

/**
 * print_python_bytes - Prints basic info about Python byte objects.
 * @o: A PyObject byte object.
 */
void print_python_bytes(PyObject *o)
{
	Py_ssize_t size, p;
	PyBytesObject *bytes = (PyBytesObject *)o;

	fflush(stdout);

	printf("[.] bytes object info\n");
	if (strcmp(o->ob_type->tp_name, "bytes") != 0)
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}

	printf("  size: %ld\n", ((PyVarObject *)o)->ob_size);
	printf("  trying string: %s\n", bytes->ob_sval);

	if (((PyVarObject *)o)->ob_size >= 10)
		size = 10;
	else
		size = ((PyVarObject *)o)->ob_size + 1;

	printf("  first %ld bytes: ", size);
	for (p = 0; p < size; p++)
	{
		printf("%02hhx", bytes->ob_sval[p]);
		if (p == (size - 1))
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_python_float - Prints basic info about Python float objects.
 * @o: A PyObject float object.
 */
void print_python_float(PyObject *o)
{
	char *buffer = NULL;

	PyFloatObject *float_obj = (PyFloatObject *)o;

	fflush(stdout);

	printf("[.] float object info\n");
	if (strcmp(p->ob_type->tp_name, "float") != 0)
	{
		printf("  [ERROR] Invalid Float Object\n");
		return;
	}

	buffer = PyOS_double_to_string(float_obj->ob_fval, 'r', 0,
			Py_DTSF_ADD_DOT_0, NULL);
	printf("  value: %s\n", buffer);
	PyMem_Free(buffer);
}

