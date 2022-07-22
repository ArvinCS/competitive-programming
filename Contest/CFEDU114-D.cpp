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

int n, m;
vector<ll> v[15];
set<vector<int>> b;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	cin >> n;
	
	for(int x=0;x<n;x++){
		int k;
		cin >> k;
		
		for(int y=0;y<k;y++){
			ll val;
			cin >> val;
			
			v[x].push_back(val);
		}
	}
		
	cin >> m;
	
	for(int x=0;x<m;x++){
		vector<int> tmp;
		for(int y=0;y<n;y++){
			int val;
			cin >> val;
			
			val--;
			tmp.push_back(val);
		}
		b.insert(tmp);
	}
	
	ll mx = -inf_ll;
	vector<int> ans;
	{
		vector<int> tmp;
		ll cnt = 0;
		for(int x=0;x<n;x++){
			tmp.push_back(v[x].size()-1);
			cnt += v[x].back();
		}
		
		if(!b.count(tmp)){
			mx = cnt;
			ans = tmp;
		}
	}
	for(auto ban : b){		
		for(int x=0;x<n;x++){
			int bef = ban[x];
			if(bef+1 < v[x].size()){
				ban[x] = bef+1;
				if(!b.count(ban)){
					ll cnt = 0;
					for(int y=0;y<n;y++){
						cnt += v[y][ban[y]];
					}
					
					if(mx < cnt){
						mx = cnt;
						ans = ban;
					}
				}
			}
			if(bef > 0){
				ban[x] = bef-1;
				if(!b.count(ban)){
					ll cnt = 0;
					for(int y=0;y<n;y++){
						cnt += v[y][ban[y]];
					}
					
					if(mx < cnt){
						mx = cnt;
						ans = ban;
					}
				}
			}
			ban[x] = bef;
		}
	}
	
	for(int x=0;x<n;x++){
		if(x > 0) cout << " ";
		cout << ans[x]+1;
	}
	cout << "\n";
    return 0;
}

