#include "Memory.h"

Memory::Memory(){
    mem = (uint8_t*)calloc(MEMSIZE, sizeof(uint8_t));
}
Memory::~Memory(){
    free(mem);
}

int Memory::read(uint8_t addr, uint8_t* data){
    if(addr >= 0 && addr < MEMSIZE){
        *data = mem[addr];
        return 0;
    }
    else{
        return -1;
    }
}

int Memory::write(uint8_t addr, uint8_t data){
    if(addr >= 0 && addr < MEMSIZE){
        mem[addr] = data;
        return 0;
    }
    else{
        return -1;
    }
}