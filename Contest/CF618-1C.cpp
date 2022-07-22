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
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	ll a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}

	stack<pair<double, int>> st;
	for(int x=0;x<n;x++){
		st.push({a[x], 1});
		
		while(st.size() > 1){
			pair<double, int> p = st.top();
			st.pop();
			pair<double, int> q = st.top();
			st.pop();
			
			if((p.first*p.second+q.first*q.second) / (p.second+q.second) <= q.first){
				st.push({(p.first*p.second+q.first*q.second) / (p.second+q.second), p.second+q.second});
			} else {
				st.push(q);
				st.push(p);
				break;
			}
		}
	}
	
	vector<double> ans;
	while(!st.empty()){
		pair<double, int> p = st.top();
		st.pop();
		
		for(int x=0;x<p.second;x++){
			ans.push_back(p.first);
		}
	}
	
	reverse(ans.begin(), ans.end());
	
	for(int x=0;x<n;x++){
		cout << fixed << setprecision(10) << ans[x] << "\n";
	}
    return 0;
}

