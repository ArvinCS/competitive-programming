#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
		a[x]--;
	}
	
	int b[n];
	for(int x=0;x<n;x++){
		cin >> b[x];
		b[x]--;
	}
	
	int pos[n];
	for(int x=0;x<n;x++){
		pos[b[x]] = x;
	}
	
	vector<pair<int, int>> ans;
	auto solve = [&](auto self, int l, int r) -> void {
		int m = (l+r) >> 1;
		
		
		
		// seg l < seg r (n/2)?
		// seg l > seg r (n/2)?
		
		if(mn-l <= r-mn){
			
		} else {
			
		}
	};
	
	cout << ans.size() << "\n";
	for(auto p : ans){
		cout << p.first+1 << " " << p.second+1 << "\n";
	}
    return 0;
}

