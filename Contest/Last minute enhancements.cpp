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
		int n;
		cin >> n;
		
		int data[n];
		for(int x=0;x<n;x++) cin >> data[x];
		
		sort(data, data+n);
		
		unordered_set<int> s;
		
		data[n-1]++;
		for(int x=n-2;x>0;x--){
			if(data[x+1]-data[x] > 1){
				data[x]++;
			}
		}
		
		int ans = (n == 1);
		for(int x=0;x<n-1;x++){
			if(data[x] != data[x+1]){
				ans++;
			}
		}
		if(n > 1 && data[n-1] != data[n-2]) ans++;
		
		cout << ans << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

