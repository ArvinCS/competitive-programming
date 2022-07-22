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
		
		int ans = 1;
		int m = n/2;
		
		for(int l=m-1;l>=0;l--){
			if(s[l] == s[m]) ans++;
			else break;
		}
		for(int r=m+1;r<n;r++){
			if(s[r] == s[m]) ans++;
			else break;
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

