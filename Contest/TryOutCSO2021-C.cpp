#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
		
	int n;
	cin >> n;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	sort(a, a+n);
	
	int q;
	cin >> q;
	
	while(q--){
		int val;
		cin >> val;
		
		int left = 0, right = n-1, ans = -1;
		while(left <= right){
			int mid = (left+right) >> 1;
			
			if(a[mid] <= val){
				ans = max(ans, mid);
				left = mid+1;
			} else {
				right = mid-1;
			}
		}
		
		cout << ans+1 << "\n";
	}
	return 0;
}
