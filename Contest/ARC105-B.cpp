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

const int maxN = 1e5 + 5;

int n;
ll arr[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> n;
	for(int x=0;x<n;x++){
		cin >> arr[x];
	}
	
	sort(arr, arr+n);
	
	if(n == 1){
		cout << arr[0] << "\n";
		return 0;
	}
	
	ll cur = __gcd(arr[0], arr[1]);
	for(int x=2;x<n;x++){
		cur = __gcd(cur, arr[x]);
	}
	cout << cur << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

