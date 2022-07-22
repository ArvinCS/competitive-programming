#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int mx = 1e6;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	for(int i=1;i<=t;i++){
		int a[3][4];
		for(int x=0;x<3;x++){
			for(int y=0;y<4;y++){
				cin >> a[x][y];
			}
		}
		
		int sum = 0;
		int ans[4];
		for(int y=0;y<4;y++){
			int mn = 1e9;
			for(int x=0;x<3;x++){
				mn = min(mn, a[x][y]);
			}
			
			sum += mn;
			ans[y] = mn;
		}
		
		cout << "Case #" << i << ": ";
		if(sum < mx){
			cout << "IMPOSSIBLE\n";
			continue;
		}
		
		for(int y=0;y<4;y++){
			int need = min(sum-mx, ans[y]);
			ans[y] -= need;
			sum -= need;
		}
		for(int y=0;y<4;y++){
			if(y > 0) cout << " ";
			cout << ans[y];
		}
		cout << "\n";
	}
	
    return 0;
}

