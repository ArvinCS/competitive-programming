#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	long long person[n];
	for(int x=0;x<n;x++){
		cin >> person[x];
	}
	
	sort(person, person+n);
	
	long long timeServed = 0;
	int served = 0;
	for(int x=0;x<n;x++){
		if(timeServed <= person[x]){
			timeServed += person[x];
			served++;
		}
	}
	cout << served << "\n";
    return 0;
}
