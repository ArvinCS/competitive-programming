#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	ll ans = 0, r = 0, g = 0, b = 0;
	for(int x=0;x<n;x++){
		for(int y=x+1;y<n;y++){
			if(s[x] != s[y]){
				if((s[x] == 'R' && s[y] == 'G') || (s[x] == 'G' && s[y] == 'R')){
					ans += b;
				} else if((s[x] == 'R' && s[y] == 'B') || (s[x] == 'B' && s[y] == 'R')){
					ans += g;
				} else {
					ans += r;
				}
				
				int prv = x-(y-x);
				if(prv >= 0 && s[x] != s[prv] && s[y] != s[prv]){
					ans--;
				}
			}
		}
		
		if(s[x] == 'R'){
			r++;
		} else if(s[x] == 'G'){
			g++;
		} else {
			b++;
		}
	}
	
	cout << ans << "\n";
    return 0;
}

