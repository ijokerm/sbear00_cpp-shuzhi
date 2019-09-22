#include <iostream>
#include <iomanip>  //������ͷ�ļ�
#include <stdlib.h>

using namespace std;

//�������ɵĽڵ������
double dataX[1000];
//������̱�
double differenceTable[100][100] = { 0 };
//��������
void loadData(int &count);
//������̱�
void calcTable(int count);
//������̱�
void print(int count);
//�����㷨������ţ�ٲ�ֵ
double NewtonDValue(double x, int count);

int main()
{
	int count = 0;
	double x;
	char ch = 'n';
	//system("color 0A");
	loadData(count);
	calcTable(count);
	print(count);
	while (ch != 'y')
	{
		cout << "������Ҫ�����ֵ��";
		cin >> x;
		cout << NewtonDValue(x, count) << endl;
		cout << "�Ƿ��������y�˳�:";
	    cin >> ch;
	}
	system("pause");
	return 0;
}
//��������
void loadData(int &count)
{
	double x, y;
	cout << "���������ڵ�ĸ�����";
	cin >> count;
	cout << "���������ڵ�ĺ������꣺";
	for (int i = 0; i<count; i++)
	{
		cin >> x >> y;
		dataX[i] = x;
		differenceTable[i][0] = y;
	}
}
//������̱�
void calcTable(int count)
{
	int dValue = 1;
	//i��ʾ��
	for (int i = 0; i<count; i++)
	{
		//j��ʾ��
	 	for (int j = i; j<count; j++)
		{
			double dQuotient = (differenceTable[j + 1][i] - differenceTable[j][i]) / (dataX[j + 1] - dataX[j + 1 - dValue]);
			differenceTable[j + 1][i + 1] = dQuotient;
		}
		dValue += 1;
	}
}
//������̱�
void print(int count)
{
	cout << "���̱�Ϊ��" << endl;
	for (int i = 0; i<count; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout.setf(ios::showpoint);
			cout << setprecision(6) << differenceTable[i][j] << " ";
		}
		cout << endl;
	}
}
//�����㷨������ţ�ٲ�ֵ
double NewtonDValue(double x, int count)
{
	double calcValue = 0, temp = 1;
	int j = 0;
	for (int i = 0; i<count; i++)
	{
		temp = 1;
		//����(X-X0)*(X-X1).....*(X-Xn-1)
		for (int j = 0; j<i; j++)
		{
			temp *= (x - dataX[j]);
		}
		//����f(X0,X1,....,Xn)*(X-X0)*(X-X1).....*(X-Xn-1)
		temp *= differenceTable[i][i];
		//����f(X0,X1,....,Xn)*(X-X0)*(X-X1).....*(X-Xn-1)�ĺ�
		calcValue += temp;
	}
	return calcValue;
}