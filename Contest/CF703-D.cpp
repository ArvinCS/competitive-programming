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

const int maxN = 2e5 + 5;

int data[maxN], n, k;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> n >> k;
	
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	int left = 1, right = n, ans = 0;
	while(left <= right){
		int mid = (left+right) >> 1;
		
		int prefix[n];
		for(int x=0;x<n;x++){
			prefix[x] = (x > 0 ? prefix[x-1] : 0);
			if(data[x] >= mid){
				prefix[x]++;
			} else {
				prefix[x]--;
			}
		}
		
		int mn = 0, mx = -inf_int;
		for(int x=0;x<n;x++){
			if(x-k >= 0) mn = min(mn, prefix[x-k]);
			if(x >= k-1) mx = max(mx, prefix[x]-mn);
		}
		
//		cout << mid << " -> " << mx << "\n";
		
		if(mx > 0){
			ans = max(ans, mid);
			left = mid+1;
		} else {
			right = mid-1;
		}
	}
	
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

