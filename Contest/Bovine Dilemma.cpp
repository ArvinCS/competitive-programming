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
		
		bool alas[105];
		fill(alas, alas+105, false);
		
		int data[n];
		for(int x=0;x<n;x++){
			cin >> data[x];
		}
		
		int ans = 0;
		for(int x=0;x<n;x++){
			for(int y=x+1;y<n;y++){
				int panjang = data[y]-data[x];
				if(!alas[panjang]){
					alas[panjang] = true;
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

