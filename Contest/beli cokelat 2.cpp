#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n,d;
	cin >> n >> d;
	
	vector<unsigned long long> cokelat;
	int size = 0;
	for(int x=0;x<n;x++){
		unsigned long long a,b;
		cin >> a >> b;
		cokelat.insert(cokelat.begin(),b,a);
	}
	
	sort(cokelat.begin(), cokelat.end());
	
	unsigned long long counter = 0;
	for(int x=0;x<cokelat.end();x++){
		if(cokelat[x] <= d){
			d -= cokelat[x];
			counter++;
		} else {
			break;
		}
	}
	
	cout << counter << "\n";
    return 0;
}
