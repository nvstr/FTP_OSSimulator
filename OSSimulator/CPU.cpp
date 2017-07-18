#include "stdafx.h"
#include "CPU.h"

CPU::CPU(){
	isInterupted = false;
	timerLimit = getTimerLimit();
	timeCounter = 0;
	getInstructions();
}

CPU::~CPU(){

}

void CPU::runProgram(){
	//execute top instruction when there is one and has not finished:
	while (!IR.empty() && !isFinish){
		//not timer up: execute next instruction
		executeInstruction(IR.top());
	}
}

int CPU::getTimerLimit(){
	cout << "Please enter timer limit: " ;
	cin >> timerLimit;
}

void CPU::getInstructions(){
	//get instructions from memory:	
	int address = IR_START_ADDRESS;	
	while (memory.readAddr(address) != 0 && address <= IR_STOP_ADDRESS){
		IR.push(memory.readAddr(address));
		address++;
	}
}

bool CPU::isTimerUp(){	
	if (isInterupted) //do not interupt while processing another interupt
		return false;
	return timeCounter >= timerLimit;
}

void CPU::processTimerUpInterupt(){
	//execute instruction from mem[1000]
}

void CPU::executeInstruction(int instruction)
{
	//check timer up status:;
	if (isTimerUp())
		processTimerUpInterupt();	

	//not timer up or have done processing timer up: process top instruction.
	//first increase timer:
	timeCounter ++;
	//base on instruction code, specify function to be executed:
	switch (instruction){
		case LOAD_VALUE:
		case LOAD_ADDRESS:
			// function defines in FunctionDefine.h
			// 
			//
			//

		default:
			//function code not found: exception
	}
}

