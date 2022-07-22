#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	// for 1 <= i <= c, i > k, useless
	
	int n;
	ll c, k;
	cin >> n >> c >> k;
	
	ll l[n];
	for(int x=0;x<n;x++){
		cin >> l[x];
	}
	
	sort(l, l+n);
	
	if(c == 0){
		cout << fixed << setprecision(9) << l[n-k] << "\n";
		return 0;		
	}
	
	double left = 0, right = l[n-1];
	for(int i=0;i<200;i++){
		double mid = (left+right)*0.5;
		
		ll cnt = 0;
		for(int x=0;x<n;x++){
			if(l[x] < mid){
				continue;
			}
			
			ll tmp = floor(l[x]*1.0/mid);
			cnt += tmp;
		}
		
//		cout << mid << " -> " << cnt << "\n";
		
		if(cnt >= k){
			left = mid;
		} else {
			right = mid;
		}
	}
	
	cout << fixed << setprecision(9) << left << "\n";
    return 0;
}

