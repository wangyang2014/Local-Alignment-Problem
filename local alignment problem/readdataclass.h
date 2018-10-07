#ifndef DEF_READDATACLASS
#define DEF_READDATACLASS DEF_READDATACLASS

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

class ReadData
{
private:
	string content;
	const char* filepath ;
public:
	ReadData(const char* filepath):filepath(filepath){};
	FILE* open();
	string getcontent();
};

#endif