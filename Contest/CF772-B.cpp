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
		
		int ans = 0;
		for(int x=2;x+2<n;x++){
			if(a[x-2] < a[x-1] && a[x-1] > a[x] && a[x] < a[x+1] && a[x+1] > a[x+2]){
				a[x] = max(a[x-1], a[x+1]);
				ans++;
			}
		}
		for(int x=1;x+1<n;x++){
			if(a[x-1] < a[x] && a[x] > a[x+1]){
				a[x] = max(a[x-1], a[x+1]);
				ans++;
			}
		}
		
		cout << ans << "\n";
		for(int x=0;x<n;x++){
			if(x > 0) cout << " ";
			cout << a[x];
		}
		cout << "\n";
	}
	
    return 0;
}

