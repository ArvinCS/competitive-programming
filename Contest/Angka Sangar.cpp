#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

const ull maxN = 1e9;

int len(ll x){
	int ans = 0;
	while(x > 0){
		x /= 10;
		ans++;
	}	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ull n;
	cin >> n;
	
	vector<ll> c{1, 5, 6, 25, 76, 376, 625, 9376, 90625, 109376, 890625, 2890625, 7109376, 12890625, 87109376, 212890625, 787109376};
	for(int i=0;i<c.size();i++){
		ull panjangC = pow(10, len(c[i]));
		for(ll b=1;b<=1e5;b++){
			if((n*panjangC+c[i])%(b*panjangC+c[i]) != 0) continue;
			ll ac = (n*panjangC+c[i])/(b*panjangC+c[i]);
			if(ac >= panjangC && ac % panjangC == c[i]){
				cout << "YA\n";
				cout << ac/panjangC << " " << b << " " << c[i] << "\n";
				return 0;
			}	
		}
	}
	cout << "TIDAK\n";
    return 0;
}

