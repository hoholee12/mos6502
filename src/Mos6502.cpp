#include "Mos6502.h"

int Mos6502::fetch(){
    uint8_t bytesfetched = 0;
    


    pc += bytesfetched;
}

void Mos6502::LDA(){} //load a
void Mos6502::LDX(){}
void Mos6502::LDY(){}
void Mos6502::STA(){} //store a
void Mos6502::STX(){}
void Mos6502::STY(){}
void Mos6502::TAX(){} // mov a -> x
void Mos6502::TAY(){}
void Mos6502::TSX(){} // the s is sp
void Mos6502::TXA(){}
void Mos6502::TXS(){}
void Mos6502::TYA(){}
//stack
void Mos6502::PHA(){} //push a into stack
void Mos6502::PHP(){} //push sr into stack (with break flag set)
void Mos6502::PLA(){} //pull back to a
void Mos6502::PLP(){} //pull back to sr
//dec / inc
void Mos6502::DEC(){} //decrement stuff from memory
void Mos6502::DEX(){} //decrement x reg
void Mos6502::DEY(){}
void Mos6502::INC(){} //increment stuff from memory
void Mos6502::INX(){}
void Mos6502::INY(){}
//arith
void Mos6502::ADC(){} //add
void Mos6502::SBC(){} //subtract
//logics    (with A register.)
void Mos6502::AND(){}
void Mos6502::EOR(){} //XOR
void Mos6502::ORA(){} //OR
//shift
void Mos6502::ASL(){} //shift left (with zero bit on right)
void Mos6502::LSR(){} //shift right (with zero bit on left)
void Mos6502::ROL(){} //rotate left (with carry bit on right)
void Mos6502::ROR(){} //rotate right (with zero bit on left)
//flag
void Mos6502::CLC(){} //clear carry bit
void Mos6502::CLD(){} //clear decimal bit
void Mos6502::CLI(){} //clear interrupt disable
void Mos6502::CLV(){} //clear overflow bit
void Mos6502::SEC(){} //set carry bit
void Mos6502::SED(){} //set decimal bit
void Mos6502::SEI(){} //set interrupt disable
//compare
//
void Mos6502::CMP(){} //compare with a reg
void Mos6502::CPX(){} //compare with x reg
void Mos6502::CPY(){} //compare with y reg
//condition branch
void Mos6502::BCC(){} //branch on carry clear
void Mos6502::BCS(){} //branch on carry set
void Mos6502::BEQ(){} //branch on equal (zero set)
void Mos6502::BMI(){} //branch on minus (negative set)
void Mos6502::BNE(){} //branch on not equal (zero clear)
void Mos6502::BPL(){} //branch on plus (negative clear)
void Mos6502::BVC(){} //branch on overflow clear
void Mos6502::BVS(){} //branch on overflow set
//jmps / subroutines
void Mos6502::JMP(){}
void Mos6502::JSR(){} //jmp to subroutine
void Mos6502::RTS(){} //return from subroutine
//interrupt
void Mos6502::BRK(){}
void Mos6502::RTI(){} //return from interrupt

void Mos6502::BIT(){} //bit test
void Mos6502::NOP(){} // noop