//把一个字符串的大写字母放到字符串的后面，各个字符的相对位置不变，且不能申请额外的空间。
//stl 
#include<iostream>
#include<vector>
//#include<vector>
//#include<algorithm>
using namespace std;


//char* quick_sort_change(char *s, int len)  //部分排序。按照快排的思路。一轮的快速排序。快速排序的时间主要耗费在划分操作上
void quick_sort_change(vector<char> &v)

{
	char pivotvalue = 'Z'+1;
	cout << pivotvalue << endl;
	int high = v.size() - 1;
	int low = 0;
	while (low < high) {
		while (low < high && v[high] >pivotvalue) {
			high--;
		}
		v[low] = v[high];
		while (low < high && v[low] < pivotvalue) {
			low++;
		}
	}
		for (vector<char>::iterator ite = v.begin(); ite != v.end(); ite++)//做遍历打印
			cout << " " << *ite;
	
}
/*
void main()
{
	//大写
	vector<char>data;
	
	char c;
	while (!cin.eof()) 
	{
		cin >> c;
		data.push_back(c);
		//cout << data.size() << endl;
	}
	cout << "tuichu " << endl;
	//quick_sort_change(data);
}

*/

	/*
	while (scanf("%s", str) != EOF)
	{
		quick_sort_change(str, strlen(str));
		//printf("%s\n", str);
		*/
