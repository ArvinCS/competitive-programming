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
	
	vector<ll> v;
	unordered_set<ll> st;
	for(int x=0;x<n;x++){
		ll tmp;
		cin >> tmp;
		
		st.insert(tmp);
		v.push_back(tmp);
	}
	
	int cnt = 0;
	while(v.size() < m){
		cnt++;
		int sz = v.size();
		for(int x=0;x<sz;x++){
			for(int y=0;y<sz;y++){
				if(x == y) continue;
				
				ll res = 2*v[x]-v[y];
				if(!st.count(res)) v.push_back(res);
				st.insert(res);
				res = 2*v[y]-v[x];
				if(!st.count(res)) v.push_back(res);
				st.insert(res);
				if(v.size() >= m) break;
			}
		}
	}
	
	sort(v.begin(), v.end());
	
	for(int x=0;x<v.size();x++){
		if(x > 0) cout << " ";
		cout << v[x];
	}
	cout << "\n";
	cout << cnt << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

