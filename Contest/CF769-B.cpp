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
		
		vector<int> ans;
		
		int lg = log2(n-1);
		for(int x=n-1;x>=1;x--){
			ans.push_back(x);
			if(x == (1 << lg)){
				ans.push_back(0);
			}
		}
		for(int x=0;x<n;x++){
			if(x > 0) cout << " ";
			cout << ans[x];
		}
		cout << "\n";
	}
	
    return 0;
}

