#include <bits/stdc++.h>

using namespace std;

#define ll long long

int solve(int n, int i){
	int ans = (n >> (i+1)) << i;
	
	if(n&(1 << i)){
		ans += n & ((1 << i) - 1);
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int l, r;
		cin >> l >> r;
		
		int ans = 1e9;
		for(int i=0;i<21;i++){
			int bit = (1 << i);
			
			ans = min(ans, (r-l+1)-(solve(r+1, i)-solve(l, i)));
		}
		cout << ans << "\n";
	}
	
    return 0;
}

