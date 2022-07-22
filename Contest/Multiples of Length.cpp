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
	
	ll n;
	cin >> n;
	
	ll data[n];
	for(int x=0;x<n;x++) cin >> data[x];
	
	if(n > 1){
		cout << "1 " << n-1 << "\n";
		for(int x=0;x<n-1;x++){
			if(x > 0) cout << " ";
			
			if(data[x]%n == 0){
				cout << 0;
			} else {
				cout << data[x]*n-data[x];
				data[x] *= n;
			}
		}
		cout << "\n";
		
		cout << "2 " << n << "\n";
		for(int x=1;x<n;x++){
			if(x > 1) cout << " ";
			
			if(data[x]%n == 0){
				cout << 0;
			} else {
				cout << data[x]*n-data[x];
				data[x] *= n;
			}
		}
		cout << "\n";
	} else {
		cout << "1 1\n0\n";
		cout << "1 1\n0\n";	
	}
	
	cout << "1 " << n << "\n";
	for(int x=0;x<n;x++){
		if(x > 0) cout << " ";
		cout << -data[x];
	}
	cout << "\n";
	
    return 0;
}

