#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

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
		
		if(a[0] == a[n-1]){
			cout << "-1\n";
			continue;
		}
		
		int ans = 0;
		for(int x=1;x<n;x++){
			if(a[x] > a[0]){
				if(ans == 0){
					ans = a[x]-a[0];
				}
				ans = __gcd(ans, a[x]-a[0]);
			}
		}
		
		cout << ans << "\n";
	}

    return 0;
}

