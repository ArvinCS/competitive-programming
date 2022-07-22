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
		
		sort(a, a+n);
		
		if((n == 1 && a[0] == 1) || (n > 1 && a[n-1]-a[n-2] <= 1)){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	
    return 0;
}

