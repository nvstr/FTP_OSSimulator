#ifndef CPU_H
#define CPU_H  
#include "Memory.h"

#define TIMER_INTERRUPT_ADDR 1000
#define INT_INSTRUCTION_ADDR 1500
#define USER_STACK_TOP 1000
#define SYS_STACK_TOP 2000

using namespace std;
class CPU
{
public:
	CPU();
	~CPU();
	void fetchIntoIR();
	void loadVal();
	void loadAddr(int addr);
	void loadInd(int addr);
	void loadIdxX(int addrVal);
	void loadIdxY(int addrVal);
	void loadSpX();
	void storeAddr(int val);
	int getRand();
	void putPort(int option);
	void addX();
	void addY();
	void subX();
	void subY();
	void copyToX();
	void copyFromX();
	void copyToY();
	void copyFromY();
	void copyToSp();
	void copyFromSp();
	void jupmAddr(int addr);
	void jumpIfEqual(int addr);
	void jumpIfNotEqual(int addr);
	void callAddr(int addr);
	void ret();
	void incX();
	void incY();
	void push();
	void pop();
	void intMode(int option);
	void iret();
	void end();
private:
	int PC;
	int SP;
	int IR;
	int AC;
	int X;
	int Y;
	bool interrupt;
	bool isFinish;
	Memory memory;
};

#endif 