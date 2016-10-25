/*************************************************************************
	> File Name: mcc.cpp
	> Author: haishand
	> Mail: 
	> Created Time: 五 10/ 7 15:33:22 2016
 ************************************************************************/

#include <iostream>

#define MAX_POOL_SIZE 256*1025

char *src, *old_src;
char token;

// VM definition
// memory
int *text,
    *old_text,
    *stack;

char *data;

// registers
int *pc, *sp, *bp;
int ax;

// instructions
enum {
   IMM, LC, LI, SC, SI, PUSH, JMP, JZ, JNZ, CALL 
};

void next() {
    token = *src++;
}

void expression() {

}

void program() {
    next();
    while(token != 0) {
        printf("token is %c\n", token);
        next();
    }
}

int eval() {
    int op;
    while(true) {
        // use "if" to keep self-compile
        if(op == IMM) { ax = *pc++; }
        else if (op == LC) { ax = *(char *)ax; }
        else if (op == LI) { ax = *(int *)ax; }
        else if (op == SC) { ax = *(char *)sp++ = ax;}
        else if (op == SI) { ax = *(int *)sp++ = ax;}
        else if (op == PUSH) { *--sp = ax; }
        else if (op == JMP) { pc = (int *)*pc; }
        else if (op == JZ) { pc = ax ? pc + 1 : (int *)*pc; }
        else if (op == JNZ) { pc = ax ? (int *)*pc : pc + 1; }
        else if (op == CALL) { *--sp = (pc + 1); pc = (int *)*pc; }
    }
    return 0;
}

int main(int argc, char **argv)
{
    FILE *fp;
    int i;

    argv++;
    if ((fp = fopen(*argv, "rb")) == NULL) {
        printf("could not open(%s)\n", *argv);
        return -1;
    }
    
    if(!(src = old_src = (char *) malloc(MAX_POOL_SIZE))) {
        printf("could not malloc(%d) for source area\n", MAX_POOL_SIZE);
        return -1;
    }

    if((i = fread(src, 1, MAX_POOL_SIZE, fp)) < 0) {
        printf("read() return code(%d)\n", i);
        return -1;
    }
    
    src[i] = 0;
    old_src = src;

    fclose(fp);

    // allocate memeory for virtual machine
    if(!(text = old_text = (int *) malloc(MAX_POOL_SIZE))) {
        printf("could not malloc(%d) for text segment\n", MAX_POOL_SIZE);
        return false;
    }

    if(!(stack = (int *) malloc(MAX_POOL_SIZE))) {
        printf("could not malloc(%d) for stack segment\n", MAX_POOL_SIZE);
        return false;
    }

    if(!(data = (char *) malloc(MAX_POOL_SIZE))) {
        printf("could not malloc(%d) for data segment\n", MAX_POOL_SIZE);
        return false;
    }

    memset(text, 0, MAX_POOL_SIZE);
    memset(stack, 0, MAX_POOL_SIZE);
    memset(data, 0, MAX_POOL_SIZE);

    bp = sp = (int *)(stack + MAX_POOL_SIZE);
    ax = 0;

//    printf("%s", src);
    program();

    return eval();
}
