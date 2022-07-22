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
		string s;
		cin >> s;
		
		char c = 'z';
		for(int x=0;x<s.length();x++){
			if(s[x] < c){
				c = s[x];
			}
		}
		
		string a, b;
		for(int x=0;x<s.length();x++){
			if(s[x] == c && a.length() == 0){
				a.push_back(s[x]);
			} else {
				b.push_back(s[x]);
			}
		}
		
		cout << a << " " << b << "\n";
	}

    return 0;
}

