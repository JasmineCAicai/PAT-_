#include<iostream>
#include<cstdio>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
 
int main()
{
	map<string, vector<string> > ma;
	int N;
	cin >> N;
	getchar();//吸收换行符
	string ID, s; char c;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (!j)
				getline(cin, ID);
			else if(j!=3)
			{
				getline(cin, s);
				ma[s].push_back(ID);
			}
			else
			{
				do
				{
					cin >> s;
					ma[s].push_back(ID);
					c = getchar();
				} while (c != '\n');
				
			}
 
		}
	}
	int M;
	cin >> M;
	getchar();
	for (int i = 0; i < M; i++)
	{
		getline(cin, s);
		cout << s << endl;
		s.erase(0, 3);
		int size = ma[s].size();
		sort(ma[s].begin(), ma[s].end());
		if (size)
		{
			for (int j = 0; j < size; j++)
			{
				cout << ma[s][j] << endl;
			}
		}
		else
			cout << "Not Found" << endl;
	}
	return 0;
}
/*注意cin跟getline同时使用时要用getchar()吸收换行符*/
