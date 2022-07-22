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
		
		reverse(a, a+n);
		
		if(a[0] != n && a[n-1] != n){
			cout << "-1\n";
		} else {
			for(int x=0;x<n;x++){
				if(x > 0) cout << " ";
				cout << a[x];
			}
			cout << "\n";
		}
	}
	return 0;
}

