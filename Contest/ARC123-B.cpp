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
	
	ll a[n], b[n], c[n];
	multiset<ll> st1, st2;
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	for(int x=0;x<n;x++){
		cin >> b[x];
		st1.insert(b[x]);
	}
	for(int x=0;x<n;x++){
		cin >> c[x];
		st2.insert(c[x]);
	}
	
	sort(a, a+n);
	
	int ans = 0;
	for(int x=0;x<n;x++){
		auto it = st1.lower_bound(a[x]+1);
		
		if(it != st1.end()){
			auto it2 = st2.lower_bound((*it)+1);
			
			if(it2 != st2.end()){
				ans++;
				
				st1.erase(it);
				st2.erase(it2);
			}
		}
	}
	
	cout << ans << "\n";
    return 0;
}

