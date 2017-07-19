#include "stdafx.h"
#include "CPU.h"

CPU::CPU(){
	this->timerLimit = getTimerLimit();
	this->timeCounter = 0;
	getInstructions();
	this->PC = 0;
	this->SP = 1000;
	this->AC = 0;
	this->X = 0;
	this->Y = 0;
	this->isInterupted = false;
	this->isFinish = false;
	this->numOfInstruction = 0;
	memory = new Memory();
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
	return timerLimit;
}

void CPU::getInstructions(){
	//get instructions from memory:	
	int address = IR_START_ADDRESS;	
	while (memory->readAddr(address) != 0 && address <= IR_STOP_ADDRESS){
		IR.push(memory->readAddr(address));
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
	//switch (instruction)
	//{
	//	case LOAD_VALUE:
	//	case LOAD_ADDRESS:
	//		// function defines in FunctionDefine.h
	//		// 
	//		//
	//		//

	//	default:
	//		//function code not found: exception
	//}
}
void CPU::setIR(stack<int> val)
{
	this->IR = val;
}
void CPU::loadVal(int val)
{
	this->AC = val;
	if (isInterupted == false)
	{
		this->numOfInstruction++;
	}
}
void CPU::loadAddr(int addr)
{
	this->AC = this->memory->readAddr(addr);
	if (isInterupted == false)
	{
		this->numOfInstruction++;
	}
}
void CPU::loadInd(int addr)
{
	int address = this->memory->readAddr(addr);
	this->AC = this->memory->readAddr(address);
	if (isInterupted == false)
	{
		this->numOfInstruction++;
	}
}
void CPU::loadIdxX(int addrVal)
{
	this->AC = this->memory->readAddr(this->X + addrVal);
	if (isInterupted == false)
	{
		this->numOfInstruction++;
	}
}
void CPU::loadIdxY(int addrVal)
{
	this->AC = this->memory->readAddr(this->Y + addrVal);
	if (isInterupted == false)
	{
		this->numOfInstruction++;
	}
}
void CPU::loadSpX()
{
	this->AC = this->memory->readAddr(this->SP + this->X);
	if (isInterupted == false)
	{
		this->numOfInstruction++;
	}
}
void CPU::storeAddr(int addr)
{
	this->memory->writeAddr(addr, this->AC);
	if (isInterupted == false)
	{
		this->numOfInstruction++;
	}
}
void CPU::getRand()
{
	int random = rand() % 100 + 1;
	AC = random;
	if (isInterupted == false)
	{
		this->numOfInstruction++;
	}
}
void CPU::putPort(int option)
{
	if (option == 1)
	{
		cout << this->AC;
		if (isInterupted == false)
		{
			this->numOfInstruction++;
		}
	}
	else if (option == 2)
	{
		cout << (char)this->AC;
		if (isInterupted == false)
		{
			this->numOfInstruction++;
		}
	}
	else
	{
		cout << "Error: Port = " << option;
		if (isInterupted == false)
		{
			this->numOfInstruction++;
		}
	}
}
void CPU::addX()
{
	this->AC = this->AC + this->X;
	if (isInterupted == false)
	{
		this->numOfInstruction++;
	}
}
void CPU::addY()
{
	this->AC = this->AC + this->Y;
	if (isInterupted == false)
	{
		this->numOfInstruction++;
	}
}
void CPU::subX()
{
	this->AC = this->AC - this->X;
	if (isInterupted == false)
	{
		this->numOfInstruction++;
	}
}
void CPU::subY()
{
	this->AC = this->AC - this->Y;
	if (isInterupted == false)
	{
		this->numOfInstruction++;
	}
}
void CPU::copyToX()
{
	this->X = this->AC;
	if (isInterupted == false)
	{
		this->numOfInstruction++;
	}
}
void CPU::copyFromX()
{
	this->AC = this->X;
	if (isInterupted == false)
	{
		this->numOfInstruction++;
	}
}
void CPU::copyToY()
{
	this->Y = this->AC;
	if (isInterupted == false)
	{
		this->numOfInstruction++;
	}
}
void CPU::copyFromY()
{
	this->AC = this->Y;
	if (isInterupted == false)
	{
		this->numOfInstruction++;
	}
}
void CPU::copyToSp()
{
	this->SP = this->AC;
	if (isInterupted == false)
	{
		this->numOfInstruction++;
	}
}
void CPU::copyFromSp()
{
	this->AC = this->SP;
	if (isInterupted == false)
	{
		this->numOfInstruction++;
	}
}
void CPU::jupmAddr(int addr)
{
	PC = addr;
	if (isInterupted == false)
	{
		this->numOfInstruction++;
	}
}
void CPU::jumpIfEqual(int addr)
{
	if (this->AC = 0)
	{
		PC = addr;
	}
	if (isInterupted == false)
	{
		this->numOfInstruction++;
	}
}
void CPU::jumpIfNotEqual(int addr)
{
	if (this->AC != 0)
	{
		PC = addr;
	}
	if (isInterupted == false)
	{
		this->numOfInstruction++;
	}
}
void CPU::callAddr(int addr)
{

}
void CPU::ret()
{

}
void CPU::incX()
{
	this->X++;
	if (isInterupted == false)
	{
		this->numOfInstruction++;
	}
}
void CPU::incY()
{
	this->X--;
	if (isInterupted == false)
	{
		this->numOfInstruction++;
	}
}
void CPU::push()
{

}
void CPU::pop()
{

}
void CPU::intMode(int option)
{

}
void CPU::iret()
{

}
void CPU::end()
{

}

