#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		array<int, 4> p[2*n];
		for(int x=0;x<n;x++){
			cin >> p[x][0] >> p[x][1];
			p[x][2] = x;
			p[x][3] = 0;
		}
		for(int x=0;x<n;x++){
			for(int y=0;y<3;y++){
				p[n+x][y] = p[x][y];
			}
			swap(p[n+x][0], p[n+x][1]);
			p[n+x][3] = 1;
		}
		
		int ans[n];
		fill(ans, ans+n, -1);
		
		sort(p, p+2*n);
		
		pair<int, int> mn = {1e9, 1e9}, mn2 = {1e9, 1e9};
		for(int x=0;x<2*n;x++){
			if(x > 0 && p[x-1][0] != p[x][0]){
				mn = min(mn, mn2);
				mn2 = {1e9, 1e9};
			}
			
			if(p[x][3] == 0){
				if(mn.first < p[x][1]){
					ans[p[x][2]] = mn.second+1;
				}
			}
			
			mn2 = min(mn2, {p[x][1], p[x][2]});
		}
		
		for(int x=0;x<n;x++){
			if(x > 0) cout << " ";
			cout << ans[x];
		}
		cout << "\n";
	}
	
    return 0;
}

