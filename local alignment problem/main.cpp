#include"readdataclass.h"
#include"LAPClass.h"

void main()
{
	const char* filepath = "local-alignment.txt";
	ReadData readData = ReadData(filepath);
	string content = readData.getcontent();

	LAPCLASS lapclass = LAPCLASS(content);
	lapclass.getmatrix();
	lapclass.printfmatrix();
	lapclass.getLocalsequence();
	lapclass.freememory();
	getchar();
}