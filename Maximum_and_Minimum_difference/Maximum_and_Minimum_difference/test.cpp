
#include "string.h"
#include "stdio.h"

#include<stdlib.h>
void test_pointer_array()
{
	char *a;
	a = "asdasgdfgd";
	printf(" a =  %s \n", a);


	//指针数组test
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

	
		//储存地址
		int asd = 5;
		int sdf = 6;
		int zxc = 7;
		printf("index1=%d\n", &asd);
		printf("index2=%d\n", &sdf);
		printf("index3=%d\n", &zxc);
		//Debug模式下，在int变量的前后各增加了4个字节，用于存储调试信息
		//Release模式下，地址相差4个字节
	
	system("pause");
}