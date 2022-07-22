#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	ll a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	stack<int> st;
	st.push(n-1);
	for(int x=n-2;x>=k;x--){
		while(!st.empty() && a[st.top()] <= a[x]){
			st.pop();
		}
		st.push(x);
	}
	
	vector<pair<int, int>> v;
	for(int x=0;x<k;x++){
		v.push_back({a[x], x});
	}
	
	sort(v.begin(), v.end());
	
	int ans = 1e9;
	for(int x=0;x<k;x++){
		while(!st.empty() && a[st.top()] <= v[x].first){
			st.pop();
		}
		
		if(!st.empty()){
			ans = min(ans, st.top()-v[x].second);
		}
	}
	
	cout << (ans == 1e9 ? -1 : ans) << "\n";
    return 0;
}

