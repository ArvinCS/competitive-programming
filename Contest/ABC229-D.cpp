#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	string s;
	cin >> s;
	
	int k;
	cin >> k;
	
	int n = s.length();
	int prefix[n];
	for(int x=0;x<n;x++){
		prefix[x] = (s[x] == '.') + (x > 0 ? prefix[x-1] : 0);
	}
	
	int left = 1, right = n, ans = 0;
	while(left <= right){
		int mid = (left+right) >> 1;
		
		bool possible = false;
		for(int x=0;x+mid<=n;x++){
			if(prefix[x+mid-1] - (x > 0 ? prefix[x-1] : 0) <= k){
				possible = true;
				break;
			}
		}
		
		if(possible){
			ans = max(ans, mid);
			left = mid+1;
		} else {
			right = mid-1;
		}
	}
	
	cout << ans << "\n";
    return 0;
}

