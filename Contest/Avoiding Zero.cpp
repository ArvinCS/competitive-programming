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
		us n;
		cin >> n;
		
		short data[n], total = 0;
		
		bool allZero = true;
		for(us x=0;x<n;x++){
			cin >> data[x];
			if(data[x] != 0) allZero = false;
		}
		
		sort(data, data+n);
		
		vector<short> ans;
		int left = 0, right = n-1;
		while(left <= right){
			if(total + data[right] != 0){
				ans.push_back(data[right]);
				total += data[right--];
			} else if(total + data[left] != 0){
				ans.push_back(data[left]);
				total += data[left++];
			} else {
				break;
			}
		}
		
		if(ans.size() == n && !allZero){
			cout << "YES\n";
			for(short x=0;x<n;x++){
				if(x > 0) cout << " ";
				cout << ans[x];
			}
			cout << "\n";
		} else {
			cout << "NO\n";
		}
	}
	
    return 0;
}

