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
		ll w, h;
		cin >> w >> h;
		
		vector<ll> ans;
		for(int ah=0;ah<=1;ah++){
			int aw = ah^1;
			for(int bh=0;bh<=1;bh++){
				int bw = bh^1;
				for(int ch=0;ch<=1;ch++){
					int cw = ch^1;
					for(int dh=0;dh<=1;dh++){
						int dw = dh^1;
						
						
						ll h1 = h-ah-dh;
						ll h2 = h-bh-ch;
						ll w1 = w-aw-bw;
						ll w2 = w-cw-dw;
						
						ll gcd = __gcd(h1, h2);
						gcd = __gcd(gcd, __gcd(w1, w2));
						for(int x=1;x*x<=gcd;x++){
							if(gcd%x == 0){
								ans.push_back(x);
								if(gcd/x != x) ans.push_back(gcd/x);
							}
						}
					}
				}	
			}
		}
		
		sort(ans.begin(), ans.end());
		ans.erase(unique(ans.begin(), ans.end()), ans.end());
		
		cout << ans.size();
		for(int x=0;x<ans.size();x++){
			cout << " " << ans[x];
		}
		cout << "\n";
	}
	
    return 0;
}

