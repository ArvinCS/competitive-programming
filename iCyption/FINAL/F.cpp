#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define inf_int 1e9
#define inf_ll 1e18

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	unsigned int n, a;
	cin >> n >> a;
	
	unsigned long long c[n];
	for(unsigned int x=0;x<n;x++) cin >> c[x];
	
	sort(c, c+n);
	
	unsigned int ans = 0, cost[n];
	for(unsigned int x=0;x<n;x++){
		cout << c[x] * 2 << " " << a << "\n";
		if(c[x] * 2 + cost[x-1] <= a){
			ans++;
			cost[x] = c[x] * 2 + cost[x-1];
		} else {
			break;
		}
	}
	
	cout << ans << "\n";
    return 0;
}
