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
	
	short t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int data[n];
		for(int x=0;x<n;x++){
			cin >> data[x];
		}
		
		vector<int> ans;
		int left = 0, right = n-1;
		while(left <= right){
			ans.push_back(data[left++]);
			if(left < right) ans.push_back(data[right--]);
		}
		
		for(int x=0;x<n;x++){
			if(x > 0) cout << " ";
			cout << ans[x];
		}
		cout << "\n";
	}
	
    return 0;
}

