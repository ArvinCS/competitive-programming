#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	ll b[n][m];
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			cin >> b[x][y];
		}
	}
	
	bool valid = true;
	for(int x=0;x<n;x++){
		ll mn = 1e18, mx = -1;
		for(int y=0;y<m;y++){
			mn = min(mn, b[x][y]);
			mx = max(mx, b[x][y]);
			
			if(y > 0 && (b[x][y] - b[x][y-1]) != 1){
				valid = false;
			}
			if(x > 0 && (b[x][y] - b[x-1][y]) != 7){
				valid = false;
			}
		}
		
		if((mn+6)/7 != (mx+6)/7){
			valid = false;
		}
	}
	
	cout << (valid ? "Yes" : "No") << "\n";
    return 0;
}

