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

	int n, m;
	cin >> n >> m;
	
	vector<pair<int, int>> v;
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		v.push_back(make_pair(a, b));
	}
	
	int ans = 0;
	for(int x=1;x<=n;x++){
		for(int y=x+1;y<=n;y++){
			bool valid = true;
			
			for(int z=0;z<v.size();z++){
				if(v[z].first == x && v[z].second == y){
					valid = false;
					break;
				}
				if(v[z].first > x && v[z].second > x && v[z].first < y && v[z].second > y){
					valid = false;
					break;
				}
				if(v[z].first < x && v[z].second > x && v[z].first < y && v[z].second < y){
					valid = false;
					break;
				}
			}
			
			if(valid){
				ans++;
				v.push_back(make_pair(x, y));
			}
		}
	}
	
	cout << ans << "\n";
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

