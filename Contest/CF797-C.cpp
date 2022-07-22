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
		
		int s[n], f[n];
		for(int x=0;x<n;x++){
			cin >> s[x];
		}
		for(int x=0;x<n;x++){
			cin >> f[x];
		}
		
		int cur = 0;
		for(int x=0;x<n;x++){
			cur = max(cur, s[x]);
			
			if(x > 0) cout << " ";
			cout << f[x]-cur;
			
			cur = f[x];
		}
		cout << "\n";
	}
	
    return 0;
}

