#include <iostream>
#include <vector>
using namespace std;

vector<int> sum, ans;
void func(int i, int& j);
int N, M;

int main()
{
    int i, j, min;
    cin >> N >> M;
    sum.resize(N + 1);
    for (i = 1; i <= N; i++)
    {
        cin >> sum[i];
        sum[i] += sum[i - 1];
    }
    int minSum = sum[N];
    for (i = 1; i <= N; i++)
    {
        func(i, j);
        int tempSum = sum[j] - sum[i - 1];
        if (tempSum > minSum) continue;
        if (tempSum >= M)
        {
            if (tempSum < minSum)
            {
                ans.clear();
                minSum = tempSum;
            }
            ans.push_back(i);
            ans.push_back(j);
        }
    }
    for (i = 0; i < ans.size(); i += 2)
        cout << ans[i] << "-" << ans[i + 1] << endl;
    return 0;
}

void func(int i, int& j)
{
    int begin = i, end = N;
    while (begin < end)
    {
        int mid = (begin + end) / 2;
        if (sum[mid] - sum[i - 1] >= M)
            end = mid;
        else
            begin = mid + 1;
    }
    j = end;
}
