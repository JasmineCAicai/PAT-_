#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPrime(int a)
{
	if (a < 2)
		return false;
	for (int i = 2; i <= sqrt(a); i++)
	{
		if (a%i == 0)
			return false;
	}
	return true;
}
int smallestPrimeSize(int a)
{
	while(!isPrime(a))
	{
		a++;
	}
	return a;
}
int main()
{
	int MSize, N;
	cin >> MSize >> N;
	int size = smallestPrimeSize(MSize);
	vector<bool> hashtable;
	for (int i = 0; i < size; i++)
	{
		hashtable.push_back(true);
	}
	int t;
	for (int i = 0; i < N; i++)
	{
		cin >> t;
		int temp = t%size;
		if (hashtable[temp])
		{
			hashtable[temp] = false;
			cout << temp;
			if (i != N - 1)
				cout << " ";
		}
		else
		{
			int j = (temp+1)%size, k = 1;//这里必须模size，假如说temp=size-1，不模的话，最后一个测试点过不去
			bool flag = false;
			while (j < size)
			{
				
				if (hashtable[j])
				{
					hashtable[j] = false;
					cout << j;
					if (i != N - 1)
						cout << " ";
					break;
				}
				else
				{
					k++;//直到平方探测长度到size-1还不能找到位置，之后就不必在探测了
					if (k == size)
					{
						flag = true;
						break;
					}
				}
				j =(temp + k*k)%size;
			}
			if (flag)
			{
				cout << "-";
				if (i != N - 1)
					cout << " ";
			}
			
		}
	}
    cout << endl;
	return 0;
}
