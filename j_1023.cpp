#include <iostream>
#include <cstring>

using namespace std;

int main() {
	string a;
	getline(cin,a);
    
	int length = a.length(); 
	int i, num[length + 1];
	int digit[10] = {0};
    
	for (i = 0; i < length; i++) {
		num[i] = a[i] - '0';
		digit[num[i]]++;
	} 
	
	int add = 0, j;
	for (i = length - 1; i >= 0; i--) {
		j = num[i] * 2;
		j += add;
		if (j >= 10){
			num[i] = j - 10;
			add = 1;
		} 
        else {
			num[i]=j;
			add=0;
		}
	}
    
	if (add == 1) {
		for (i = length; i >= 1; i--) {
            num[i] = num[i - 1];
        }
		num[0] = 1;
		length++;
		cout << "No" << endl; 
	}
    else {
		for (i = 0; i < length; i++) {
			digit[num[i]]--;
		}
		for (i = 0; i < 10; i++) {
			if (digit[i] != 0){
				cout << "No" << endl;
				add = 2; 
				break;
			}
        }
		if (add != 2) cout << "Yes" << endl;
	}
    
	for (i = 0; i < length; i++) {
        cout << num[i];
    }
    
	return 0;
} 
