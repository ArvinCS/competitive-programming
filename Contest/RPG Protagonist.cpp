#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		ui p, f;
		cin >> p >> f;
		
		ui swords, axes;
		cin >> swords >> axes;
		
		ui ws, wa;
		cin >> ws >> wa;
		
		if(wa < ws){
			swap(swords, axes);
			swap(ws, wa);
		}
		
		ui ans = 0;
		
		for(ui x=0;x<=min(swords, p/ws);x++){
			ui tmp1 = min(axes, (p-x*ws)/wa), tmp2 = min(swords-x, f/ws), tmp3 = min(axes-tmp1, (f-tmp2*ws)/wa);
			
			ans = max(ans, x+tmp1+tmp2+tmp3);
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

