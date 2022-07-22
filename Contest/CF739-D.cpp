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

	int t;
	cin >> t;
	
	while(t--){
		ll n;
		cin >> n;
		
		vector<ll> v;
		ll cur = n;
		while(cur > 0){
			v.push_back(cur%10);
			cur /= 10;
		}
		
		reverse(v.begin(), v.end());
		
		int ans = v.size()+1;
		ll pw = 1;
		for(int x=0;x<59;x++){
			vector<ll> w;
			
			ll tmp = pw;
			while(tmp > 0){
				w.push_back(tmp%10);
				tmp /= 10;
			}
			
			int pos = w.size()-1;
			for(int y=0;y<v.size();y++){
				if(pos >= 0 && v[y] == w[pos]){
					pos--;
					continue;
				}
			}
			
			pw *= 2;
						
			int sz = v.size()+w.size();
			ans = min(ans, sz-2*((int)w.size()-1-pos));
		}
		
		cout << ans << "\n";
	}

    return 0;
}

