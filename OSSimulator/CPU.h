#ifndef CPU_H
#define CPU_H  
#include "Memory.h"
#include "stdafx.h"
#include "FunctionDefine.h"
#include <stack>
#include <iostream>
#define TIMER_INTERRUPT_ADDR 1000
#define INT_INSTRUCTION_ADDR 1500
#define USER_STACK_TOP 1000
#define SYS_STACK_TOP 2000
#define IR_START_ADDRESS 100
#define IR_STOP_ADDRESS 150
using namespace std;
class CPU
{
public:
	CPU();
	~CPU();
	void runProgram();
private:
	int timerLimit;
	int timeCounter;
	int PC;
	int SP;
	stack <int> IR;
	int AC;
	int X;
	int Y;
	bool isInterupted;	
	bool isFinish;
	Memory memory;

private:
	void executeInstruction(int instruction);
	int getTimerLimit();
	bool isTimerUp();
	void processTimerUpInterupt();
	void getInstructions();

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
};

#endif 