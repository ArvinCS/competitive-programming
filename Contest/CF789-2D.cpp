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
		int n, m;
		cin >> n >> m;
		
		string s;
		cin >> s;
		
		int col[m], row[m];
		fill(row, row+m, 0);
		fill(col, col+m, 0);
		
		int ans[n*m];
		fill(ans, ans+n*m, 0);
		
		int cur = 0, cp = n*m, last = 0;
		for(int x=0;x<n*m;x++){
			if(s[x] == '1'){ // serious
				// for column
				if(col[x%m] == 0) cur++;				
				col[x%m]++;
				last = x+1;
				if(x < cp) cp = x;
			} else if(s[x] == '0'){
				if(x-last+1 >= m){
					row[x%m]++;
				}
			}
			
//			cout << x << " -> " << cur << " " << (x+1)/m << " - " << row[x%m] << "\n";
			ans[x] = cur + ((x+1)/m - row[x%m]) + (cp < (x+1)%m);
		}
		
		for(int x=0;x<n*m;x++){
			if(x > 0) cout << " ";
			cout << ans[x];
		}
		cout << "\n";
	}
	
    return 0;
}

