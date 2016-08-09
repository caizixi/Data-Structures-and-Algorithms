
#include "string.h"
#include "stdio.h"

#include<stdlib.h>

//c专家编程的一些test


//内存的位置，动态数组，其实就是预先分配了而已。。。
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
	
	int *d;  //只是必须先定义才能用而已。。。
	char input_1[10];
	int size_1;
	printf("enter size:");
	size_1 = atoi(fgets(input_1, 7, stdin));
	d = (int *)malloc(size_1);
	d[0] = 1;
	d[size_1 - 1] = 2;
	//printf("size_of_d=%d\n",  sizeof(*d));  
	//!!!!sizeof不能求得动态分配的内存的大小!!!!
	printf("d[%d]=%d\n",0, d[0]);
	printf("d[%d]=%d\n", size_1 - 1, d[size_1 - 1]);


	//储存地址
	int asd = 5;
	int sdf = 6;
	int zxc = 7;
	printf("index1=%d\n", &asd);
	printf("index2=%d\n", &sdf);
	printf("index3=%d\n", &zxc);
	//Debug模式下，在int变量的前后各增加了4个字节，用于存储调试信息
	//Release模式下，地址相差4个字节

}

//指针数组、数组指针
void test_pointer_array()
{
	char *a;
	a = "asdasgdfgd";
	printf(" a =  %s \n", a);


	//指针数组： int 一维
	int *p[4];
	int e[4] = { 1,2,3,4 };
	//初始化
	for (int i = 0; i < 4; i++)
	{
		p[i] = &e[i];
	}
	int lenp = sizeof(p) / sizeof(int);
	for (int i = 0; i < lenp; i++)
	{
		printf("p[%d]=%d,index=%d\n", i, *p[i], p[i]);
	}

	//指针数组： char 二维
	const int column_size = 2; 
	int row_size =50; //每行最长50
	char *pea[column_size];
	
	//初始化1:malloc一次性分配，通过循环给指针指派空间。
	
	//char *ptr;
	//ptr = (char *)malloc(row_size * column_size * sizeof(char));  //char:1 int:4
	//if (ptr == NULL)
	//	printf("error");
	//for (int i = 0; i < column_size; i++)
	//{
	//	pea[i] = ptr + row_size * i * sizeof(char);
	//}
	

	//初始化2:malloc单次分配，每个指针单独分配。 通过strcpy 赋值。
	for (int i = 0; i < column_size; i++)
	{		pea[i] = (char *)malloc(row_size);	
	}
	char my_string[] = "good good";
	//pea[j] = malloc(strlen(my_string) + 1);  //动态分配内存
	strcpy(pea[1], my_string); //拷贝
	
	//打印 地址
	printf("pea[0]=%d\n", pea[0]);printf("pea[1]=%d\n", pea[1]);
	
	//初始化3：共享字符串。不需要拷贝字符串。但是空间不连续（最合适的方式。共享地址。）
	pea[0] = &my_string[0];
	
	//打印 地址
	printf("pea[0]=%d\n", pea[0]);printf("pea[1]=%d\n", pea[1]);




//数组指针test 一维
	int(*b)[4];
	int c[4] = { 1,2,3,4 };
	b = &c;//初地址就行了
	int lenb = sizeof(c) / sizeof(int);
	printf("len=%d\n", lenb);
	printf("sizeof(*b)=%d\n", sizeof(*b));
	for (int i = 0; i < lenb; i++)

	{
		printf("b[%d]=%d\n", i, (*b)[i]);//  *b 指向一个16bit的数组，整体。(*b)[i] 
	}

//数组指针test 二维
	int(*x)[4];  //数组容量是固定的，如果想用大小可变的，可以用一个类似的数据结构，vector
	int d[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	x = d;//*x 对应的16位长的数组。。。对齐。 这里的赋值时
	printf("x_point_to=%d\n", x);
	printf("index_d=%d\n", &d);


	int lenx = sizeof(*x) / sizeof(int);  //如果是x，对应的是本身指针的长度
	int lend = sizeof(d); /// sizeof(int);
	printf("lenx=%d\n", lenx);  //很好地解释了*x 对应的16位长的数组。。。。
	printf("lend=%d\n", lend);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			//printf("x[%d][%d]=%d\n", i, j, *(x+1));   
			//C语言与C++语言规定，一个指针变量加/减一个整数是将该指针变量的原值（是一个地址）和它指向的变量所占用的内存单元字节数相加或相减。这样就保证了p+i指向p下面的第i个元素。
			printf("x[%d][%d]=%d\n", i, j, *(*(x + i) + j));
			// x[i][j]  或者   *(*(x+i)+j)  或者 (*x)[i*4+j]         
		}
	}

	

	

}