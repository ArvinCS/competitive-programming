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

const int maxN = 5e4 + 5;

int table[2][405];
int last[405];
map<int, vector<int>> w[405];
vector<int> v[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m, k;
	cin >> n >> m >> k;
	
	int data[n], mn = inf_int, mx = 0;
	for(int x=0;x<n;x++){
		cin >> data[x];
		v[data[x]].push_back(x);
		
		mn = min(mn, data[x]);
		mx = max(mx, data[x]);
	}
	
	if(n == k){
		cout << "0\n";
		return 0;	
	}
	
	if(mn == mx){
		cout << (n-k+m-1)/m << "\n";
		return 0;	
	}
	
	fill(table[0], table[2], inf_int);
	fill(last, last+405, -1);
	
	table[0][0] = 0;
	last[0] = 0;
	
	for(int x=1;x<n;x++){
		for(int y=k;y>=0;y--){
			int prv = last[y];
			if(prv < 0) continue;
			
			auto it1 = upper_bound(v[data[x]].begin(), v[data[x]].end(), x);
			auto it2 = lower_bound(v[data[x]].begin(), v[data[x]].end(), prv);
			auto it3 = upper_bound(w[y][data[x]].begin(), w[y][data[x]].end(), x);
			auto it4 = lower_bound(w[y][data[x]].begin(), w[y][data[x]].end(), prv);
			
			int cnt = (it1 - v[data[x]].begin()) - (it2 - v[data[x]].begin()) - ((it3 - w[y][data[x]].begin()) - (it4 - w[y][data[x]].begin()));
			
			int idx = (x%2);
			int idx2 = (idx+1)%2;
//			cout << x << " " << prv << "(" << y << ") -> " << cnt << "\n";
			if(cnt > m){
				int i = cnt-m;			
				if(y+i <= k && cnt-i <= m){
					if(table[idx2][y] < table[idx][y+i]){
						table[idx][y+i] = table[idx2][y];
						last[y+i] = prv;
						
						for(auto m : w[y]){
							vector<int> tmp;
							for(int x=m.second.size()-1;x>=0;x--){
								if(m.second[x] < prv) break;
								
								tmp.push_back(m.second[x]);
							}
							w[y+i][m.first] = tmp;
						}
						
						for(int j=1;j<=i;j++) w[y+i][data[x]].push_back(v[data[x]][(it1-v[data[x]].begin())-j]);
					}
				}
				
				if(cnt-1 <= m){
					table[idx][y] = table[idx2][y]+1;
					last[y] = x;
				} else {
					table[idx][y] = inf_int;
					last[y] = -1;
				}
			} else {
				table[idx][y] = table[idx2][y];
				last[y] = prv;
			}
		}
	}
	
//	for(int x=0;x<n;x++){
//		for(int y=0;y<=k;y++){
//			cout << table[x][y] << " ";
//		}
//		cout << "\n";
//	}

	int ans = inf_int;
	for(int x=0;x<=k;x++){
		ans = min(ans, table[(n-1)%2][x]);
	}
	cout << ans+1 << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

