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

ll merge(int data[], int tmp[], int left, int mid, int right){
	int x = left, y = mid+1, z = left;
	ll ans = 0;
	while(x <= mid && y <= right){
		if(data[x] <= data[y]){
			tmp[z++] = data[x++];
		} else {
			tmp[z++] = data[y++];
			ans += (mid-x+1);
		}
	}
	
	while(x <= mid) tmp[z++] = data[x++];
	while(y <= right) tmp[z++] = data[y++];
	
	for(int x=left;x<=right;x++){
		data[x] = tmp[x];
	}
	
	return ans;
}

ll solve(int data[], int tmp[], int left, int right){
	ll ans = 0;
	if(left < right){
		int mid = (left+right) >> 1;
		
		ans += solve(data, tmp, left, mid);
		ans += solve(data, tmp, mid+1, right);
		
		ans += merge(data, tmp, left, mid, right);
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	int data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	int tmp[n], tmp2[n];
	for(int x=0;x<n;x++){
		tmp[x] = data[x];
	}
	
	ll prv = solve(tmp, tmp2, 0, n-1), ans = 0;
	for(int i=31;i>=0;i--){
		ll bit = (1 << i);
		
		for(int x=0;x<n;x++){
			tmp[x] = (data[x]^bit);
		}
		
		ll cnt = solve(tmp, tmp2, 0, n-1);
		if(cnt < prv){
			prv = cnt;
			ans += bit;
			
			for(int x=0;x<n;x++){
				data[x]^=bit;
			}
		}
	}
	
	cout << prv << " " << ans << "\n";
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

