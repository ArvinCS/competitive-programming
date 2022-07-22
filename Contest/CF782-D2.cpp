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
		
		int c[n];
		for(int x=0;x<n;x++){
			cin >> c[x];
		}
		
		int ans[n+1];
		fill(ans, ans+n+1, 0);
		
		int cur = 0;
		for(int x=0;x<n;x++){
			if(cur < 0) cur += (c[x] - (x > 0 ? c[x-1] : 0));
			cur = min(cur, (c[x] - (x > 0 ? c[x-1] : 0)));
			
			if(c[x] == 0) continue;
			if(cur >= 0){
				ans[x] |= 1;
			}
		}
		
		for(int x=0;x<n;x++){
			if(x > 0) cout << " ";
			cout << ans[x];
		}
		cout << "\n";
	}
	
    return 0;
}

