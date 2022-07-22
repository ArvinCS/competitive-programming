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
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		bool possible = true;
		int odd = 0, even = 0;
		for(int x=0;x<n;x++){
			if(a[x]&1){
				possible &= (odd <= a[x]);
				odd = max(odd, a[x]);
			} else {
				possible &= (even <= a[x]);
				even = max(even, a[x]);
			}
		}
		
		cout << (possible ? "Yes" : "No") << "\n";
	}
	
    return 0;
}

