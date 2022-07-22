#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	pair<ll, ll> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
	}
	
	double ans[n];
	ans[0] = p[0].second;
	
	// X2^2 + X1^2 - 2X2X1 = 4r1r2
	// (X2^2 + X1^2 - 2X2X1)/4r1 = r2
	// (X1^2 - 2X2X1)/4r1 = r2 - (X2^2)/4r1
	
	stack<int> st;
	st.push(0);
	for(int x=1;x<n;x++){
		double mn = p[x].second*1.0;
		
		while(!st.empty()){
			int idx = st.top();
			
			mn = min(mn, (p[idx].first-p[x].first)*(p[idx].first-p[x].first)*1.0/(4*ans[idx]));
			
			if(mn > ans[idx]-(1e-9)){
				st.pop();
			} else {
				break;
			}
		}
		
		ans[x] = mn;
		st.push(x);
	}
	
	for(int x=0;x<n;x++){
		cout << fixed << setprecision(5) << ans[x] << "\n";
	}
    return 0;
}
