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
	
	short t;
	cin >> t;
	
	while(t--){
		short n;
		cin >> n;
		
		bool digits[10];
		fill(digits, digits+10, false);
		
		stack<int> ans;
		while(n > 0){
			int before = n;
			for(short x=9;x>0;x--){
				if(digits[x]) continue;
				if(n-x < 0) continue;
				
				ans.push(x);
				n -= x;
				digits[x] = true;
				
				break;
			}
			if(before == n) break;
		}
		
		if(n != 0){
			cout << "-1\n";
		} else {
			while(!ans.empty()){
				cout << ans.top();
				ans.pop();
			}
			cout << "\n";
		}
	}
	
    return 0;
}

