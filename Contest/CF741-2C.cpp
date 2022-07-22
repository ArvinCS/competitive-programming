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
		
		int a = 0, b = (n-(n%2))-1, c = 0, d = n/2-1;
		for(int x=0;x<n;x++){
			if(s[x] == '0'){
				if(x+(n/2) < n){
					a = x;
					b = x+(n/2);
					c = x+1;
					d = x+(n/2);
				}
				if(x-(n/2) >= 0){
					a = x-(n/2);
					b = x;
					c = x-(n/2);
					d = x-1;
				}
			}
		}
		
		cout << a+1 << " " << b+1 << " " << c+1 << " " << d+1 << "\n";
	}
	
    return 0;
}

