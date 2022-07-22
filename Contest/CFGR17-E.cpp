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
		
		ll a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		int ans = n;
		for(int x=0;x<n;x++){
			int left = x+1, right = n-1, pos = 0;
			while(left <= right){
				int mid = (left+right) >> 1;
				
				if((a[mid]+a[mid-1]+a[x]) > 3*a[x] && (a[mid]+a[mid-1]+a[x]) < 3*a[mid-1]){
					cout << x << " " << mid << " <-\n";
					right = mid-1;
				} else {
					cout << x << " " << mid << " ->\n";
					pos = mid;
					left = mid+1;
				}
			}
			
			ans = min(ans, n-(pos-x+1));
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

