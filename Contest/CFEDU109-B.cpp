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
		
		bool ascend = true;
		for(int x=0;x<n;x++){
			if(data[x]-1 != x){
				ascend = false;
				break;
			}
		}
		
		if(ascend){
			cout << "0\n";
			continue;
		}
		
		if(data[0] != 1 && data[n-1] != n){
			if(data[0] == n && data[n-1] == 1){
				cout << "3\n";
			} else {
				cout << "2\n";
			}
		} else {
			cout << "1\n";
		}
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

