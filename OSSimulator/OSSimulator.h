#ifndef OSSIMULATOR_H
#define OSSIMULATOR_H 

#include "CPU.h"
#include "Memory.h"
#include "HandleFileException.h"
#include "IllegalAccessException.h"
#include "OutOfRangeException.h"
#include <fstream>
#include <string>

class OSSimulator
{
private:
	CPU cpu;
	int stack[SIZE_OF_MEMORY];
public:
	void parseFile(string fileName);
	void executeProgram();
};

#endif 