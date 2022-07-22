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
	
	ll n;
	cin >> n;
	
	n = pow(2, n);
	
	ll arr[n+1];
	
	for(int x=1;x<=n;x++){
		cin >> arr[x];
	}
	
	pair<ll, int> a, b;
	a.first = arr[1];
	a.second = 1;
	for(int x=2;x<=n/2;x++){
		if(a.first < arr[x]){
			a.first = arr[x];
			a.second = x;
		}
	}
	
	b.first = arr[n/2+1];
	b.second = n/2+1;
	for(int x=n/2+2;x<=n;x++){
		if(b.first < arr[x]){
			b.first = arr[x];
			b.second = x;
		}
	}
	
	if(a.first > b.first){
		cout << b.second << "\n";
	} else {
		cout << a.second << "\n";
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

