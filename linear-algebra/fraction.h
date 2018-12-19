#pragma once

#include<iostream>
#include<string>
#include<cmath>
//#include<limits>
/*
only support int and float
float have only seven devimal places
*/
using namespace std;


class fraction
{
public:
	fraction operator+(const fraction&);
	fraction operator-(const fraction&);
	fraction operator*(const fraction&);
	fraction operator/(const fraction&);
	
	fraction& operator=(const fraction&);
	fraction& operator+=(const fraction&);
	fraction& operator-=(const fraction&);
	fraction& operator*=(const fraction&);
	fraction& operator/=(const fraction&);

	friend istream & operator>> (istream &in,fraction&);
	friend ostream & operator<< (ostream & out,const fraction&);
	friend bool operator==(fraction, fraction);
	friend bool operator>(fraction, fraction);
	friend bool operator>=(fraction, fraction);
	friend bool operator<(fraction, fraction);
	friend bool operator<=(fraction, fraction);

	operator int();
	operator float();

	fraction();
	fraction(float);// Should be think more about it
	fraction(float, float);
	~fraction();

private:
	void input(long int,long int);
	int molecules;
	unsigned int denominator;
	int com_factor(long int,long int);
};

typedef fraction fra;


//------------------TODO------------
//1.错误处理 ">>"
//2.优化
//3.233