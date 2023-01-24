#include "Mos6502.h"

//argc argv is essential for SDL program!!!
int main(int argc, char** argv){
	Memory* mem = new Memory();
	Mos6502* cpu = new Mos6502(mem);
	
	return 0;
}
