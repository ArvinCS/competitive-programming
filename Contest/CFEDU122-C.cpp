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
		ll hc, dc, hm, dm;
		cin >> hc >> dc >> hm >> dm;
		
		int k;
		ll w, a;
		cin >> k >> w >> a;
		
		bool possible = false;
		for(int x=0;x<=k;x++){
			int y = k-x;
			
			ll tc = (hm+dc+x*w-1)/(dc+x*w);
			ll tm = (hc+y*a+dm-1)/dm;
			
			if(tc <= tm){
				possible = true;
			}
		}
		
		cout << (possible ? "YES" : "NO") << "\n";
	}
	
    return 0;
}

