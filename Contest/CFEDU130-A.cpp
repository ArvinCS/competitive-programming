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
		int n, m;
		cin >> n >> m;
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		int sum = 0;
		for(int x=0;x<n;x++){
			sum += a[x];
		}
		
		if(sum <= m){
			cout << "0\n";
		} else {
			cout << sum-m << "\n";
		}
	}
	
    return 0;
}

