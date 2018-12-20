#include "pch.h"
#include "detarminant.h"
#include "fraction.h"
#include <iostream>
#include<iomanip>

using namespace std;


#define ep_det_size 3
#define ep_det_element -7,-2,1,2,-2,-2,-3,-6,-3





int main()
{
	int x = -10;

	for (; x < 10; x++)
	{
		fra f1[9] = { x - 3,2,4,-7,x + 5,10,3,-2,x - 3 };
		fra f2[9] = { x,0,2 * x + 1,-7,x + 5,3,3,-2,x };
		detarminant D1(3), D2(3);
		D1 = f1;
		D2 = f2;

		cout << x << ' ' << D2.calculate() << endl;// << D2 << endl;
		//cout << x << ' ' << D1.calculate() - D2.calculate()<<endl;
	}
	//detarminant D1 (ep_det_size);
	//fra data[ep_det_size*ep_det_size] = { ep_det_element };
	//D1 = data;
	//cout << D1 << '=' << D1.calculate()<<endl;
	//D1.trans_row_intechng(1, 3);
	//cout << D1 << '=' << D1.calculate()<<endl;
	//D1.trans_row_adtimes(3,1,-1);
	//cout << D1 << '=' << D1.calculate() << endl;
	//D1.trans_row_adtimes(3, 2, 2);
	//cout << D1 << '=' << D1.calculate()<<endl;
	//D1.trans_row_adtimes(2, 1,fra(2,3));
	//cout << D1 << '=' << D1.calculate() << endl;
	//cin>>D1;
	//cout << D1.calculate() << endl;

	//----------------------- fra testing 2-----
	//fra c(12345678,99999999);

	//cout << c << ' ' << setprecision(DBL_DIG+1)<<12345678.0/99999999;
	//cout << endl << DBL_DIG;

	//----------------------- fraction testing 1-------

	//fra a(1.0/2),b(2.0/3);      // attention
	//cout<<a<<' '<<b<<endl;
	//cout << float(a) << ' ' << float(b) << endl;
	//cout << a + b << endl;
	//cout <<a - b << endl;
	//cout << a * b << endl;
	//cout <<a / b << endl;
	//a += b;
	//cout << a << endl;

	//---------------
	//for (;;)
	//{
	//fra a;
	//cin >> a;
	//cout <<a<<endl;
	//}


	system("pause");
	return 0;
}

