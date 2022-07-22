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
		
		string s;
		cin >> s;
		
		int prefix[n][2];
		for(int x=0;x<n;x++){
			for(int y=0;y<2;y++){
				prefix[x][y] = (x > 0 ? prefix[x-1][y] : 0);
				if((s[x] - '0') == y){
					prefix[x][y]++;
				}
			}
		}
		
		pair<int, int> mn[2];
		mn[0] = mn[1] = {0, 0};
		
		for(int x=1;x<n-1;x+=2){
			// case if we place 0
			pair<int, int> tmp[2];
			tmp[1] = min(mn[1], {mn[0].first+prefix[x][1]-prefix[x][0], mn[0].second+1});
			
			// case if we place 1
			tmp[0] = min(mn[0], {mn[1].first+prefix[x][0]-prefix[x][1], mn[1].second+1});
			
			for(int i=0;i<2;i++){
				mn[i] = tmp[i];
			}
		}
		
		pair<int, int> ans = {1e9, 1e9};
		ans = min(ans, {mn[0].first+prefix[n-1][1], mn[0].second+1});
		ans = min(ans, {mn[1].first+prefix[n-1][0], mn[1].second+1});
		
		cout << ans.first << " " << ans.second << "\n";
	}
	
    return 0;
}

