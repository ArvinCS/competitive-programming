#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 998244353

const int maxN = 2005;

vector<int> v;
int a[maxN][maxN], ans[maxN], n;
bool ok[maxN][maxN];
bool found = false;
ll ways = 0;

void solve(int cnt, vector<int> v, vector<int> w){
	if(cnt == n){
		if(!found){
			for(int x=0;x<n;x++){
				ans[x] = v[x]+1;
			}
			found = true;
		}
		
		ways++;
		ways %= mod;
		return;
	}
	
	vector<int> tmp;
	for(int x=0;x<w.size();x++){
		if(w[x] <= v.back()) continue;
		
		bool compatible = true;
		for(int y=0;y<v.size();y++){
			if(!ok[w[x]][v[y]]){
				compatible = false;
				break;
			}
		}
		
		if(compatible){
			tmp.push_back(w[x]);
		}
	}
	
	for(int x=0;x<tmp.size();x++){
		v.push_back(tmp[x]);
		solve(cnt+1, v, tmp);
		v.pop_back();
	}
}

//void color(int curNode){
//	
//}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	us t;
	cin >> t;
	
	while(t--){
		cin >> n;
		
		fill(ok[0], ok[2*n], false);
		ways = 0;
		found = false;
		
		for(int x=0;x<2*n;x++){
			for(int y=0;y<n;y++){
				cin >> a[x][y];
			}
		}
		
		for(int x=0;x<2*n;x++){
			for(int y=x+1;y<2*n;y++){
				if(x == y){
					ok[x][y] = ok[y][x] = true;
					continue;
				}
				
				bool compatible = true;
				for(int z=0;z<n;z++){
					if(a[x][z] == a[y][z]){
						compatible = false;
						break;
					}
				}
				
				ok[x][y] = ok[y][x] = compatible;
			}
		}
		
		vector<int> w;
		for(int x=0;x<2*n;x++){
			w.push_back(x);
		}
		
		for(int x=0;x<2*n;x++){
			vector<int> v;
			v.push_back(x);
			
			solve(1, v, w);
		}
		
		cout << ways << "\n";
		for(int x=0;x<n;x++){
			if(x > 0) cout << " ";
			cout << ans[x];
		}
		cout << "\n";
	}
	
    return 0;
}

