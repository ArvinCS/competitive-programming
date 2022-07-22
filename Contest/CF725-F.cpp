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
	
	us t;
	cin >> t;
	
	while(t--){
		ll l, r;
		cin >> l >> r;
		
		ll a = 0, b = 0;		
		ll tmp = l;
		ll digit[10], p = 9;
		fill(digit, digit+10, 0);
		
		while(tmp > 0){
			digit[p--] = tmp%10;
			tmp /= 10;
		}
		
		tmp = l;
		for(int x=9;x>=0;x--){
			tmp /= 10;
			a += tmp*10 + digit[x];
		}
		
		tmp = r; p = 9; tmp = r;
		fill(digit, digit+10, 0);
		
		while(tmp > 0){
			digit[p--] = tmp%10;
			tmp /= 10;
		}
		
		tmp = r;
		for(int x=9;x>=0;x--){			
			tmp /= 10;
			b += tmp*10 + digit[x];
		}
		
		cout << b-a << "\n";
	}
	
    return 0;
}



