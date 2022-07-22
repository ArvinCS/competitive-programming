#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll k;

ll powmod(ll x, ll y){
	ll ans = 1;
	
	x %= k;
	while(y > 0){
		if(y&1) ans = (ans * x) % k;
		
		y >>= 1;
		x = (x * x) % k;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int h, w;
	cin >> h >> w >> k;
	
	int a[h], b[w];
	for(int x=0;x<h;x++){
		cin >> a[x];
	}
	for(int x=0;x<w;x++){
		cin >> b[x];
	}
	
	int sumA = 0, sumB = 0;
	for(int x=0;x<h;x++){
		sumA += a[x];
		if(sumA >= k) sumA -= k;
	}
	for(int x=0;x<w;x++){
		sumB += b[x];
		if(sumB >= k) sumB -= k;
	}
	
	if(sumA != sumB){
		cout << "-1\n";
		return 0;
	}
	
	ll ans = h*1ll*w*(k-1);
	ll must = (sumA+sumB) / 2;
	
	for(int x=k-1;x>=0;x--){
		if((ans-(k-1)+x) % k == must){
			ans += x-(k-1);
			cout << "A\n";
			break;
		}
	}
	
	cout << must << "\n";
	cout << ans << "\n";
    return 0;
}

