#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		ll data[n];
		for(int x=0;x<n;x++){
			cin >> data[x];
		}
		
		sort(data, data+n);
		
		vector<int> cnt;
		int same = 1;
		for(int x=1;x<n;x++){
			if(data[x-1] != data[x]){
				cnt.push_back(same);
				same = 0;
			}
			same++;
			
			if(x == n-1){
				cnt.push_back(same);
			}
		}
		
		if(n == 1){
			cnt.push_back(1);
		}
		
		sort(cnt.begin(), cnt.end());
		
		ll prefix[cnt.size()];
		prefix[0] = cnt[0];
		for(int x=1;x<cnt.size();x++){
			prefix[x] = prefix[x-1] + cnt[x];
		}
		
		ll ans = inf_ll;	
		ll maxC = cnt.back();
		for(int c=1;c<=maxC;c++){
			int boundleft = -1, boundright = -1;
			int left = 0, right = cnt.size()-1;
			
			while(left <= right){
				int mid = (left+right)/2;
				
				if(cnt[mid] == c){
					right = mid-1;
					boundleft = mid;
				} else if(cnt[mid] < c){
					left = mid+1;
				} else {
					right = mid-1;
				}
			}
			
			left = 0, right = cnt.size()-1;
			while(left <= right){
				int mid = (left+right)/2;
				
				if(cnt[mid] == c){
					left = mid+1;
					boundright = mid;
				} else if(cnt[mid] < c){
					left = mid+1;
				} else {
					right = mid-1;
				}
			}
			
			ll tmp = inf_int;
			if(boundleft != -1 && boundright != -1){
				tmp = (boundleft > 0 ? prefix[boundleft-1] : 0) + (prefix[cnt.size()-1] - prefix[boundright]) - c*(cnt.size()-boundright-1);
			}
			
//			cout << c << " -> " << boundleft << " " << boundright << "\n";
			ans = min(ans, tmp);
			if(ans == 0) break;
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

