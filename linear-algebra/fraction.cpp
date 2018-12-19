#include "pch.h"
#include"fraction.h"
#include<iostream>

using namespace std;



int fraction::com_factor(long int num1,long int num2)
 {
	num1 = num1 >= 0 ? num1 : -num1;
	num2 = num2 >= 0 ? num2 : -num2;
	if (num1*num2 == 0)
		return 1;									//attantion
	long int big = 0, small = 0;
	big = num1 > num2 ? num1 : num2;
	small = num1 > num2 ? num2 : num1;
	if (big%small == 0)
		return small;
	else
 		return com_factor(big%small, small);  //----TODO:turn it into while
}

void fraction::input(long int mol,long int den)
{
	if (den == 0)
		throw("denominator could not be 0.");
	int cfac = com_factor(mol, den);
	if (den < 0)
	{
		molecules = -mol / cfac;
		denominator = -den / cfac;
	}
	else
	{
		molecules = mol / cfac;
		denominator = den / cfac;
	}
}

bool operator==(fraction fra1, fraction fra2)
{
	if (fra1.molecules == fra2.molecules && fra1.denominator == fra2.denominator)
		return true;
	else
		return false;
}

bool operator>(fraction fra1, fraction fra2)
{
	if (float(fra1 - fra2) > 0)
		return true;
	else
		return false;
}

bool operator>=(fraction fra1, fraction fra2)
{
	if (float(fra1 - fra2) >= 0)
		return true;
	else
		return false;
}

bool operator<(fraction fra1, fraction fra2)
{
	if (float(fra1 - fra2) < 0)
		return true;
	else
		return false;
}

bool operator<=(fraction fra1, fraction fra2)
{
	if (float(fra1 - fra2) <= 0)
		return true;
	else
		return false;
}

istream & operator>>(istream & in, fraction& ip)
{
	string str;
	in >> str;
	str += '\0';
	unsigned short size = 0;
	unsigned short point_1 = 0, point_2 = 0;
	unsigned short slash = 0;
	for (;; size++)
		if (str[size] == '\0')
			break;
	size--;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '/')
			slash = i;
		if (str[i] == '.')
			if (slash == 0)
				point_1 = i;
			else
				point_2 = i;
	}
	//cout << point_1 << ' ' << point_2 << ' ' << slash << ' ' << size << endl;
	slash = slash == 0 ? size + 1 : slash;
	string s_num1(str, 0, slash >= size ? size + 1 : slash);
	string s_num2(str, slash >= size ? size + 1 : slash + 1);
	int num1 = 0, num2 = 0;
	float exp1 = 0, exp2 = 0;
	for (int fig1 = 0; fig1 < slash; fig1++)
	{
		exp1 *= 10;
		switch (s_num1[fig1])
		{
		case '9':num1 += (int)(9 * pow(10.0, double(slash - fig1 - (bool)point_1 - 1))); break;
		case '8':num1 += (int)(8 * pow(10.0, double(slash - fig1 - (bool)point_1 - 1))); break;
		case '7':num1 += (int)(7 * pow(10.0, double(slash - fig1 - (bool)point_1 - 1))); break;
		case '6':num1 += (int)(6 * pow(10.0, double(slash - fig1 - (bool)point_1 - 1))); break;
		case '5':num1 += (int)(5 * pow(10.0, double(slash - fig1 - (bool)point_1 - 1))); break;
		case '4':num1 += (int)(4 * pow(10.0, double(slash - fig1 - (bool)point_1 - 1))); break;
		case '3':num1 += (int)(3 * pow(10.0, double(slash - fig1 - (bool)point_1 - 1))); break;
		case '2':num1 += (int)(2 * pow(10.0, double(slash - fig1 - (bool)point_1 - 1))); break;
		case '1':num1 += (int)(1 * pow(10.0, double(slash - fig1 - (bool)point_1 - 1))); break;
		case'.':exp1 = 1; point_1 = 0; break;
		default:throw("Please chack what you have input as a fraction.");
		}
	}
	if (!exp1)
		exp1 = 1;
if (slash != size + 1)
	for (int fig2 = 0; fig2 < size - slash; fig2++)
	{
		exp2 *= 10.0;
		switch (s_num2[fig2])
		{
		case '9':num2 += (int)(9 * pow(10.0, double(size - slash - fig2 - (bool)point_2 - 1))); break;
		case '8':num2 += (int)(8 * pow(10.0, double(size - slash - fig2 - (bool)point_2 - 1))); break;
		case '7':num2 += (int)(7 * pow(10.0, double(size - slash - fig2 - (bool)point_2 - 1))); break;
		case '6':num2 += (int)(6 * pow(10.0, double(size - slash - fig2 - (bool)point_2 - 1))); break;
		case '5':num2 += (int)(5 * pow(10.0, double(size - slash - fig2 - (bool)point_2 - 1))); break;
		case '4':num2 += (int)(4 * pow(10.0, double(size - slash - fig2 - (bool)point_2 - 1))); break;
		case '3':num2 += (int)(3 * pow(10.0, double(size - slash - fig2 - (bool)point_2 - 1))); break;
		case '2':num2 += (int)(2 * pow(10.0, double(size - slash - fig2 - (bool)point_2 - 1))); break;
		case '1':num2 += (int)(1 * pow(10.0, double(size - slash - fig2 - (bool)point_2 - 1))); break;
		case'.':exp2 = 1; point_2 = 0; break;
		default:throw("Please chack what you have input as a fraction.");
		}
	}
	if (!exp2)
		exp2 = 1;
	//cout << s_num1 << ' ' << s_num2 << endl;
	//cout << num1 << "aaaa" << exp1<<endl;
	//cout << num2 << "bbbb" << exp2<<endl;
	if (slash != size + 1)
		ip = fraction(num1 / exp1, num2 / exp2);
	else
		ip = fraction((float)num1, (float)exp1);
	//cout << ip << endl;
	return in;
}

ostream & operator<< (ostream & out, const fraction& op)
{
	if (op.denominator == 1 || op.molecules == 0)
		out << op.molecules;
	else
		out << op.molecules << '/' << op.denominator;
	return out;
}

fraction fraction::operator+(const fraction& num)
{
	if (denominator == num.denominator)
		return fraction((float)(molecules + num.molecules), (float)denominator);
	else
		return fraction((float)(molecules * (int)num.denominator + num.molecules * (int)denominator), (float)(denominator * num.denominator));
}

fraction fraction::operator-(const fraction& num)
{
	if (denominator == num.denominator)
		return fraction((float)(molecules - num.molecules), (float)denominator);
	else
		return fraction((float)(molecules * (int)num.denominator - num.molecules * (int)denominator), (float)(denominator * num.denominator));

}

fraction fraction::operator*(const fraction& num)
{
	return fraction((float)(molecules*num.molecules), (float)(denominator*num.denominator));

}


fraction fraction::operator/(const fraction& num)
{
	return fraction(float(molecules * (int)num.denominator), (float)((int)denominator * num.molecules));
}

fraction& fraction::operator+=(const fraction& num)
{
	*this = *this + num;
	return *this;
}

fraction& fraction::operator-=(const fraction& num)
{
	*this = *this - num;
	return *this;
}

fraction& fraction::operator*=(const fraction& num)
{
	*this = *this*num;
	return *this;
}

fraction& fraction::operator/=(const fraction& num)
{
	*this = *this / num;
	return *this;
}
fraction& fraction::operator=(const fraction& inp)
{
	molecules = inp.molecules;
	denominator = inp.denominator;
	return *this;
}


fraction::operator int()
{
	return int(molecules) / int(denominator);
}

fraction::operator float()
{
	return float(molecules) / float(denominator);
}

fraction::fraction(float value = 0)
{
	//--------------Ñ­»·Ê¶±ð----

	//--------------still not begin to do
	float exp = 1;
	for (int i = 1; i < DBL_DIG; i++)
	{
		if (abs(value - (int)value) < float(0.1))
		{
			input((long int)value, (long int)exp);
			return;
		}
		value *= (float)10;
		exp *= (float)10;
	}
}

fraction::fraction(float mol, float den = 1)
{
	for (int i = 1; i < DBL_DIG; i++)
	{
		//cout << mol << ' ' << den << endl;
		//cout << mol / den << endl;
		//cout << (float)(int)mol / (float)(int)(den) << endl;
		if (mol/den - (float)(int)mol/(float)(int)(den) < float(0.1) && mol / den - (float)(int)mol / (float)(int)(den)>float(-0.1))
		{
			input((long int)mol, (long int)den);
			return;
		}
		mol *= (float)10;
		den *= (float)10;
	}
}

fraction::fraction()
{
	molecules = 0;
	denominator = 1;
}

fraction::~fraction()
{

}
