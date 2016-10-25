/*************************************************************************
	> File Name: main.cpp
	> Author: haishand
	> Mail: 
	> Created Time: 五 10/ 7 15:33:22 2016
 ************************************************************************/

#include <iostream>
#include "../include/Defs.h"
#include "../include/VM.h"

char *src, *old_src;
char token;

VM vm;

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
    return 0;
}

/*
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

    if(!vm.init()) {
        printf("VM init failure\n");
        return -1;
    }

//    printf("%s", src);
    program();

    return eval();
}
*/
