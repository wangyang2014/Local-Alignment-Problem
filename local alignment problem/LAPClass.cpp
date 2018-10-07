#include"LAPClass.h"

LAPCLASS::LAPCLASS(const string compareString, const char spiltChar)
{
	int position = compareString.find(spiltChar);
	if(-1 == position)
	{
		this->compareStrA = compareString;
		this->compareStrB = compareString;
		this->initialization();
		return ;
	}
	this->compareStrA = compareString.substr(0,position-1);
	this->compareStrB = compareString.substr(position+1,compareString.size());
	this->initialization();
}

bool LAPCLASS::equalstr(char a,char b)
{
	if(a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void LAPCLASS::initialization()
{
	this->Row = this->compareStrA.size() + 1;
	this->Column = this->compareStrB.size() + 1;

	this->scorematrix = new int* [this->Row];
	for(int i=0;i<this->Row;i++)
	{
		scorematrix[i] = new int[this->Column];
		memset(scorematrix[i],0,sizeof(int)*this->Column);
	}
}

void LAPCLASS::getmatrix()
{
	int Row = this->Row;
	int Cloumn = this->Column;


	for(int i=1;i<Row;i++)
	{
		for(int j=1;j<Cloumn;j++)
		{
			int Similarityscore = 0,penaltyvalue = 0;
			if(this->equalstr(this->compareStrA[i-1],this->compareStrB[j-1]))
			{
				Similarityscore = this->scorematrix[i - 1][j - 1] + LAPCLASS::svalue;
			}
			else
			{
				Similarityscore = this->scorematrix[i-1][j-1] - LAPCLASS::svalue;
			}
			penaltyvalue = __max(this->scorematrix[i-1][j],this->scorematrix[i][j-1]) + LAPCLASS::pvalue;
			this->scorematrix[i][j] = __max(__max(Similarityscore,penaltyvalue),0);//max(Similarityscore,penaltyvalue)
		}
	}
}

void LAPCLASS::printfmatrix()
{
	int Row = this->Row;
	int Cloumn = this->Column;

	for(int i=0;i<Row;i++)
	{
		for(int j = 0;j<Column;j++)
		{
			cout<<this->scorematrix[i][j]<<"  ";
		}
		cout << endl;
	}
}

void LAPCLASS::Traceback(vector<point> &position)
{
	int size = position.size();
	point start = position[size - 1];


	if (this->scorematrix[start.x][start.y] == 0)
	{
		position.pop_back();
		return;
	}

	int diagonal = this->scorematrix[start.x][start.y] - this->scorematrix[start.x - 1][start.y - 1];
	if (((diagonal == LAPCLASS::svalue) && this->equalstr(this->compareStrA[start.x - 1], this->compareStrB[start.y - 1])) \
		||((diagonal != LAPCLASS::svalue) && !this->equalstr(this->compareStrA[start.x - 1], this->compareStrB[start.y - 1])))
	{
		position.push_back(point(start.x - 1, start.y - 1));
		this->Traceback(position);
		return;
	}

	int penalty = this->scorematrix[start.x][start.y] - this->scorematrix[start.x][start.y - 1];
	if (penalty == LAPCLASS::pvalue)
	{
		position.push_back(point(start.x, start.y - 1));
		this->Traceback(position);
		return;
	}
	else
	{
		position.push_back(point(start.x - 1, start.y));
		this->Traceback(position);
		return;
	}
}

string LAPCLASS::getLocalsequence()
{
	int maxbvalue = 0;
	int Row = this->Row;
	int Cloumn = this->Column;
	vector<point> position;

	for(int i=0;i<Row;i++)
	{
		for(int j = 0;j<Column;j++)
		{
			if(this->scorematrix[i][j] > maxbvalue)
			{
				maxbvalue = scorematrix[i][j];
				position.clear();
				position.push_back(point(i, j));
			}
		}
	}
	this->Traceback(position);

	point front = position[0];
	string cA = "", cB = "";
	cA = this->compareStrA[front.x - 1] + cA;
	cB = this->compareStrB[front.y - 1] + cB;

	for (int i = 1; i < position.size();i++)
	{
		point endposition = position[i];
		if (front.x == endposition.x)
		{
			cA = "_" + cA;
		}
		else
		{
			cA = this->compareStrA[endposition.x - 1] + cA;
		}

		if (front.y == endposition.y)
		{
			cB = "_" + cB;
		}
		else
		{
			cB = this->compareStrB[endposition.y - 1] + cB;
		}
		front = endposition;
	}
	cout << "The alignment result is:" << endl << cA << endl << cB << endl;
	return "value";
}

/*LAPCLASS::~LAPCLASS()
{
	for(int i=0;i<this->Row;i++)
	{
		delete[] this->scorematrix[i];
	}
	delete[] this->scorematrix;
	this->scorematrix = NULL;
}*/

void LAPCLASS::freememory()
{
	for(int i=0;i<this->Row;i++)
	{
		delete[] this->scorematrix[i];
	}
	delete[] this->scorematrix;
	this->scorematrix = NULL;
}