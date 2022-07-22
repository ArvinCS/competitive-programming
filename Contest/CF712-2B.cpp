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
		
		string a, b;
		cin >> a >> b;
		
		bool can[n];
		int zero = 0, one = 0;
		for(int x=0;x<n;x++){
			if(a[x] == '1') one++;
			else zero++;
			
			if(one == zero){
				can[x] = true;
			} else {
				can[x] = false;
			}
		}
		
		bool possible = true;
		int inv = 0;
		for(int x=n-1;x>=0;x--){
			int digitA = (a[x] - '0'), digitB = (b[x] - '0');
			if((digitA+inv)%2 != digitB){
				if(can[x]){
					inv++;
				} else {
					possible = false;
					break;
				}
			}
		}
		
		if(possible){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

