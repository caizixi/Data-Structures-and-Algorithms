
#include "string.h"
#include "stdio.h"

#include<stdlib.h>

//cר�ұ�̵�һЩtest


//�ڴ��λ�ã���̬���飬��ʵ����Ԥ�ȷ����˶��ѡ�����
void memory_test()
{
	/*
	char *dynamic;
	char input[10];
	int size;
	printf("enter size:");
	size = atoi(fgets(input, 7, stdin));
	dynamic = (char *)malloc(size);
	dynamic[0] = 'a';
	dynamic[size - 1] = 'z';
	*/
	
	int *d;  //ֻ�Ǳ����ȶ�������ö��ѡ�����
	char input_1[10];
	int size_1;
	printf("enter size:");
	size_1 = atoi(fgets(input_1, 7, stdin));
	d = (int *)malloc(size_1);
	d[0] = 1;
	d[size_1 - 1] = 2;
	//printf("size_of_d=%d\n",  sizeof(*d));  
	//!!!!sizeof������ö�̬������ڴ�Ĵ�С!!!!
	printf("d[%d]=%d\n",0, d[0]);
	printf("d[%d]=%d\n", size_1 - 1, d[size_1 - 1]);


	//�����ַ
	int asd = 5;
	int sdf = 6;
	int zxc = 7;
	printf("index1=%d\n", &asd);
	printf("index2=%d\n", &sdf);
	printf("index3=%d\n", &zxc);
	//Debugģʽ�£���int������ǰ���������4���ֽڣ����ڴ洢������Ϣ
	//Releaseģʽ�£���ַ���4���ֽ�

}

//ָ�����顢����ָ��
void test_pointer_array()
{
	char *a;
	a = "asdasgdfgd";
	printf(" a =  %s \n", a);


	//ָ�����飺 int һά
	int *p[4];
	int e[4] = { 1,2,3,4 };
	//��ʼ��
	for (int i = 0; i < 4; i++)
	{
		p[i] = &e[i];
	}
	int lenp = sizeof(p) / sizeof(int);
	for (int i = 0; i < lenp; i++)
	{
		printf("p[%d]=%d,index=%d\n", i, *p[i], p[i]);
	}

	//ָ�����飺 char ��ά
	const int column_size = 2; 
	int row_size =50; //ÿ���50
	char *pea[column_size];
	
	//��ʼ��1:mallocһ���Է��䣬ͨ��ѭ����ָ��ָ�ɿռ䡣
	
	//char *ptr;
	//ptr = (char *)malloc(row_size * column_size * sizeof(char));  //char:1 int:4
	//if (ptr == NULL)
	//	printf("error");
	//for (int i = 0; i < column_size; i++)
	//{
	//	pea[i] = ptr + row_size * i * sizeof(char);
	//}
	

	//��ʼ��2:malloc���η��䣬ÿ��ָ�뵥�����䡣 ͨ��strcpy ��ֵ��
	for (int i = 0; i < column_size; i++)
	{		pea[i] = (char *)malloc(row_size);	
	}
	char my_string[] = "good good";
	//pea[j] = malloc(strlen(my_string) + 1);  //��̬�����ڴ�
	strcpy(pea[1], my_string); //����
	
	//��ӡ ��ַ
	printf("pea[0]=%d\n", pea[0]);printf("pea[1]=%d\n", pea[1]);
	
	//��ʼ��3�������ַ���������Ҫ�����ַ��������ǿռ䲻����������ʵķ�ʽ�������ַ����
	pea[0] = &my_string[0];
	
	//��ӡ ��ַ
	printf("pea[0]=%d\n", pea[0]);printf("pea[1]=%d\n", pea[1]);




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

	

	

}