//��һ���ַ����Ĵ�д��ĸ�ŵ��ַ����ĺ��棬�����ַ������λ�ò��䣬�Ҳ����������Ŀռ䡣
//stl 
#include<iostream>
#include<vector>
//#include<vector>
//#include<algorithm>
using namespace std;


//char* quick_sort_change(char *s, int len)  //�������򡣰��տ��ŵ�˼·��һ�ֵĿ������򡣿��������ʱ����Ҫ�ķ��ڻ��ֲ�����
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
		for (vector<char>::iterator ite = v.begin(); ite != v.end(); ite++)//��������ӡ
			cout << " " << *ite;
	
}
/*
void main()
{
	//��д
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
