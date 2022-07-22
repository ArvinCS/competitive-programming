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
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		sort(a, a+n);
		
		ll ans[n+1];
		fill(ans, ans+n+1, -1);
		
		stack<int> st;
		int pos = 0, mx = -1;
		ll prv = 0;
		for(int x=0;x<=n;x++){
			while(pos < n && a[pos] < x){
				if(a[pos] > mx){
					st.push(a[pos]);
				}
				pos++;
			}
			
			ll cnt = prv;
			while(!st.empty() && mx+1 <= x-1){
				cnt += mx+1-st.top();
				st.pop();
				mx++;
			}
			
			if(mx < x-1){
				break;
			}
			
			prv = cnt;
			while(pos < n && a[pos] <= x){
				if(a[pos] > mx){
					st.push(a[pos]);
				}
				pos++;
				cnt++;
			}
			
			ans[x] = cnt;
			mx = max(mx, x-1);
		}
		
		for(int x=0;x<=n;x++){
			if(x > 0) cout << " ";
			cout << ans[x];
		}
		cout << "\n";
	}
	
    return 0;
}

