#ifndef MEMORY_H
#define MEMORY_H  

#define SIZE_OF_MEMORY 2000

using namespace std;
class Memory
{
public:
	Memory();
	~Memory();
	int readAddr(int address);
	void writeAddr(int address, int data);
	void setMode(bool set);
	bool getMode();
private:
	int memory[SIZE_OF_MEMORY];
};
#endif 