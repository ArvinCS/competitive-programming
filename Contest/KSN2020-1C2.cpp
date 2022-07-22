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
const int maxK = 405;
const int lgN = log2(maxN)+1;

vector<int> v[maxN];
pair<int, int> w[maxK][maxK];
int h[maxN];
int table[2][maxK];
int last[maxK];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m, k;
	cin >> n >> m >> k;
	
	bool same = true;
	for(int x=0;x<n;x++){
		cin >> h[x];
		v[h[x]].push_back(x);
		
		if(x > 0 && h[x-1] != h[x]) same = false;
	}
	
	if(n == k){
		cout << "0\n";
		return 0;
	}
	
	if(same){
		cout << (n-k+m-1)/m << "\n";
		return 0;
	}
	
	fill(table[0], table[2], inf_int);
	fill(last, last+maxK, -1);
	fill(w[0], w[maxK], make_pair(-1, 0));
	
	table[0][0] = 1;
	last[0] = 0;
	
	for(int x=1;x<n;x++){
		for(int i=k;i>=0;i--){
			if(last[i] < 0) continue;
			
			int rightCnt = upper_bound(v[h[x]].begin(), v[h[x]].end(), x) - v[h[x]].begin();
			int leftCnt = lower_bound(v[h[x]].begin(), v[h[x]].end(), last[i]) - v[h[x]].begin();
			
			int cnt = (rightCnt - leftCnt);
			
			for(auto p : w[i]){
				if(p.first == -1) break;
				if(p.first == h[x]){
					cnt -= p.second;
					break;
				}
			}
			
			if(cnt > m){
				int remain = cnt-m;
				if(remain+i <= k){
					if(table[(x&1)^1][i] < table[x&1][remain+i]){
						table[x&1][remain+i] = table[(x&1)^1][i];
						last[remain+i] = last[i];
						
						bool found = false;
						for(int j=0;j<400;j++){
							w[remain+i][j] = w[i][j];
							if(!found && w[remain+i][j].first == h[x]){
								found = true;
								w[remain+i][j].second += remain;
							}
							if(w[remain+i][j].first == -1){
								if(!found){
									w[remain+i][j].first = h[x];
									w[remain+i][j].second = remain;
								}
								break;
							}
						}
					}
				}
				
				if(cnt-1 <= m){ // remain 1, we take it to create new group
					table[x&1][i] = table[(x&1)^1][i]+1;
					last[i] = x;
					
					for(int j=0;j<400;j++){
						if(w[i][j].first == -1) break;
						
						w[i][j].first = -1;
						w[i][j].second = 0;
					}
				} else {
					table[x&1][i] = inf_int;
					last[i] = -1;
				}
			} else {
				table[x&1][i] = table[(x&1)^1][i];
			}
		}
	}
	
	int ans = inf_int;
	for(int x=0;x<=k;x++){
		ans = min(ans, table[(n-1)&1][x]);
	}
	
	cout << ans << "\n";
    return 0;
}

