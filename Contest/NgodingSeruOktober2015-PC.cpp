#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	short n;
	cin >> n;
	
	short a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	for(int x=n-1;x>=0;x--){
		if(x != n-1) cout << ",";
		cout << a[x];
	}
	cout << "\n";
    return 0;
}

