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
		string s;
		cin >> s;
		
		int n = s.length();
		int prefix[n];
		for(int x=0;x<n;x++){
			prefix[x] = (x > 0 ? prefix[x-1] : 0);
			if(s[x] == '1') prefix[x]++;
		}
		
		int ans = 1e9;
		for(int x=0;x<n;x++){			
			int left = x, right = n-1;
			int pos = x;
			while(left <= right){
				int mid = (left+right) >> 1;
				
				int zero = (mid-x+1)-(prefix[mid] - (x > 0 ? prefix[x-1] : 0));
				int one = (x > 0 ? prefix[x-1] : 0) + (prefix[n-1] - prefix[mid]);
				
				if(zero <= one){
					pos = mid;
					left = mid+1;
				} else {
					right = mid-1;
				}
			}
			
			if(pos != -1){
				int zero = (pos-x+1)-(prefix[pos] - (x > 0 ? prefix[x-1] : 0));
				int one = (x > 0 ? prefix[x-1] : 0) + (prefix[n-1] - prefix[pos]);
				
				ans = min(ans, max(zero, one));
			}
		}
		
		if(v.empty() || w.empty()){
			ans = 0;
		}
		
		assert(ans < 1e9);
		
		cout << ans << "\n";
	}
	
    return 0;
}

