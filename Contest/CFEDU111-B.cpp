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
		int n, a, b;
		cin >> n >> a >> b;
		
		string s;
		cin >> s;
		
		if(b >= 0){
			cout << (a+b)*n << "\n";
		} else {
			vector<int> zero, one;
			int cnt1 = 0, cnt2 = 0;
			
			int prv = 0;
			for(int x=0;x+1<n;x++){
				if(s[x] != s[x+1]){
					if(s[x] == '0') zero.push_back(x-prv+1);
					else one.push_back(x-prv+1);
					prv = x+1;
				}
			}
			
			if(s[n-1] == '0') zero.push_back(n-prv);
			else one.push_back(n-prv);
			
			int best1 = 0, best2 = 0;
			int remain = n;
			for(int x=0;x<zero.size();x++){
				best1 += zero[x]*a + b;
				remain -= zero[x];
			}
			best1 += remain*a + b;
			
			remain = n;
			for(int x=0;x<one.size();x++){
				best2 += one[x]*a + b;
				remain -= one[x];
			}
			best2 += remain*a+b;
			
			cout << max(best1, best2) << "\n";
 		}
	}
	
    return 0;
}

