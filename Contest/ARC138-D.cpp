#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	vector<int> ans;
	ans.push_back(0);
	
	int mx = (1 << n);
	bool pick[mx];
	fill(pick, pick+mx, false);
	
	pick[0] = true;
	
	bool found = true;
	while(found){
		found = false;
		
		for(int x=1;x<mx;x++){
			int val = (ans.back()+x);
			if(val < mx && !pick[val] && __builtin_popcount(val^ans.back()) == k){
				ans.push_back(val);
				pick[val] = true;
				found = true;
				break;
			}
			
			val = (ans.back()-x);
			if(val >= 0 && !pick[val] && __builtin_popcount(val^ans.back()) == k){
				ans.push_back(val);
				pick[val] = true;
				found = true;
				break;
			}
		}
	}
	
	
	if(ans.size() == mx && __builtin_popcount(ans.back()) == k){
		cout << "Yes\n";
		for(int x=0;x<ans.size();x++){
			if(x > 0) cout << " ";
			cout << ans[x];
		}
		cout << "\n";
	} else {
		cout << "No\n";
	}
    return 0;
}

