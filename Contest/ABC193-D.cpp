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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	ll k;
	cin >> k;
	
	string s, t;
	cin >> s >> t;
	
	ll cnt[2][15];
	fill(cnt[0], cnt[2], 0);
	
	ll a = 45, b = 45;
	for(ll x=0;x<4;x++){
		ll digit = (s[x] - '0');
		a -= digit * pow(10, cnt[0][digit]++);
		a += digit * pow(10, cnt[0][digit]);
	}
	for(ll x=0;x<4;x++){
		ll digit = (t[x] - '0');
		b -= digit * pow(10, cnt[1][digit]++);
		b += digit * pow(10, cnt[1][digit]);
	}
	
	ull taka = 0, aoi = 0;
	for(ll x=1;x<=9;x++){
		if(cnt[0][x] + cnt[1][x] >= k){
			continue;
		}
		
		ll tmp1 = a;
		tmp1 -= x * pow(10ll, cnt[0][x]);
		tmp1 += x * pow(10ll, cnt[0][x]+1);
//		cout << x << " -> " << tmp1 << "\n";
		for(ll y=1;y<=9;y++){
			if(cnt[0][y] + cnt[1][y] + (x == y) >= k){
				continue;
			}
			
			ll tmp2 = b;
			tmp2 -= y * pow(10ll, cnt[1][y]);
			tmp2 += y * pow(10ll, cnt[1][y]+1);
//			cout << y << " ---> " << tmp2 << "\n";
			
			ll tmp3 = (k - (cnt[0][x] + cnt[1][x])) * (k - (cnt[0][y] + cnt[1][y] + (x == y)));
			if(tmp1 > tmp2){
				taka += tmp3;
			} else {
				aoi += tmp3;
			}
		}
	}
//	cout << a << " " << b << "\n";
//	cout << taka << " " << aoi << "\n";
	
	cout << fixed << setprecision(15) << (taka * 1.0)/(taka+aoi) << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

