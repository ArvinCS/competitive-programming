#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll n, p;
	cin >> n >> p;
	
	if(n >= p){
		cout << "0\n";
		return 0;
	}
	
	ll ans = 1;
	for(int x=1+!(n&1);x<=n;x+=2){
		ans *= x;
		ans %= p;
	}
	
	cout << ans << "\n";
    return 0;
}

