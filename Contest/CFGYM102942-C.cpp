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
	
	us t;
	cin >> t;
	
	while(t--){
		int n, k;
		cin >> n >> k;
		
		int data[n];
		for(int x=0;x<n;x++){
			cin >> data[x];
		}
		
		sort(data, data+n);
		
		int left = 0, right = n-1, ans = 0;
		while(left <= right){
			if(data[right] >= k){
				right--;
				ans++;
				continue;
			}
			if(data[left] >= k){
				left++;
				ans++;
				continue;
			}
			if(left == right) break;
			if(data[left]+data[right] >= k){
				ans++;
				left++;
				right--;
			} else {
				left++;
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

