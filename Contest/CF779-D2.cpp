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
		int l, r;
		cin >> l >> r;
		
		int n = r-l+1;
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		sort(a, a+n);
		
		if(r == 0){
			cout << a[0] << "\n";
			continue;
		}
		
		vector<int> z[2];
		for(int x=l;x<=r;x++){
			if(x&1){
				z[1].push_back(x&1);
			} else {
				z[0].push_back(x&1);
			}
		}
		
		vector<int> w[2];
		for(int x=0;x<n;x++){
			if(a[x]&1){
				w[1].push_back(a[x]&1);
			} else {
				w[0].push_back(a[x]&1);
			}
		}
		
		int lg = log2(max(r, a[n-1]));
		int ans = 0;
		for(int i=0;i<=lg;i++){
			bool valid = true;
			int nxtbit = (1 << (i+1)), bit = (1 << i);
			for(int x=0;x<2;x++){
				if(w[x].size() != z[x].size()){
					valid = false;
					break;
				}
				for(int y=0;y<w[x].size();y++){
					if(w[x][y] != z[x][y]){
						valid = false;
						break;
					}
				}
			}
			
			if(!valid){
				ans |= bit;
			}
			
			for(int x=0;x<2;x++){
				z[x].clear();
				w[x].clear();
			}
			
			for(int x=l;x<=r;x++){
				if(x&nxtbit){
					z[1].push_back(x&((nxtbit << 1)-1));
				} else {
					z[0].push_back(x&((nxtbit << 1)-1));
				}
			}
			for(int x=0;x<n;x++){
				if(a[x]&nxtbit){
					w[1].push_back((a[x]^(!valid ? bit : 0))&((nxtbit << 1)-1));
				} else {
					w[0].push_back((a[x]^(!valid ? bit : 0))&((nxtbit << 1)-1));
				}
			}
			
			for(int x=0;x<2;x++){
				if(!z[x].empty()) sort(z[x].begin(), z[x].end());
				if(!w[x].empty()) sort(w[x].begin(), w[x].end());
			}
		}
		cout << ans << "\n";
	}
	
    return 0;
}

