#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	sort(data, data+n);
	if(data[0] == 1){
		for(int x=1;x<n;x++){
			if(x > 1) cout << " ";
			cout << data[x];
		}
		cout << " " << data[0];
		cout << "\n";
	} else {
		for(int x=0;x<n;x++){
			if(x > 0) cout << " ";
			cout << data[x];
		}
		cout << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

