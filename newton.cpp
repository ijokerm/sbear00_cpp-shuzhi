#include<iostream>
#include<string>
#include<cmath>
using namespace std;
double fd(double x)
{
	double c = (x*x*x) / 3 - x;
	double d = x*x - 1;
	return (c / d);
}

void newton(double x0, double e)
{
	double a = x0;
	double x = x0 - fd(x0);
	int i = 0;
	while (abs(x - a) > e)
	{
		cout << a << endl;
		a = x;
		i++;   //循环次数
		x = x - fd(x);
		if (i > 50)
		{
			cout << "迭代失败！" << endl;
			return;
		}
	}
	cout << "迭代次数为：" << i << endl;
}

int main_2()
{
	double x0, e;
	cout << "请输入x0的值：";
	cin >> x0;
	cout << "请输入容许误差：";
	cin >> e;
	newton(x0, e);
	return 0;
	system("pause");
}