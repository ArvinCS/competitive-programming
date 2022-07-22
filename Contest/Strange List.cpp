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
		int n, m;
		cin >> n >> m;
		
		ull sum = 0;
		int data[n], tmp[n];
		
		for(int x=0;x<n;x++){
			cin >> data[x];
			tmp[x] = data[x];
			
			sum += data[x];
		}
		
		bool valid = true;
		while(valid){
			for(int x=0;x<n;x++){
				if(tmp[x]%m == 0){
					sum += data[x];
					tmp[x] /= m;
				} else {
					valid = false;
					break;
				}
			}
		}
		cout << sum << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

