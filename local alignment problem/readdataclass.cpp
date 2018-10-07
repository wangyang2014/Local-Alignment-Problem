#include"readdataclass.h"

FILE* ReadData::open()
{
	FILE* ftp;
	fopen_s(&ftp,this->filepath, "rb");
	if (NULL == ftp)
	{
		cout<<"the open file fail,plaese confirm that the file exists"<<endl;
		return NULL;
	}
	return ftp;
}

string ReadData::getcontent()
{
	FILE* ftp = this->open();
	if(NULL == ftp)
	{
		exit(0);
	}

	fseek(ftp,0,SEEK_END);
	int size = ftell(ftp);
	fseek(ftp,0,SEEK_SET);

	char *data = new char[size +1] ;
	if(NULL == data)
	{
		fclose(ftp);
		cout<<"memery full ,please close something computering software"<<endl;
		exit(0);
	}
	memset(data,0,size+1);
	fread(data,1,size,ftp);
	
	this->content = string(data);
	fclose(ftp);
	ftp = NULL;
	delete[] data;
	data = NULL;
	return this->content;
}