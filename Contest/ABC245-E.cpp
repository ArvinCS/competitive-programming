#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	pair<int, int> p[n], q[m];
	for(int x=0;x<n;x++){
		cin >> p[x].first;
	}
	for(int x=0;x<n;x++){
		cin >> p[x].second;
	}
	for(int x=0;x<m;x++){
		cin >> q[x].first;
	}
	for(int x=0;x<m;x++){
		cin >> q[x].second;
	}
	
	sort(p, p+n);
	sort(q, q+m);
	
	multiset<int> st;
	bool valid = true;
	int pos = 0;
	for(int x=0;x<m;x++){
		while(pos < n && p[pos].first <= q[x].first){
			st.insert(p[pos].second);
			pos++;
		}
		
		auto it = st.lower_bound(q[x].second+1);
		if(it != st.begin()){
			it--;
			st.erase(it);
		}
	}
	
	cout << (st.empty() && pos == n ? "Yes" : "No") << "\n";
    return 0;
}

