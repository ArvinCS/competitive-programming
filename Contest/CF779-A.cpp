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
		
		int ans = 0, last = -1;
		for(int x=0;x<n;x++){
			if(s[x] == '0'){
				if(last != -1 && x-last-1 <= 1){
					ans += 2-(x-last-1);
				}
				
				last = x;
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

