#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
 
const int N = 40010;
const int M = 26 * 26 * 26 * 10 + 1; //由姓名散列成的数字上界
vector<int> selectCourse[M];
 
//hash函数，将字符串name转换成数字 
int getID (char name[]) {
	int id = 0;
	for (int i = 0; i < 3; i++) {
		id = id * 26 + (name[i] - 'A');
	}
	id = id * 10 + (name[3] - '0');
	return id;
}

int main() {
	char name[5];
	int n, k;
    
	cin >> n >> k; //人数及课程数
    
	//对每门课程
	for (int i = 0; i < k; i++) {
		int course, x;
		cin >> course >> x; //输入课程编号与选课人数
        
		for (int j = 0; j < x; j++) {
			cin >> name;
			int id = getID(name); //将名字散列为一个整数作为编号
			selectCourse[id].push_back(course);
		}
	}
    
	//n个查询
	for (int i = 0; i < n; i++) {
		cin >> name;
		int id = getID(name); //获得学生编号
        
		sort(selectCourse[id].begin(), selectCourse[id].end()); //从小到大排序
        
		cout << name << " " << selectCourse[id].size(); //姓名、选课数
        
		for (int j = 0; j < selectCourse[id].size(); j++) {
			cout << " " << selectCourse[id][j];//选课编号
		}
		cout << endl;
	}
    
	return 0;
}
