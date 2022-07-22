#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	pair<int, int> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
	}
	
	set<pair<int, int>> st;
	st.insert(p[0]);
	
	for(int x=1;x<n;x++){
		set<pair<int, int>> new_st;
		
		for(auto q : st){
			pair<int, int> tmp = q;
			tmp.first = __gcd(tmp.first, p[x].first);
			tmp.second = __gcd(tmp.second, p[x].second);
			
			new_st.insert(tmp);
			
			tmp = q;
			tmp.first = __gcd(tmp.first, p[x].second);
			tmp.second = __gcd(tmp.second, p[x].first);
			
			new_st.insert(tmp);
		}
		
		swap(new_st, st);
	}
	
	ll ans = 0;
	for(auto q : st){
		ans = max(ans, (q.first*1ll*q.second)/__gcd(q.first, q.second));
	}
	
	cout << ans << "\n";
    return 0;
}

