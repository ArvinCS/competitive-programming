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
	
	int n;
	cin >> n;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	int diff[n];
	diff[0] = 0;
	
	ll sum = 0;
	for(int x=1;x<n;x++){
		diff[x] = a[x]-a[x-1];
		sum += max(diff[x], 0);
	}
	
	ll left = -inf_ll, right = inf_ll, ans = inf_ll;
	while(left <= right){
		ll mid = (left+right) >> 1;
		
		ll cnt = a[0]-mid+sum;
		if(cnt < a[])
	}
	
	
	int q;
	cin >> q;
	
	for(int i=1;i<=q;i++){
		int l, r, val;
		cin >> l >> r >> val;
		
		l--; r--;
		
	}
    return 0;
}

