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
		int n, d;
		cin >> n >> d;
		
		int a[2*n];
		for(int x=0;x<n;x++){
			cin >> a[x];
			a[n+x] = a[x];
		}
		
		bool visited[n];
		fill(visited, visited+n, false);
		
		int table[n];
		fill(table, table+n, inf_int);
		
		for(int x=0;x<n;x++){
			if(!visited[x]){
				int pos = x;
				vector<pair<int, int>> w;
				while(!visited[pos]){
					visited[pos] = true;
					w.push_back({a[pos], pos});
					
					pos += d;
					pos %= n;
				}
				
				int sz = w.size();
				for(int y=0;y<sz;y++) w.push_back(w[y]);
				
				int cur = inf_int;
				for(int y=w.size()-1;y>=0;y--){
					if(w[y].first == 0){
						cur = y;
					}
					
					table[w[y].second] = cur-y;
				}
			}
		}
		
		bool possible = true;
		int ans = 0;
		for(int x=0;x<n;x++){
			if(a[x] == 1 && table[x] == inf_int){
				possible = false;
				break;
			}
			
			if(a[x] == 1) ans = max(ans, table[x]);
		}
		
		if(possible){
			cout << ans << "\n";
		} else {
			cout << "-1\n";
		}
	}

    return 0;
}

