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

const int maxN = 510;

int n, k;
int dist[maxN], backtrack[maxN];

// dist[remaining]
// backtrack[remaining]

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> n >> k;
	
	fill(dist, dist+n+5, inf_int);
	fill(backtrack, backtrack+n+5, -1);
	
	dist[n+1] = -1;
	queue<pair<int, int>> q;
	q.push({0, n+1});
	
	while(!q.empty()){
		pair<int, int> p = q.front();
		q.pop();
		
		if(dist[p.first] != inf_int) continue;
//		cout << p.first << " " << p.second << "\n";
		
		dist[p.first] = dist[p.second]+1;
		backtrack[p.first] = p.second;
		
		for(int x=0;x<=k;x++){
			if(p.first+x-(k-x) < 0 || p.first+x-(k-x) > n) continue;
			if(p.first < (k-x) || n-p.first < x) continue;
			
//			cout << p.first+x-(k-x) << " " << x << " " << p.first << "\n";
			if(dist[p.first+x-(k-x)] > dist[p.first]+1){
				q.push({p.first+x-(k-x), p.first});
			}
		}
	}
	
	if(dist[n] == inf_int){
		cout << "-1" << endl;
		return 0;
	}
	
	int cnt[n], curNode = n, ans = 0;
	fill(cnt, cnt+n, 1);
	
	while(curNode > 0){
		int diff = abs(curNode-backtrack[curNode]);
		int zero = 0, one = 0;
		if(curNode >= backtrack[curNode]){
			one = (diff+k)/2;
			zero = k-one;	
		} else {
			zero = (diff+k)/2;
			one = k-zero;
		}
		
		cout << "?";
		for(int x=0;x<n;x++){
			if(cnt[x] % 2 == 0){
				if(zero > 0){
					cout << " " << x+1;
					
					zero--;
					cnt[x]^=1;
				}
			} else {
				if(one > 0){
					cout << " " << x+1;
					
					one--;
					cnt[x]^=1;
				}
			}
		}
		cout << endl;
		
		int res;
		cin >> res;
		
		ans ^= res;
		
		curNode = backtrack[curNode];
	}
	
	cout << "! " << ans << endl;	
    return 0;
}

