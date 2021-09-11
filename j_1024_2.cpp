#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

bool checkPalindromic(deque<char> dq) {
	int i = 0, j = dq.size() - 1;
	while (i <= j) {
		if (dq[i] != dq[j]) return false;
		i++; 
        j--;
	}
	return true;
}

int main() {
	char N[20];
	int K;
    
	cin >> N >> K;
    
	int len = strlen(N);
	deque<char> dq, dq1, dq2;
    
	for (int i = 0; i < len; i++) {
        dq.push_back(N[i]);
	}
    
	dq1 = dq2 = dq;
    
	reverse(dq2.begin(), dq2.end());
    
	int i = 1;
	int t, carry = 0;
    
	if (checkPalindromic(dq)) {
		for (int i = 0; i < dq.size(); i++) {
			cout << dq[dq.size() - 1 - i];
		}
        cout << endl;
		cout << 0 << endl;
		return 0;
	}//若本身就是回文数，则不需进行计算了
    
	while (i <= K) {
		for (int j = 0; j < dq.size(); j++) {
			t = dq1[j] - '0' + dq2[j] - '0' + carry;
			carry = 0;
			if (t >= 10) {
				dq[j] = '0' + t - 10;
				carry = 1;
			}
			else
				dq[j] = '0' + t;
		}
        
		if (carry) {
			dq.push_back('1');
			carry = 0;
		}
        
		if (checkPalindromic(dq)) {
            break;
		}
		else {
			dq1 = dq2 = dq;
			reverse(dq2.begin(), dq2.end());
			i++;
		}
	}
    
	if (i > K) {
		for (int i = 0; i < dq.size(); i++) {
			cout << dq[dq.size() - 1 - i];
		}
        cout << endl;
		cout << K << endl;
	}
	else {
		for (int i = 0; i < dq.size(); i++) {
			cout << dq[dq.size() - 1 - i];
		}
        cout << endl;
		cout << i << endl;
	}
    
	return 0;
}
