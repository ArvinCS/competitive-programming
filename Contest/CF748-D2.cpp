#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxA = 2e6 + 5;


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

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
		
		int cur = 1, mx = 0;
		for(int x=1;x<n;x++){
			if(a[x-1] == a[x]){
				cur++;
			} else {
				mx = max(mx, cur);
				cur = 1;
			}
		}
		mx = max(mx, cur);
		
		if(mx >= n/2){
			cout << "-1\n";
			continue;
		}
		
		int ans = 0;
		for(int x=0;x<=n/2;x++){
			vector<int> w;
			vector<int> v;
			
			for(int y=x;y<n;y++){
				int val = a[y]-a[x];
				w.push_back(val);
				for(int z=1;z*z<=val;z++){
					if(val%z == 0){
						v.push_back(z);
						if(val/z != z) v.push_back(val/z);
					}
				}
			}
			
			for(int y=0;y<v.size();y++){
				int cur = 0;
				for(int z=0;z<w.size();z++){
					if(w[z]%v[y] == 0){
						cur++;
					}
				}
				
				if(cur >= n/2){
					ans = max(ans, v[y]);
				}
			}
		}
		
		cout << ans << "\n";
	}

    return 0;
}

