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
		
		ll ans[n];
		ans[0] = 1;
		
		bool possible = true;
		for(int x=1;x<n;x++){
			if(ans[x-1]*3 <= 1e9){
				ans[x] = ans[x-1]*3;
			} else {
				possible = false;
			}
		}
		
		if(possible){
			cout << "YES\n";
			for(int x=0;x<n;x++){
				if(x > 0) cout << " ";
				cout << ans[x];
			}
			cout << "\n";
		} else {
			cout << "NO\n";
		}
	}	
	
    return 0;
}

