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
		
		map<ll, int> mp;
		ll a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		// -4 -3 -2 -1 1 2 3 4
		
		sort(a, a+n);
		
		bool zero = false;
		int cnt = 0, cnt2 = 0;
		for(int x=0;x<n;x++){
			if(a[x] == 0){
				zero = true;
				continue;
			}
			if(mp[-a[x]] > 0){
				mp[-a[x]]--;
				cnt2--;
				cnt++;
			} else {
				cnt2++;
				mp[a[x]]++;
			}
		}
		
		ll sum = 0;
		for(int x=0;x<n;x++){
			sum += a[x];
		}
		
		bool possible = false;
		if(cnt2 <= 1-zero && cnt <= 1){
			possible = true;
		}
		if(cnt == 2 && cnt2 == 0 && !zero){
			possible = true;
		}
		if(cnt2 == 1 && cnt == 0){
			possible = true;
		}
		
		cout << (possible ? "YES" : "NO") << "\n";
	}
    return 0;
}

