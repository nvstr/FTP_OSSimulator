// OSSimulator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "OSSimulator.h"
#include "CPU.h"
#include "Memory.h"


int main(){
	//new CPU:	
	CPU* cpu = new CPU();
	cpu->runProgram();
	return 0;
}
