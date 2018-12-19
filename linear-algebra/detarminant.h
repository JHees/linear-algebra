#pragma once

#include<iostream>
#include"fraction.h"
using namespace std;
class detarminant
{
public:	
	detarminant(unsigned int);
	~detarminant();

	detarminant& operator=(const fra*);//Please make sure the size of "fra" is big enough.
	detarminant& operator=(const detarminant);

	friend istream & operator>> (istream &in, detarminant&);
	friend ostream & operator<< (ostream &out, const detarminant&);

	fra calculate();

	void trans_row_intechng(unsigned int,unsigned int);
	void trans_col_intechng(unsigned int,unsigned int);//interchange
	void trans_row_adtimes(unsigned int, unsigned int, fra);//??????
	void trans_col_adtimes(unsigned int, unsigned int, fra);
	void trans_row_divide(unsigned int, fra);
	void trans_col_divide(unsigned int, fra);
	

private:	
	fra det_result;
	int det_size;
	fra **ip_root;

//------------mathe----------
	inline int factorial(int);
	bool inverse(unsigned int []);
	void sequence(unsigned int*);
};

//TODO 
//1.从程序输入行列式 done
//插，规范重载.....cin,cout  T.T
//模板
//2.程序隐蔽性and接口
//3.程序优化

