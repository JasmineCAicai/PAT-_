#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<set>
#include<algorithm>

using namespace std;

int main(){
	string a;
	cin>>a;
	int sum=0;
	int i=0;
	while(a[i]!='\0')
	{
        sum+=a[i]-'0';
        i++;
    }
	int temp;
	vector <int> v;
	do
	{
		temp = sum % 10;
		sum = sum/10;
		v.push_back(temp);
	}while(sum);//避免0的问题 
	for(int i=0;i<v.size();i++){
		switch(v[v.size()-i-1]){
			case 0:cout << "zero"; break;
            case 1:cout << "one"; break;
            case 2:cout << "two"; break;
            case 3:cout << "three"; break;
            case 4:cout << "four"; break;
            case 5:cout << "five"; break;
            case 6:cout << "six"; break;
            case 7:cout << "seven"; break;
            case 8:cout << "eight"; break;
            case 9:cout << "nine"; break;
            default:
                break;
		}
		if(i!=v.size()-1){
			cout<<" ";
			//if i=v.size()-1  那么就说明所有数字已经录入完毕 
		}		 
	}
}
