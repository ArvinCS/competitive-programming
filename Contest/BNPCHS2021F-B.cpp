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
	
	int n, m;
	cin >> n >> m;
	
	pair<int, int> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first;
		
		char c;
		cin >> c;
		
		p[x].second = (c == 'U' ? 1 : -1);
	}
	
	set<pair<int, int>> st[2];
	
	for(int x=0;x<n;x++){
		st[(p[x].first%2)].insert(p[x]);
	}
	
	if(st[0].size() != 0 && st[1].size() != 0){
		cout << "NO\n";
		return 0;
	}
	if(st[0].size() > 2 || st[1].size() > 2){
		cout << "NO\n";
		return 0;
	}
	
	cout << "YES\n";
    return 0;
}

