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

	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		vector<int> v;
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
			v.push_back(a[x]);
		}
		
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		
		map<int, int> mp;
		for(int x=0;x<v.size();x++){
			mp[v[x]] = x+1;
		}
		
		int table[v.size()+1];
		fill(table, table+v.size()+1, 0);
		
		int ans = 0;
		for(int x=0;x<n;x++){
			table[mp[a[x]]] = max(table[mp[a[x]]], table[mp[a[x]]-1]+1);
			ans = max(ans, table[mp[a[x]]]);
		}
		
		cout << n-ans << "\n";
	}

    return 0;
}

