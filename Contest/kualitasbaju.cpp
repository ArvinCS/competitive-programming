#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	float data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	sort(data, data+n);
	
	if(n%2 == 0){
		float median = (data[n/2-1] + data[n/2]) / 2;
		cout << fixed << setprecision(1) << median << "\n";
	} else {
		int median = ceil(n/2);
		cout << fixed <<  setprecision(1) << data[median] << "\n";
	}
    return 0;
}
