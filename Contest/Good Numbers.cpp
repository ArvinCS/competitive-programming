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

const int sz = 1e7;

ull pw[41];
ll curA = 0, curB = 0;

ull a[sz], b[sz];

void sub(ull index, ull cur, ull mx, bool useA){
	if(index == mx){
		if(useA) a[curA++] = cur;
		else b[curB++] = cur;
		return;
	}
	
	sub(index+1, cur+pw[index], mx, useA);
	sub(index+1, cur, mx, useA);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	pw[0] = 1;
	for(int x=1;x<=40;x++){
		pw[x] = 3*pw[x-1];
	}
	
	sub(0,0,17,true);
	sub(17,0,39,false);
	
	sort(a, a+curA);
	sort(b, b+curB);
	
	int q;
	cin >> q;
	
	while(q--){
		ull n;
		cin >> n;
		
		ull ans = 1e19;

		for(ll x=0;x<curA;x++){
			if(a[x] >= ans) break;
			auto it = lower_bound(b, b+curB, n > a[x] ? n-a[x] : 0);
			if(it-b == curB) it--;
			if(a[x]+*it >= n){
				ans = min(ans, a[x]+*it);
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

