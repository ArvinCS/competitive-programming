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
		
		int data[n];
		for(int x=0;x<n;x++){
			cin >> data[x];
		}
		
		bool valid = false;
		for(int x=0;x<n;x++){
			int tmp = sqrt(data[x]);
			if(tmp*tmp != data[x]){
				valid = true;
				break;
			}
		}
		
		if(valid) cout << "YES\n";
		else cout << "NO\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

