#include "pch.h"
#include "detarminant.h"
#include <iostream>

using namespace std;


detarminant::detarminant(unsigned int input_size = 0)//,int *data =NULL)
{
	det_result = 0;
	det_size = 0;
	if (input_size == 0)
	{
		cout << "You need to input the size of the detarminant" << endl;
		cin >> this->det_size;
	}
	else
		this->det_size = input_size;

	ip_root = new fra*[det_size];
	for (int i = 0; i < det_size; i++)
		ip_root[i] = new fra[det_size];
	for (int row = 0; row < det_size; row++)
		for (int column = 0; column < det_size; column++)
			ip_root[row][column] = 0;
}


detarminant::~detarminant()
{
	for (int i = 0; i < det_size; i++)
		delete[] this->ip_root[i];
	delete this->ip_root;
}

detarminant& detarminant::operator=(const fra *data)
{
	for (int row = 0; row < det_size; row++)
		for (int column = 0; column < det_size; column++)
			ip_root[row][column] = data[(row)*det_size + column];
	return *this;
}

detarminant& detarminant::operator=(const detarminant other)
{
	for (int row = 0; row < det_size; row++)
		for (int column = 0; column < det_size; column++)
			this->ip_root[row][column] = other.ip_root[row][column];
	return *this;
}
istream &operator>>(istream& in, detarminant& det)
{
	for (int row = 0; row < det.det_size; row++)
	{
		cout << "Please input " << row + 1 << " row element";
		for (int column = 0; column < det.det_size; column++)
			in >> det.ip_root[row][column];
	}
	return in;
}

ostream &operator<<(ostream& out, const detarminant& det)
{
	for (int row = 0; row < det.det_size; row++)
	{
		out << '|';
		for (int column = 0; column < det.det_size; column++)
			out << det.ip_root[row][column] << '\0';
		out << '\b' << '|' << endl;
	}
	return out;
}

fra detarminant::calculate()
{
	unsigned int *seq = new unsigned int[det_size];
	det_result = 0;
	fra data = 1;
	for (int i = 0; i < det_size; i++)
		seq[i] = i+1;
	for (int i = 0; i < factorial(det_size); i++)
	{
		sequence(seq);
		for (int row = 0; row < det_size; row++)
		{
			data *= ip_root[row][seq[row]-1];
#ifdef calculate_Testing
			cout <<'('<<row+1<<','<<seq[row]<<')'<< ip_root[row][seq[row] - 1] << ' ';
#endif
		}
		data *= inverse(seq)?1.0f:-1.0f;
#ifdef calculate_Testing
		cout << " : " << data<<endl;
#endif
		det_result += data;
		data = 1;
		//if(i==2500000)
		//{
		//	i=i;
		//}
	}
	delete[] seq;
	return det_result;
}

bool detarminant::inverse(unsigned int data[])
{
	int inv = 0;
	int *seq = new int[det_size];
	for (int i = 0; i < det_size; i++)
		seq[i] = data[i];
	for (int a = 0; a < det_size; a++)
	{
		for (int b = a+1; b < det_size; b++)
		{
			if (seq[a] > seq[b])
			{
				seq[a] += seq[b];
				seq[b] = seq[a] - seq[b];
				seq[a] -= seq[b];
				inv++;
			}
		}
	}
	delete[] seq;
	if (inv / 2 * 2 == inv)
		return 1;
	return 0;
}

void detarminant::sequence(unsigned int* seq)
{
	unsigned int chack = det_size-1;
	for (; chack > 0 ; chack--)
		if (seq[chack - 1] < seq[chack])
			break;
	if (chack != 0)
		chack--;
	if (seq[chack] == det_size)
		seq[chack] = 1;
	else
		seq[chack]++;
	for (int i = 0; i < (int)chack; i++)
	{
		if (seq[chack] == seq[i])
		{
			seq[chack]++;
			if (seq[chack] == det_size+1)
				seq[chack] = 1;
			i = -1;
		}
	}
	chack++;
	for (; (int)chack < det_size; chack++)
	{
		seq[chack] = 1;
		for (int i = 0; i < (int)chack; i++)
		{
			if (seq[chack] == seq[i])
			{
				seq[chack]++;
				if (seq[chack] == det_size + 1)
					seq[chack] = 1;
				i = -1;
			}
		}
	}
}

inline int detarminant::factorial(int num)
{
	if (num == 1 || num == 0)
		return 1;
	return num*factorial(num - 1);
}

void detarminant::trans_row_intechng(unsigned int r1,unsigned int r2)
{
	if (r1 == r2)
		return;
	for (int i = 0; i < det_size; i++)
	{
		ip_root[r1 - 1][i] += ip_root[r2 - 1][i];
		ip_root[r2 - 1][i] = ip_root[r1 - 1][i] - ip_root[r2 - 1][i];
		ip_root[r1 - 1][i] -= ip_root[r2 - 1][i];
	}
}

void detarminant::trans_col_intechng(unsigned int c1, unsigned int c2)
{
	if (c1 == c2)
		return;
	for (int i = 0; i < det_size; i++)
	{
		ip_root[i][c1 - 1] += ip_root[i][c2 - 1];
		ip_root[i][c2 - 1] = ip_root[i][c1 - 1] - ip_root[i][c2 - 1];
		ip_root[i][c1 - 1] -= ip_root[i][c2 - 1];
	}
}

void detarminant::trans_row_adtimes(unsigned int r1, unsigned int r2, fra times)
{
	if (r1 == r2)
		return;
	for (int i = 0; i < det_size; i++)
		ip_root[r1 - 1][i] += ip_root[r2 - 1][i]*times;
}

void detarminant::trans_col_adtimes(unsigned int c1, unsigned int c2, fra times)
{
	if (c1 == c2)
		return;
	for (int i = 0; i < det_size; i++)
		ip_root[i][c1 - 1] += ip_root[i][c2 - 1] * times;
}

void detarminant::trans_row_divide(unsigned int r, fra times)
{
	for (int i = 0; i < det_size; i++)
		ip_root[r-1][i] /= times;
}

void detarminant::trans_col_divide(unsigned int c, fra times)
{
	for (int i = 0; i < det_size; i++)
		ip_root[i][c-1] /= times;
}
