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
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	map<int, int> mp;
	for(int x=2;x<=n;x++){
//		cout << x << " -> " << n/x << "\n";
		mp[n/x]++;
	}
	
	for(auto p : mp){
		cout << p.first << " " << p.second << "\n";
	}
	
	cout << mp.size() << "\n";
    return 0;
}
