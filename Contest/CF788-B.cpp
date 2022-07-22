#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		string s;
		cin >> s;
		
		int k;
		cin >> k;
		
		bool c[26];
		fill(c, c+26, false);
		
		for(int x=0;x<k;x++){
			char val;
			cin >> val;
			
			c[(val - 'a')] = true;
		}
		
		int idx[n];
		fill(idx, idx+n, 1e9);
		
		int mn = n;
		for(int x=n-1;x>=0;x--){
			if(mn != n){
				idx[x] = mn-x;
			}
			if(c[(s[x] - 'a')]){
				mn = x;
			}
		}
		
		int mx = 0;
		for(int x=0;x<n;x++){
			if(idx[x] != 1e9){
				mx = max(mx, idx[x]);
			}
		}
		
		cout << mx << "\n";
	}
	
    return 0;
}

