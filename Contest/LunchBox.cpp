#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	unsigned short n,m;
	cin >> n >> m;
	
	unsigned short k[m];
	for(unsigned short x=0;x<m;x++) cin >> k[x];
	
	sort(k, k+m);
	
	unsigned short total = 0, ans = 0;
	for(unsigned short x=0;x<m;x++){
		if(total + k[x] <= n){
			ans++;
			total += k[x];
		}
	}
	
	cout << ans << "\n";
    return 0;
}
