#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	long list[n];
	for(int x=0;x<n;x++){
		cin >> list[x];
	}
	
	sort(list, list+n);
	
	cout << list[k-1] << "\n";
    return 0;
}
