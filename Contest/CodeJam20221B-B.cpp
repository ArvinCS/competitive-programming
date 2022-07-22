#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	for(int i=1;i<=t;i++){
		int n, m;
		cin >> n >> m;
		
		vector<ll> v[n];
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				ll val;
				cin >> val;
				
				v[x].push_back(val);
			}
			
			sort(v[x].begin(), v[x].end());
		}
		
		ll table[n][2];
		fill(table[0], table[n], 1e18);
		
		table[0][0] = v[0][m-1]+abs(v[0][m-1]-v[0][0]);
		table[0][1] = v[0][m-1];
		
		for(int x=1;x<n;x++){
			// end at the left
			table[x][0] = min(table[x-1][0]+abs(v[x][m-1]-v[x-1][0])+abs(v[x][m-1]-v[x][0]), table[x-1][1]+abs(v[x][m-1]-v[x-1][m-1])+abs(v[x][m-1]-v[x][0]));
			
			// end at the right
			table[x][1] = min(table[x-1][0]+abs(v[x][0]-v[x-1][0])+abs(v[x][m-1]-v[x][0]), table[x-1][1]+abs(v[x][0]-v[x-1][m-1])+abs(v[x][m-1]-v[x][0]));
		}
		
		cout << "Case #" << i << ": " << min(table[n-1][0], table[n-1][1]) << "\n";
	}
	
    return 0;
}

