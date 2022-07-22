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
		int n, m, k;
		cin >> n >> m >> k;
		
		if(m < n-1 || m > n*1ll*(n-1)/2){
			cout << "NO\n";
			continue;
		}
		
		k -= 2;
		if(k < 0){
			cout << "NO\n";
			continue;
		}
		if(n == 1 && m == 0 && k >= 0){
			cout << "YES\n";
			continue;
		}
		if(m == n*1ll*(n-1)/2 && k >= 1){
			cout << "YES\n";
			continue;
		}
		if(k >= 2){
			cout << "YES\n";
			continue;
		}
		
		cout << "NO\n";
	}
	
    return 0;
}

