#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int t;
	cin >> t;
	
	while(t--){
		ll cnt[3];
		for(int x=0;x<3;x++){
			cin >> cnt[x];
		}
		
		for(int x=0;x<3;x++){
			ll mx = 0;
			for(int y=0;y<3;y++){
				if(x != y) mx = max(mx, cnt[y]);
			}
			
			if(x > 0) cout << " ";
			cout << max(mx+1-cnt[x], 0ll);
		}
		cout << "\n";
	}

    return 0;
}

