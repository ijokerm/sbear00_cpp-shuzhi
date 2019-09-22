#include<iostream>
#include<cmath>
#include<String>
using namespace std;
#define tol -10   /*����*/
/*--------------------
*�����鼰һ�׵���
--------------------*/
double func1(double x, double y){
	return x*x -2 * x - y + 0.5;
}

double func2(double x, double y){
	return x*x + 4 * y*y - 4;
}

double func11(double x, double y){
	return 2 * x - 3;
}
double func21(double x, double y){
	return 2 * x + 8 * y;
}

int main_22(void){
	unsigned int c_times = 0;
	double r_x, r_y, p_x, p_y;
	double n_tol = 1;
	p_x = -1;
	p_y = 1;
	n_tol = pow((double)10, tol);  /*������*/

//	printf("%s\t%s\t%s\n", "��������", "X", "Y");
	cout << "��������"  << "X"<< ' ' << "Y" << endl;
	/*ţ�ٵ���*/
	for (c_times = 1; c_times < 1000; c_times++){
		r_x = p_x - func1(p_x, p_y) / func11(p_x, p_y);
		r_y = p_y - func2(p_x, p_y) / func21(p_x, p_y);
		//printf("%d\t%-.20lg\t%-.20lg\n", c_times, r_x, r_y);
		cout << c_times <<' '<< r_x <<' '<< r_y<<endl;
		if (((p_x - r_x)>0 ? p_x - r_x : r_x - p_x) < n_tol)
			break;
		p_x = r_x;
		p_y = r_y;

	}
	//printf("��������:%d\n", c_times - 1);
	cout << "��������" << c_times - 1<<endl;
	//printf("�������:\n");
	cout << "������⣺"<<endl;
	//printf("%.20lg\t%.20lg\n", r_x, r_y);
	cout << r_x << r_y<<endl;
	getchar();
	return 0;
}