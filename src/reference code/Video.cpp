#include"Video.h"

void Video::init(const char* str, defaults* mainwindow, Status* imstat, int queue_offset){
	this->offset_limit = queue_offset;

	//clear videobuffer(also does fbuffer)
	clearVBuffer();

	mainwindow->videoInit(str, SCREEN_WIDTH, SCREEN_HEIGHT, SCALE, imstat);

	draw(mainwindow);

}

//real final draw
void Video::draw(defaults* mainwindow){

	int scan = 0;

	mainwindow->drawVideo(frameBuffer);


}


//also does fbuffer
void Video::clearVBuffer(){
	for(int i = 0; i < (SCREEN_WIDTH * SCREEN_HEIGHT); i++) videoBuffer[i] = 0;
	copyToFbuffer();
	overwriteHint = false;
	offset_count = 0;
	offset_limit = QUEUE_OFFSET; //how much loops to ignore before flush, disable deflicker if -1
	copyFlag = false; //signal to copy to fbuffer
	queuePointer = 0;	//first
	prevOp = 0;
}

void Video::copySprite(CPU* cpu, Memory* memory, Video* video){
	//?x??
	uint8_t *vx = cpu->getV((cpu->currentOpcode & 0x0f00) >> 8);
	
	//??y?
	uint8_t *vy = cpu->getV((cpu->currentOpcode & 0x00f0) >> 4);

	//vf
	uint8_t *vf = cpu->getV(0xf);

	//??nn
	uint8_t n = cpu->currentOpcode & 0x000f;
	*vf = 0x0; //default

	//index register
	uint16_t indexReg = *cpu->getIndexRegister();

	uint8_t wrapX = *vx;// % SCREEN_WIDTH;
	uint8_t wrapY = *vy;// % SCREEN_HEIGHT;

	//draw to fbuffer before jmp
	bool temp = video->prevOverwriteHint();
#ifdef DEBUG_ME
	if (temp) printf("overwrite hint!!!!\n");
#endif
	pre_optimizations(new QueueType{ cpu->currentOpcode, cpu->prevJmpHint(), temp });


	for (int y = 0; y < n; y++){
		for (int x = 0; x < 8; x++){
			int check1 = SCREEN_WIDTH * (wrapY + y) + (wrapX + x);
			uint8_t check2 = memory->read(*cpu->getIndexRegister() + y) << x;
			check2 >>= 7;
			//printf("%d ", check2);
			if ((videoBuffer[check1] & check2) != 0){ 
				overwriteHint = true;
				*vf = 0x1;
			}
			videoBuffer[check1] ^= check2;
		}
		//printf("\n");
	}

	post_optimizations();
#ifdef DEBUG_ME
	printf("indexReg = %x, x = %x, y = %x, f = %x, n = %x\n", *cpu->getIndexRegister(), *vx, *vy, *vf, n);
#endif
}

