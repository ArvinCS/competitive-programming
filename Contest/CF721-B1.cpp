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
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		string s;
		cin >> s;
		
		int zero = 0;
		for(int x=0;x<n;x++){
			if(s[x] == '0') zero++;
		}
		
		if(zero == 0){
			cout << "DRAW\n";
			continue;
		}
		if(zero == 1){
			cout << "BOB\n";
			continue;
		}
		
		if(n > 1 && (n%2==1) && s[n/2] == '0'){
			zero--;
			if(zero == 1 || zero % 4 == 3){
				cout << "DRAW\n";
			} else {
				cout << "ALICE\n";
			}
		} else {
			cout << "BOB\n";
		}
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

