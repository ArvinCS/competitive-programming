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

	int cnt = 1;
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int data[n-1], less = 0;
		for(int x=0;x<n-1;x++){
			char tmp;
			cin >> tmp;
			
			if(tmp == '>'){
				data[x] = 1;
			} else {
				data[x] = -1;
				less++;
			}
		}	
		
		int a[n], b[n], last = 0;
		
		int cur = n;
		for(int x=0;x<n;x++){
			if(x == n-1 || data[x] == 1){
				for(int y=x;y>=last;y--){
					a[y] = cur--;
				}
				last = x+1;
			}
		}
		
		last = 0;
		cur = 1;
		for(int x=0;x<n;x++){
			if(x == n-1 || data[x] == -1){
				for(int y=x;y>=last;y--){
					b[y] = cur++;
				}
				last = x+1;
			}
		}
		
		for(int x=0;x<n;x++){
			if(x > 0) cout << " ";
			cout << a[x];
		}
		cout << "\n";
		
		for(int x=0;x<n;x++){
			if(x > 0) cout << " ";
			cout << b[x];
		}
		cout << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

