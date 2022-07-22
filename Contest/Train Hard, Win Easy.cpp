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
	
	pair<int, int> s[n];
	for(int x=0;x<n;x++){
		cin >> s[x].first >> s[x].second;
	}
	
	vector<int> v[n];
	for(int x=0;x<m;x++){
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		
		tmp1--; tmp2--;
		v[tmp1].push_back(tmp2);
		v[tmp2].push_back(tmp1);
	}
	
	sort(s, s+n);
	
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

