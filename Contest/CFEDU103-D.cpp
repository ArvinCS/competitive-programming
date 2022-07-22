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
		int n;
		cin >> n;
		
		string s;
		cin >> s;
		
		int a[n+1], b[n+1];
		fill(a, a+n+1, 0);
		fill(b, b+n+1, 0);
		
		for(int x=0;x<2;x++){
			int cnt = 0;
			for(int y=0;y<n;y++){
				bool ori = (y % 2) ^ x;
				char need = (ori ? 'R' : 'L');
				
				if(s[y] == need){
					cnt++;
				} else {
					cnt = 0;
				}
				
				if(y%2 == x){
					a[y+1] = cnt;
				}
			}
			
			cnt = 0;
			for(int y=n-1;y>=0;y--){
				bool ori = (y % 2 == (n-1) % 2) ^ x;
				char need = (ori ? 'R' : 'L');
				
				if(s[y] == need){
					cnt++;
				} else {
					cnt = 0;
				}
				
				if((y % 2 == (n-1) % 2) != x){
					b[y] = cnt;
				}
			}
		}
		
		for(int x=0;x<=n;x++){
			if(x > 0) cout << " ";
			cout << a[x]+b[x]+1;
		}
		cout << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

