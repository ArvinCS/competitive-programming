#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	ll a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	int ans = 0;
	set<pair<int, int>> st;
	for(int i=0;i<2;i++){
		ll prefix[n];
		prefix[0] = a[0];
		for(int x=1;x<n;x++){
			prefix[x] = a[x] + prefix[x-1];
		}
		
		auto get = [&](int l, int r) -> ll {
			return prefix[r] - (l > 0 ? prefix[l-1] : 0);
		};
		
		for(int x=0;x<n;x++){
			int lg = log2(a[x])+1;
			for(int y=x+2;y<n;y++){
				if(get(x+1, y-1) < (1 << lg)){
					if(get(x, y) == 2*(a[x]|a[y]) && !st.count({(i == 1 ? n-1-x : x), (i == 1 ? n-1-y : y)})){
						st.insert({(i == 1 ? n-1-x : x), (i == 1 ? n-1-y : y)});
						st.insert({(i == 1 ? n-1-y : y), (i == 1 ? n-1-x : x)});
						ans++;
					}
				} else {
					break;
				}
			}
		}
		
		reverse(a, a+n);
	}
	
	cout << ans << "\n";
    return 0;
}
