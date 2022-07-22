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
		
		int ans = 0;
		set<int> st;
		for(int x=1;x*x*x<=n;x++){
			st.insert(x*x*x);
			ans++;
		}
		for(int x=1;x*x<=n;x++){
			if(!st.count(x*x)){
				st.insert(x*x);
				ans++;
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

