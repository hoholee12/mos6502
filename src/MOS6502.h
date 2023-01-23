#pragma once

/*
mos6502 disassembler
https://www.masswerk.at/6502/disassembler.html

mos6502 details
https://www.masswerk.at/6502/6502_instruction_set.html

*/

class mos6502{
public:
    //registers
    uint16_t pc; //program counter
    uint8_t ac;
    uint8_t x;
    uint8_t y;
    uint8_t sr; //stats reg
    uint8_t sp; //stack ptr
    /*
    sr flags:
    bit7: negative
    bit6: overflow
    bit5: - 
    bit4: break
    bit3: decimal(bcd mode for adc/sbc)
    bit2: interrupt(block interrupts)
    bit1: zero
    bit0: carry



    */

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
    




}