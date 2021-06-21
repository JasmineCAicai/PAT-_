// 完全正确
#include <iostream>
#include<iomanip>

using namespace std;

int main(){
	double a[1001]={0.0},b[2001]={0.0},t;
	int  n1,n2,m,i,j;
	cin >> n1;
	for(i=0;i<n1;i++){
		cin >> m >> t;
		a[m]=t;
	}
	cin >> n2;
	for(i=0;i<n2;i++){
		cin >> m >> t;
		for(j=0;j<1001;j++){
			if(a[j]!=0.0){
				b[m+j]+=a[j]*t;
			}
		}
	}
	j=0;
	for(i=0;i<2001;i++){
		if(b[i]!=0.0)
			j++;
	}
	cout << j;
	for(i=2000;i>=0;i--){
		if(b[i]!=0.0)
            cout << " " << i << " " << fixed << setprecision(1) << b[i];
	}
    cout << endl;
	return 0;
} 
