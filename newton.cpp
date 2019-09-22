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
		i++;   //ѭ������
		x = x - fd(x);
		if (i > 50)
		{
			cout << "����ʧ�ܣ�" << endl;
			return;
		}
	}
	cout << "��������Ϊ��" << i << endl;
}

int main_2()
{
	double x0, e;
	cout << "������x0��ֵ��";
	cin >> x0;
	cout << "������������";
	cin >> e;
	newton(x0, e);
	return 0;
	system("pause");
}