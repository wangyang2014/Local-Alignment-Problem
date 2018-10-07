#ifndef DEF_LAPCLASS 
#define DEF_LAPCLASS DEF_LAPCLASS 

#include<iostream>
#include<string>
#include<cmath>
#include<vector>
using namespace std;

typedef struct point
{
	int x;
	int y;
	point(int x, int y) :x(x), y(y) {};
};

class LAPCLASS
{
private:
	string compareStrA;
	string compareStrB;
	string localalignment;
	static const int svalue = 3;
	static const int pvalue = -2;
	int Row;
	int Column;
	int ** scorematrix;
	void initialization();
	bool equalstr(char a,char b);
public:
	LAPCLASS(string compareStrA, string compareStrB):compareStrA(compareStrA),compareStrB(compareStrB){this->initialization();};
	LAPCLASS(const string compareString, const char spiltChar = '\n');
	void getmatrix();
	void printfmatrix();
	void Traceback(vector<point> &position);
	string getLocalsequence();
	void freememory();
	//~LAPCLASS();
};
#endif