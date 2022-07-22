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
		
		ll sum = 0;
		for(int x=0;x<n-1;x++){
			sum += a[x];
		}
		
		if(a[n-1] == 0){
			cout << "0\n";
			continue;
		}
		
		cout << max(1ll, a[n-1]-sum) << "\n";
	}
	
    return 0;
}

