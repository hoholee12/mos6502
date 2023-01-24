#pragma once
#include<stdint.h>
#include "Memory.h"

/*
mos6502 disassembler
https://www.masswerk.at/6502/disassembler.html

mos6502 details
https://www.masswerk.at/6502/6502_instruction_set.html

*/

class Mos6502{
public:
    //registers
    uint16_t pc; //program counter
    uint8_t ac;
    uint8_t x;
    uint8_t y;
    uint8_t sp; //stack ptr

    uint8_t sr; //stats reg
    /*
    sr flags:
    bit7: negative
    bit6: overflow
    bit5: - 
    bit4: break
    bit3: decimal(bcd mode for adc/sbc)
    bit2: disable interrupts
    bit1: zero
    bit0: carry
    */
    Memory* mem;
    Mos6502(Memory* mem):mem(mem){}


    //fetch op
    uint32_t opcode;
    uint32_t operand;
    int fetch();    //return cycles

    //ops
    //transfers
    void LDA(); //load a
    void LDX();
    void LDY();
    void STA(); //store a
    void STX();
    void STY();
    void TAX(); // mov a -> x
    void TAY();
    void TSX(); // the s is sp
    void TXA();
    void TXS();
    void TYA();
    //stack
    void PHA(); //push a into stack
    void PHP(); //push sr into stack (with break flag set)
    void PLA(); //pull back to a
    void PLP(); //pull back to sr
    //dec / inc
    void DEC(); //decrement stuff from memory
    void DEX(); //decrement x reg
    void DEY();
    void INC(); //increment stuff from memory
    void INX();
    void INY();
    //arith
    void ADC(); //add
    void SBC(); //subtract
    //logics    (with A register.)
    void AND();
    void EOR(); //XOR
    void ORA(); //OR
    //shift
    void ASL(); //shift left (with zero bit on right)
    void LSR(); //shift right (with zero bit on left)
    void ROL(); //rotate left (with carry bit on right)
    void ROR(); //rotate right (with zero bit on left)
    //flag
    void CLC(); //clear carry bit
    void CLD(); //clear decimal bit
    void CLI(); //clear interrupt disable
    void CLV(); //clear overflow bit
    void SEC(); //set carry bit
    void SED(); //set decimal bit
    void SEI(); //set interrupt disable
    //compare
    //
    void CMP(); //compare with a reg
    void CPX(); //compare with x reg
    void CPY(); //compare with y reg
    //condition branch
    void BCC(); //branch on carry clear
    void BCS(); //branch on carry set
    void BEQ(); //branch on equal (zero set)
    void BMI(); //branch on minus (negative set)
    void BNE(); //branch on not equal (zero clear)
    void BPL(); //branch on plus (negative clear)
    void BVC(); //branch on overflow clear
    void BVS(); //branch on overflow set
    //jmps / subroutines
    void JMP();
    void JSR(); //jmp to subroutine
    void RTS(); //return from subroutine
    //interrupt
    void BRK();
    void RTI(); //return from interrupt

    void BIT(); //bit test
    void NOP(); // noop



};