#include "stdafx.h"
#include "OSSimulator.h"
#include <string>
#include <iostream>

using namespace std;

void main(string args[])
{
	OSSimulator *os = new OSSimulator();
	os->parseFile("..\\OSSimulator\\File\\file1.txt");
}