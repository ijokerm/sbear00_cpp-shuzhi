#include <iostream>
#include <iomanip>  //流控制头文件
#include <stdlib.h>

using namespace std;

//保存生成的节点横坐标
double dataX[1000];
//定义差商表
double differenceTable[100][100] = { 0 };
//加载数据
void loadData(int &count);
//计算差商表
void calcTable(int count);
//输出差商表
void print(int count);
//核心算法，计算牛顿插值
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
		cout << "请输入要计算的值：";
		cin >> x;
		cout << NewtonDValue(x, count) << endl;
		cout << "是否继续？按y退出:";
	    cin >> ch;
	}
	system("pause");
	return 0;
}
//加载数据
void loadData(int &count)
{
	double x, y;
	cout << "请输入插入节点的个数：";
	cin >> count;
	cout << "请输入插入节点的横纵坐标：";
	for (int i = 0; i<count; i++)
	{
		cin >> x >> y;
		dataX[i] = x;
		differenceTable[i][0] = y;
	}
}
//计算差商表
void calcTable(int count)
{
	int dValue = 1;
	//i表示列
	for (int i = 0; i<count; i++)
	{
		//j表示行
	 	for (int j = i; j<count; j++)
		{
			double dQuotient = (differenceTable[j + 1][i] - differenceTable[j][i]) / (dataX[j + 1] - dataX[j + 1 - dValue]);
			differenceTable[j + 1][i + 1] = dQuotient;
		}
		dValue += 1;
	}
}
//输出差商表
void print(int count)
{
	cout << "差商表为：" << endl;
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
//核心算法，计算牛顿插值
double NewtonDValue(double x, int count)
{
	double calcValue = 0, temp = 1;
	int j = 0;
	for (int i = 0; i<count; i++)
	{
		temp = 1;
		//计算(X-X0)*(X-X1).....*(X-Xn-1)
		for (int j = 0; j<i; j++)
		{
			temp *= (x - dataX[j]);
		}
		//计算f(X0,X1,....,Xn)*(X-X0)*(X-X1).....*(X-Xn-1)
		temp *= differenceTable[i][i];
		//计算f(X0,X1,....,Xn)*(X-X0)*(X-X1).....*(X-Xn-1)的和
		calcValue += temp;
	}
	return calcValue;
}