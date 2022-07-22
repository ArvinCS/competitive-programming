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
		string a, b;
		cin >> a >> b;
		
		if(a < b){
			cout << a << "\n";
			continue;
		}
		
		int n = a.length();
		char c[n];
		bool found = false;
		for(int x=0;x<n-1;x++){
			if(x >= b.length()) break;
			c[x] = min(a[x], a[x+1]);
		}
		
		for(int x=0;x<n;x++){
			if(a[x] != c[x]){
				for(int y=x+1;y<n;y++){
					if(a[y] == c[y]){
						swap(a[x], a[y]);
						if(a < b){
							found = true;
							break;
						}
						swap(a[x], a[y]);
					}
				}
				if(found) break;
			}
		}
		
		if(found){
			cout << a << "\n";
		} else {
			cout << "---\n";
		}
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

