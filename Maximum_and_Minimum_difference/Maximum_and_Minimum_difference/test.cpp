
#include "string.h"
#include "stdio.h"

#include<stdlib.h>
void test_pointer_array()
{
	char *a;
	a = "asdasgdfgd";
	printf(" a =  %s \n", a);


	//ָ������test
	int *p[4];
	int e[4] = { 1,2,3,4 };
	for (int i = 0; i < 4; i++)
	{
		p[i] = &e[i];
	}
	int lenp = sizeof(p) / sizeof(int);
	for (int i = 0; i < lenp; i++)
	{
		printf("p[%d]=%d\n", i, *p[i]);
	}



	//����ָ��test һά
	int(*b)[4];
	int c[4] = { 1,2,3,4 };
	b = &c;//����ַ������
	int lenb = sizeof(c) / sizeof(int);
	printf("len=%d\n", lenb);
	printf("sizeof(*b)=%d\n", sizeof(*b));
	for (int i = 0; i < lenb; i++)

	{
		printf("b[%d]=%d\n", i, (*b)[i]);//  *b ָ��һ��16bit�����飬���塣(*b)[i] 
	}

	//����ָ��test ��ά
	int(*x)[4];  //���������ǹ̶��ģ�������ô�С�ɱ�ģ�������һ�����Ƶ����ݽṹ��vector
	int d[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	x = d;//*x ��Ӧ��16λ�������顣�������롣 ����ĸ�ֵʱ
	printf("x_point_to=%d\n", x);
	printf("index_d=%d\n", &d);


	int lenx = sizeof(*x) / sizeof(int);  //�����x����Ӧ���Ǳ���ָ��ĳ���
	int lend = sizeof(d); /// sizeof(int);
	printf("lenx=%d\n", lenx);  //�ܺõؽ�����*x ��Ӧ��16λ�������顣������
	printf("lend=%d\n", lend);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			//printf("x[%d][%d]=%d\n", i, j, *(x+1));   
			//C������C++���Թ涨��һ��ָ�������/��һ�������ǽ���ָ�������ԭֵ����һ����ַ������ָ��ı�����ռ�õ��ڴ浥Ԫ�ֽ�����ӻ�����������ͱ�֤��p+iָ��p����ĵ�i��Ԫ�ء�
			printf("x[%d][%d]=%d\n", i, j, *(*(x + i) + j));
			// x[i][j]  ����   *(*(x+i)+j)  ���� (*x)[i*4+j]         
		}
	}

	
		//�����ַ
		int asd = 5;
		int sdf = 6;
		int zxc = 7;
		printf("index1=%d\n", &asd);
		printf("index2=%d\n", &sdf);
		printf("index3=%d\n", &zxc);
		//Debugģʽ�£���int������ǰ���������4���ֽڣ����ڴ洢������Ϣ
		//Releaseģʽ�£���ַ���4���ֽ�
	
	system("pause");
}