// OSSimulator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "OSSimulator.h"
#include "CPU.h"
#include "Memory.h"
#include <stack>

using namespace std;

template<typename T, typename P>
T remove_if(T beg, T end, P pred)
{
    T dest = beg;
    for (T itr = beg;itr != end; ++itr)
        if (!pred(*itr))
            *(dest++) = *itr;
    return dest;
}

OSSimulator::OSSimulator()
{
	cpu = new CPU();
	cpu->runProgram();
}

// Parsing file to array int
void OSSimulator::parseFile(string fileName)
{
	ifstream fileInstruction;
	string data[200];
	int instruction[200];
	int count = 0;
	string line = "";
	bool isInComment = false;
	bool isEndLine = false;
	char c;
	fileInstruction.open(fileName);
	if (fileInstruction.fail()){
		throw HandleFileException();
	}
	else
	{
		while (!fileInstruction.eof())
		{
			c = fileInstruction.get();
			if (c == '\n') {
				data[count++] = line;
				line = "";
			}
			else {
				line.push_back(c);
			}
		}
		for (int i = 0; i < count; i++)
		{
			data[i].erase(remove_if(data[i].begin(), data[i].end(), isspace), data[i].end());
			for (int j = 0; j < data[i].length(); j++)
			{
				if (data[i][j] == '/' && data[i][j+1] == '/')
				{
					string tmp = data[i].substr(0, j);
					instruction[i] = stoi(tmp);
					break;
				}
				else
				{
					instruction[i] = stoi(data[i]);
				}
			}
		}
		// Instruction is array int to IR stack
		
	}

}

