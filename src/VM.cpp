/*************************************************************************
	> File Name: VM.cpp
	> Author: 
	> Mail: 
	> Created Time: 日 10/ 9 10:09:50 2016
 ************************************************************************/
#include "../include/Defs.h"
#include "../include/VM.h"
#include <iostream>

VM::VM() {
    text = stack = NULL;
    data = NULL;
    bp = sp = NULL;
    ax = 0;
}

VM::~VM() {
    if(text != NULL) {
        free(text);
    }
    if(stack != NULL) {
        free(stack);
    }
    if(data != NULL) {
        free(data);
    }
}

bool VM::init() {
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

    return true;
}
