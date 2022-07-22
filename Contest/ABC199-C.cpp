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
	
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	int q;
	cin >> q;
	
	bool flip = false;
	for(int i=1;i<=q;i++){
		int t, a, b;
		cin >> t >> a >> b;
		
		if(t == 1){
			if(flip){
				swap(s[(n+a-1)%(2*n)], s[(n+b-1)%(2*n)]);
			} else {
				swap(s[a-1], s[b-1]);
			}
		} else {
			flip = !flip;
		}
	}
	
	if(flip){
		for(int x=n;x<2*n;x++) cout << s[x];
		for(int x=0;x<n;x++) cout << s[x];
		cout << "\n";
	} else {
		cout << s << "\n";
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

