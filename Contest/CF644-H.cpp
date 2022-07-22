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
		ll n, m;
		cin >> n >> m;
		
		vector<ll> v;
		for(int x=0;x<n;x++){
			string s;
			cin >> s;
			
			ll val = 0;
			for(int y=0;y<m;y++){
				val *= 2ll;
				val += (s[y] == '1' ? 1 : 0);
			}
			
			v.push_back(val);
		}
		
		sort(v.begin(), v.end());
		
		ll mid = (pow(2, m)-n+1)/2;
		ll pos = 0, cur = 0, ans = 0;
		for(int x=0;x<v.size();x++){
			if(pos < mid && pos+v[x]-cur >= mid){
				ans = cur+(mid-pos)-1;
			}
			
			pos += v[x]-cur;
			cur = v[x]+1;
		}
		if(pos < mid && pos+pow(2, m)-cur >= mid){
			ans = cur+(mid-pos)-1;
		}
		
		for(int y=0;y<m;y++){
			if(ans&(1ll << (m-1-y))){
				cout << 1;
			} else {
				cout << 0;
			}
		}
		cout << "\n";
	}

    return 0;
}

