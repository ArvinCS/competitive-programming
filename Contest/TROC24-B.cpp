#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	ll odd = 0, even = 0;
	for(int x=0;x<n;x++){
		if(x&1){
			odd += a[x];
		} else {
			even += a[x];
		}
	}
	
	ll ans = even-odd;
	ll curOdd = 0, curEven = 0;
	for(int x=0;x<n-1;x++){
		if(x&1){
			curOdd += a[x];
			odd -= a[x];
			
			ans = max(ans, (curOdd+odd)-(even+curEven));
		} else {
			curEven += a[x];
			even -= a[x];
			
			ans = max(ans, (even+curEven)-(curOdd+odd));
		}
	}
	
	cout << ans << "\n";
	return 0;
}
