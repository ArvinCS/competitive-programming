#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	unsigned long long n,m;
	cin >> n >> m;
	
	unsigned long long bebek[n], sepatu[m];
	for(unsigned long long x=0;x<n;x++){
		cin >> bebek[x];
	}
	
	for(unsigned long long x=0;x<m;x++){
		cin >> sepatu[x];
	}
	
	sort(bebek, bebek+n);
	sort(sepatu, sepatu+m);
	
	unsigned long long counter = 0, start = 0;
	for(unsigned long long x=0;x<n;x++){
		for(unsigned long long y=start;y<m;y++){
			if(bebek[x] == sepatu[y] || bebek[x] == sepatu[y]-1){
				counter++;
				start = y+1;
				break;
			} else if(bebek[x] < sepatu[y]) {
				break;
			} else {
				start = y+1;
			}
		}
	}
	
	cout << counter << "\n";
    return 0;
}
