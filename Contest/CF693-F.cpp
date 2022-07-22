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
		int n, m;
		cin >> n >> m;
		
		vector<pair<int, int>> v;
		for(int x=0;x<m;x++){
			int a, b;
			cin >> a >> b;
			
			a--; b--;
			v.push_back({b, a});
		}
		
		sort(v.begin(), v.end());
		
		vector<pair<int, int>> w;
		for(int x=0;x<v.size();x++){
			if(x+1 < v.size() && v[x].first == v[x+1].first){
				continue;
			} else {
				if(x-1 >= 0 && v[x-1].first == v[x].first){
					w.push_back({v[x].first, 3});
				} else if(v[x].second == 0){
					w.push_back({v[x].first, 1});
				} else {
					w.push_back({v[x].first, 2});
				}
			}
		}
		
		if(w.size() == 1){
			if(w[0].second == 3){
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
			continue;
		}
		
		bool possible = true, behind = (w[0].second != 3);
		for(int x=1;x<w.size();x++){
			int dist = w[x].first-w[x-1].first;
			
			if(behind){ // we care about behind blocked cell
				dist++;
				
				if(dist % 2 == 0){
					if(w[x].second != w[x-1].second){
						if(w[x].second != 3 || w[x-1].second != 3){
							possible = false;
							break;
						}
					}
				} else {
					if(w[x].second == 3 || w[x-1].second == 3){
						possible = false;
						break;
					}
					if(w[x].second == w[x-1].second){
						possible = false;
						break;
					}
				}
				behind = false;
			} else {
				if(dist % 2 == 0){
					if(w[x].second != 3){
						behind = true;
					}
				} else {
					if(w[x].second != 3){
						behind = true;
					}
				}
			}
		}
		if(behind){
			possible = false;
		}
		
		if(possible) cout << "YES\n";
		else cout << "NO\n";
	}

    return 0;
}

