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
		string a, b;
		cin >> a >> b;
		
		int pos[26];
		for(int x=0;x<a.length();x++){
			pos[(a[x] - 'a')] = x;
		}
		
		int ans = 0;
		for(int x=1;x<b.length();x++){
			ans += abs(pos[(b[x] - 'a')] - pos[(b[x-1] - 'a')]);
		}
		cout << ans << "\n";
	}
	
    return 0;
}

