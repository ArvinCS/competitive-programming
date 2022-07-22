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

const int maxN = 1e5 + 2;

short eco[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	eco[0] = 1;
	
	int zero = 0;
	for(ll x=1;x<n;x++){
		cin >> eco[x];
		if(eco[x] == 0){
			zero = x;
		}
	}
	
	if(n == 2 || zero <= 1){
		cout << "1\n";
	} else {
		if(eco[n-1] == 1){
			cout << "2\n";
		} else {
			int last = n-1;
			for(int x=n-2;x>=0;x--){
				if(eco[x]&1){
					last = x;
					break;
				}
			}
			
			cout << n-last-(last == 0) << "\n";
		}
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

