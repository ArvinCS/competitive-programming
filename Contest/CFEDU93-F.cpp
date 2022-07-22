#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e6 + 5;

int ans[maxN];
vector<int> pending[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	fill(ans, ans+n, 0);
	
	stack<int> st;
	for(int x=n-1;x>=0;x--){
		st.push(x);
	}
	
	int last[2];
	last[0] = last[1] = -1;
	
	for(int x=0;x<n;x++){
		if(!pending[x].empty()) reverse(pending[x].begin(), pending[x].end());
		while(!pending[x].empty()){
			st.push(pending[x].back());
			pending[x].pop_back();
		}
		
		int mx = 0;
		if(s[x] == '?'){
			mx = max(x-last[0]-1, x-last[1]-1);
		} else {
			mx = x-last[(s[x] - '0')^1]-1;
		}
		
		while(!st.empty() && st.top() <= mx){
			ans[st.top()]++;
			if(x+st.top()+1 < n) pending[x+st.top()+1].push_back(st.top());
			st.pop();
		}
		
		if(s[x] == '0'){
			last[0] = x;
		} else if(s[x] == '1'){
			last[1] = x;
		}
	}
	
	for(int x=0;x<n;x++){
		if(x > 0) cout << " ";
		cout << ans[x];
	}
	cout << "\n";
    return 0;
}

