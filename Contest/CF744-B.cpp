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
		
		vector<pair<int, int>> ans;
		ll a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		for(int x=0;x<n;x++){
			int pos = x;
			for(int y=x;y<n;y++){
				if(a[pos] > a[y]){
					pos = y;
				}
			}
			
			if(x >= pos) continue;
			
			ans.push_back({x, pos});
			
			for(int y=pos;y>x;y--){
				a[y] = a[y-1];
			}
		}
		
		cout << ans.size() << "\n";
		for(auto p : ans){
			cout << p.first+1 << " " << p.second+1 << " " << (p.second-p.first) << "\n";
		}
	}
	
    return 0;
}

