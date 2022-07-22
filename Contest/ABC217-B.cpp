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

string r[4] = {"ARC", "ABC", "AHC", "AGC"};

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	string s[3];
	for(int x=0;x<3;x++) cin >> s[x];
	
	for(int x=0;x<4;x++){
		bool found = false;
		for(int y=0;y<3;y++){
			if(s[y] == r[x]){
				found = true;
			}
		}
		
		if(!found){
			cout << r[x] << "\n";
			break;
		}
	}
	
    return 0;
}

