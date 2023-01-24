#pragma once
#include<stdint.h>
#include <stdlib.h>

#define MEMSIZE 1024

class Memory{
public:
    uint8_t* mem;
    //returns -1 if addr not valid
    int read(uint8_t, uint8_t*);
    int write(uint8_t, uint8_t);
    Memory();
    ~Memory();
};