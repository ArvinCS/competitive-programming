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
		int n, d;
		cin >> n >> d;
		
		int data[n];
		for(int x=0;x<n;x++){
			cin >> data[x];
		}
		
		sort(data, data+n);
		
		bool all = true;
		for(int x=0;x<n;x++){
			if(data[x] > d){
				all = false;
				break;
			}
		}
		
		if(all){
			cout << "YES\n";
			continue;
		} else {
			int smallest = data[0] + data[1];
			if(smallest <= d){
				cout << "YES\n";
				continue;
			}
		}
		
		cout << "NO\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

