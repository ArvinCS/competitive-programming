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
		int n;
		cin >> n;
		
		int data[2*n];
		for(int x=0;x<2*n;x++){
			cin >> data[x];
		}
		
		sort(data, data+2*n);
		
		int p1 = 0, p2 = n;
		int ans[2*n];
		for(int x=0;x<2*n;x++){
			if(x%2 == 0){
				ans[x] = data[p1++];
			} else {
				ans[x] = data[p2++];
			}
		}
		
		for(int x=0;x<2*n;x++){
			if(x > 0) cout << " ";
			cout << ans[x];
		}
		cout << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

