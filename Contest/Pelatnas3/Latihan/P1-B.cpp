#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxA = 2e5 + 5;

int pos[maxA];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	fill(pos, pos+maxA, -1);
	
	int n;
	ll m;
	cin >> n >> m;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	int nxt[n];
	for(int x=n-1;x>=0;x--){
		nxt[x] = pos[a[x]];
		pos[a[x]] = x;
	}
	
	int cur = 0, lst = n;
	ll cnt = 0;
	while(true){
		cur %= n;
		while(cur < n){
			if(nxt[cur] == -1){
				lst = cur;
				cur = (pos[a[cur]]+1);
				if(cur == n) cnt++;
				break;
			} else {
				lst = cur;
				cur = (nxt[cur]+1);
			}
		}
		
		cnt++;
		if(cur%n == 0) break;
	}
	
	assert(cnt != 0);
	
	vector<int> ans;
	lst = n;
	cur = 0;
	for(int r=0;r<m%cnt;r++){
		cur %= n;
		while(cur < n){
			if(nxt[cur] == -1){
				lst = cur;
				cur = pos[a[cur]]+1;
				break;
			} else {
				lst = cur;
				cur = nxt[cur]+1;
			}
		}
	}
	
	fill(pos, pos+maxA, -1);
	
	for(int x=lst;x<n;x++){
		if(pos[a[x]] != -1){
			while(ans.size() > pos[a[x]]){
				pos[ans.back()] = -1;
				ans.pop_back();
			}
		} else {
			ans.push_back(a[x]);
			pos[a[x]] = ans.size()-1;
		}
	}
	
	if(ans.empty()){
		cout << "-1\n";
		return 0;
	}
	
	for(int x=0;x<ans.size();x++){
		if(x > 0) cout << " ";
		cout << ans[x];
	}
	cout << "\n";
    return 0;
}

