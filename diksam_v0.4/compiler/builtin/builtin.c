#include <stdio.h>
#include "../diksamc.h"


char *st_diksam_lang_dkh_text[] = {
    "void print(string str);\n",
    "void println(string str) {\n",
    "    print(str + \"\\n\");\n",
    "}\n",
    "\n",
    "public class File {\n",
    "    native_pointer fp;\n",
    "    constructor initialize(native_pointer fp) {\n",
    "\tthis.fp = fp;\n",
    "    }\n",
    "}\n",
    "\n",
    "File fopen(string file_name, string mode);\n",
    "string fgets(File file);\n",
    "void fputs(string str, File file);\n",
    "void fclose(File file);\n",
    "\n",
    "double to_double(int int_value) {\n",
    "    return int_value;\n",
    "}\n",
    "\n",
    "int to_int(double double_value) {\n",
    "    return double_value;\n",
    "}\n",
    "\n",
    "int parse_int(string str) throws NumberFormatException;\n",
    "double parse_double(string str) throws NumberFormatException;\n",
    "\n",
    "void exit(int status);\n",
    "void randomize();\n",
    "int random(int range);\n",
    "\n",
    "class StackTrace {\n",
    "    int\tline_number;\n",
    "    string file_name;\n",
    "    string function_name;\n",
    "}\n",
    "\n",
    "abstract public class Exception {\n",
    "    public string message;\n",
    "    public StackTrace[] stack_trace;\n",
    "    public void print_stack_trace() {\n",
    "\tint i;\n",
    "\tprintln(\"Exception occured. \" + this.message);\n",
    "\tfor (i = 0; i < this.stack_trace.size(); i++) {\n",
    "\t    println(\"\\tat \" \n",
    "\t\t    + this.stack_trace[i].function_name\n",
    "\t\t    + \"(\" + this.stack_trace[i].file_name\n",
    "\t\t    + \":\" + this.stack_trace[i].line_number + \")\");\n",
    "\t}\n",
    "    }\n",
    "    public virtual constructor initialize() {\n",
    "\tthis.stack_trace = new StackTrace[0];\n",
    "    }\n",
    "}\n",
    "\n",
    "abstract public class BugException : Exception {\n",
    "}\n",
    "\n",
    "abstract public class RuntimeException : Exception {\n",
    "}\n",
    "\n",
    "public class NullPointerException : BugException {\n",
    "}\n",
    "\n",
    "public class ArrayIndexOutOfBoundsException : BugException {\n",
    "}\n",
    "\n",
    "public class StringIndexOutOfBoundsException : BugException {\n",
    "}\n",
    "\n",
    "public class DivisionByZeroException : RuntimeException {\n",
    "}\n",
    "\n",
    "public class MultibyteCharacterConvertionException : RuntimeException {\n",
    "}\n",
    "\n",
    "public class ClassCastException : BugException {\n",
    "}\n",
    "\n",
    "public abstract class ApplicationException : Exception {\n",
    "}\n",
    "\n",
    "public class NumberFormatException : ApplicationException {\n",
    "}\n",
    "\n",
    "delegate int HogeDelegate(int value);\n",
    "\n",
    "// BUGBUG for test routine\n",
    "void test_native(HogeDelegate dele);\n",
    "\n",
    "void foo_file(File file) {\n",
    "}\n",
    NULL
};
char *st_diksam_lang_dkm_text[] = {
    "require diksam.lang;\n",
    "\n",
    "native_pointer __fopen(string file_name, string mode);\n",
    "string __fgets(native_pointer fp);\n",
    "void __fputs(string str, native_pointer fp);\n",
    "void __fclose(native_pointer fp);\n",
    "\n",
    "File fopen(string file_name, string mode) {\n",
    "    native_pointer fp = __fopen(file_name, mode);\n",
    "    if (fp == null) {\n",
    "\treturn null;\n",
    "    } else {\n",
    "\treturn new File(fp);\n",
    "    }\n",
    "}\n",
    "\n",
    "string fgets(File file) {\n",
    "    return __fgets(file.fp);\n",
    "}\n",
    "\n",
    "void fputs(string str, File file) {\n",
    "    __fputs(str, file.fp);\n",
    "}\n",
    "\n",
    "void fclose(File file) {\n",
    "    __fclose(file.fp);\n",
    "}\n",
    NULL
};
char *st_diksam_math_dkh_text[] = {
    "double fabs(double z);\n",
    "double pow(double z, double x);\n",
    "double fmod(double number, double divisor);\n",
    "double ceil(double z);\n",
    "double floor(double z);\n",
    "double sqrt(double z);\n",
    "double exp(double z);\n",
    "double log10(double z);\n",
    "double log(double z);\n",
    "double sin(double radian);\n",
    "double cos(double radian);\n",
    "double tan(double radian);\n",
    "double asin(double arg);\n",
    "double acos(double arg);\n",
    "double atan(double arg);\n",
    "double atan2(double num, double den);\n",
    "double sinh(double value);\n",
    "double cosh(double value);\n",
    "double tanh(double value);\n",
    NULL
};

BuiltinScript dkc_builtin_script[] = {
    {"diksam.lang", DKH_SOURCE, st_diksam_lang_dkh_text},
    {"diksam.lang", DKM_SOURCE, st_diksam_lang_dkm_text},
    {"diksam.math", DKH_SOURCE, st_diksam_math_dkh_text},
    {NULL, DKM_SOURCE, NULL}
};
