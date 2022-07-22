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
		
		int m = s.length();
		pair<ll, ll> suffix[m];
		suffix[m] = {0, 0};
		for(int x=m-1;x>=0;x--){
			suffix[x] = suffix[x+1];
			
			if(s[x] == 'D'){
				suffix[x].first++;
			} else {
				suffix[x].second++;
			}
		}
		
		bool right = false, down = false;
		ll ans = 1;
		ll row = 0, col = 0;
		ll mxrow = 0, mxcol = 0;
		for(int x=0;x<m;x++){		
			if(s[x] == 'D'){
				row++;
				down = true;
			} else {
				col++;
				right = true;
			}
			
			ll curmxrow = (down ? max(mxrow, n-1-suffix[x+1].first) : 0);
			ll curmxcol = (right ? max(mxcol, n-1-suffix[x+1].second) : 0);
			
			if(mxrow < row || mxcol < col){
				ans += (curmxcol-col+1)*(curmxrow-row+1);
			} else {
				ans += (curmxcol-col+1)*(curmxrow-max(mxrow, row-1));
				ans += (curmxcol-max(mxcol, col-1))*(curmxrow-row+1);
			}
				
			mxrow = curmxrow;
			mxcol = curmxcol;
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

