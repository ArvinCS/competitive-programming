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
	
	for(int i=1;i<=t;i++){
		int n;
		cin >> n;
		
		int a[n][n], b[n][n], cntr[n], cntc[n];
		fill(cntr, cntr+n, 0);
		fill(cntc, cntc+n, 0);
		
		for(int x=0;x<n;x++){
			for(int y=0;y<n;y++){
				cin >> a[x][y];
				if(a[x][y] == -1){
					cntr[x]++;
					cntc[y]++;
				}
			}
		}
		for(int x=0;x<n;x++){
			for(int y=0;y<n;y++){
				cin >> b[x][y];
			}
		}
		
		int row[n], col[n];
		for(int x=0;x<n;x++){
			cin >> row[x];
		}
		for(int x=0;x<n;x++){
			cin >> col[x];
		}
		
		if(n == 1){
			cout << "Case #" << i << ": 0\n";
			continue;
		}
		
		bool change = true;
		while(change){
			change = false;
			for(int x=0;x<n;x++){
				if(cntr[x] == 1){
					int idx = -1, sum = -1;
					for(int y=0;y<n;y++){
						if(a[x][y] != -1){
							if(sum == -1) sum = a[x][y];
							else sum ^= a[x][y];
						} else {
							idx = y;
						}
					}
					
					if(sum^1 == row[x]){
						a[x][idx] = 1;
					} else {
						a[x][idx] = 0;
					}
					cntr[x]--;
					cntc[idx]--;
					change = true;
				}
			}
			for(int y=0;y<n;y++){
				if(cntc[y] == 1){
					int idx = -1, sum = -1;
					for(int x=0;x<n;x++){
						if(a[x][y] != -1){
							if(sum == -1) sum = a[x][y];
							else sum ^= a[x][y];
						} else {
							idx = x;
						}
					}
					
					if(sum^1 == col[y]){
						a[idx][y] = 1;
					} else {
						a[idx][y] = 0;
					}
					cntr[idx]--;
					cntc[y]--;
					change = true;
				}
			}
		}
		
		ll ans = 0;
		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
		for(int x=0;x<n;x++){
			for(int y=0;y<n;y++){
				if(a[x][y] == -1){
					pq.push(make_pair(b[x][y], make_pair(x, y)));
				}
			}
		}
		
		if(pq.size() > 0 && n == 2){
			cout << "Case #" << i << ": " << pq.top().first << "\n";
			continue;
		}
		
		while(!pq.empty()){
			pair<int, pair<int, int>> p = pq.top();
			pq.pop();
			
			int x = p.second.first, y = p.second.second;
			if(a[x][y] != -1) continue;
			
//			cout << x << " " << y << " --> ";
			ans += b[x][y];
			a[x][y] = 1;
			cntr[x]--;
			cntc[y]--;
			
			change = true;
			while(change){
				change = false;
				for(int x=0;x<n;x++){
					if(cntr[x] == 1){
						int idx = -1, sum = -1;
						for(int y=0;y<n;y++){
							if(a[x][y] != -1){
								if(sum == -1) sum = a[x][y];
								else sum ^= a[x][y];
							} else {
								idx = y;
							}
						}
						
						if(sum^1 == row[x]){
							a[x][idx] = 1;
						} else {
							a[x][idx] = 0;
						}
						cntr[x]--;
						cntc[idx]--;
						change = true;
					}
				}
				for(int y=0;y<n;y++){
					if(cntc[y] == 1){
						int idx = -1, sum = -1;
						for(int x=0;x<n;x++){
							if(a[x][y] != -1){
								if(sum == -1) sum = a[x][y];
								else sum ^= a[x][y];
							} else {
								idx = x;
							}
						}
						
						if(sum^1 == col[y]){
							a[idx][y] = 1;
						} else {
							a[idx][y] = 0;
						}
						cntr[idx]--;
						cntc[y]--;
						change = true;
					}
				}
			}
//			cout << ans << "\n";
		}
		cout << "Case #" << i << ": " << ans << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

