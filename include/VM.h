/*************************************************************************
	> File Name: VM.h
	> Author: 
	> Mail: 
	> Created Time: 六 10/ 8 13:34:56 2016
 ************************************************************************/

#ifndef _VM_H
#define _VM_H

class VM {
    public:
        VM();
        virtual ~VM();
        bool init();

    private:
    // memory
    int *text,
        *old_text,
        *stack;
    char *data;

    // registers
    int *pc, *sp, *bp;
    int ax;
};

#endif
