#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	pair<string, int> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
	}
	
	int mx = 0;
	set<string> st;
	for(int x=0;x<n;x++){
		if(st.count(p[x].first)) continue;
		st.insert(p[x].first);
		
		mx = max(mx, p[x].second);
	}
	
	st.clear();
	
	int ans = -1;
	for(int x=0;x<n;x++){
		if(st.count(p[x].first)) continue;
		st.insert(p[x].first);
		
		if(p[x].second == mx){
			ans = x;
			break;
		}
	}
	
	cout << ans+1 << "\n";
    return 0;
}

