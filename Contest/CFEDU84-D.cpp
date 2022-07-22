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

const int maxN = 2e5 + 5;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
			a[x]--;
		}
		
		int c[n];
		for(int x=0;x<n;x++){
			cin >> c[x];
		}
		
		bool visited[n];
		fill(visited, visited+n, false);
		
		int ans = n;
		for(int x=0;x<n;x++){
			if(!visited[x]){
				int node = x;
				vector<int> v;
				while(!visited[node]){
					visited[node] = true;
					v.push_back(node);
					node = a[node];
				}
				
				for(int i=1;i<=v.size();i++){
					if(v.size()%i == 0){
						for(int y=0;y<i;y++){
							bool ok = true;
							for(int z=y;z+i<v.size();z+=i){
								if(c[v[z]] != c[v[z+i]]){
									ok = false;
									break;
								}
							}
							
							if(ok){
								ans = min(ans, i);
								break;
							}
						}
					}
				}
			}
		}
		
		cout << ans << "\n";
	}

    return 0;
}

