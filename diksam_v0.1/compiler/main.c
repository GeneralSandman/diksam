#include <stdio.h>
#include <locale.h>
#include "DKC.h"
#include "DVM.h"
#include "MEM.h"

int main(int argc, char **argv) {
    DKC_Compiler *      compiler;
    FILE *              fp;
    DVM_Executable *    exe;
    DVM_VirtualMachine *dvm;

    if (argc < 2) {
        fprintf(stderr, "usage:%s filename arg1, arg2, ...", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "%s not found.\n", argv[1]);
        exit(1);
    }

    setlocale(LC_CTYPE, "");
    compiler = DKC_create_compiler();

    // 词法分析 语法分析 构建语法树 修正语法树 生成中间代码
    exe = DKC_compile(compiler, fp);

    //
    dvm = DVM_create_virtual_machine();
    DVM_add_executable(dvm, exe);

    // 执行中间代码
    DVM_execute(dvm);

    // 释放内存
    DKC_dispose_compiler(compiler);
    DVM_dispose_virtual_machine(dvm);

    MEM_check_all_blocks();
    MEM_dump_blocks(stdout);

    return 0;
}
