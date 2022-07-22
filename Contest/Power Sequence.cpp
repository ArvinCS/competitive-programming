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
	
	ui n;
	cin >> n;
	
 	ll data[n];
	for(ui x=0;x<n;x++){
		cin >> data[x];
	}
	
	sort(data, data+n);
	ll ans = 0;
	for(ui x=0;x<n;x++) ans += abs(data[x] - 1);

	for(ull x=2;x*x<=5000000005;x++){
		ull j;
		ll currentNum = 1, tmp = 0;
		for(j=0;j<n;j++){
			tmp += abs(currentNum - data[j]);
			if(tmp >= ans) break;
			currentNum *= x;
		}
//		cout << tmp << " " << ans << "\n";
		if(j == n){
			ans = min(ans, tmp);
		}
	}
	
	cout << ans << "\n";
    return 0;
}

