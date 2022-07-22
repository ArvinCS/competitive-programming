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
		int n, k;
		cin >> n >> k;
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		sort(a, a+n);
		
		vector<int> v, w;
		v.push_back(a[0]);
		
		for(int x=1;x<n;x++){
			if(a[x] != a[x-1]){
				v.push_back(a[x]);
			} else {
				w.push_back(a[x]);
			}
		}
		
		int cnt = v.size();
		int ans = cnt-min(k, cnt-1);
		int need = 0;
		
		int pos = 0;
		for(int x=0;x<=n;x++){
			need++;
			while(pos < v.size() && v[pos] <= x){
				pos++;
				need--;
			}
			
			if(k >= need){
				int mn = min(cnt-pos, need);
				int remain = need-mn;
				
				if(w.size() >= remain){
					ans = min(ans, cnt+remain-(x+1)-min(k-need, cnt-pos-mn));	
				}
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

