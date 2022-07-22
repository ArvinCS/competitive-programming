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

	int t;
	cin >> t;
	
	while(t--){
		int n, u1, r1, d1, l1;
		cin >> n >> u1 >> r1 >> d1 >> l1;
		
		bool possible = false;
		
		for(int a=0;a<2;a++){	
			for(int b=0;b<2;b++){
				for(int c=0;c<2;c++){
					for(int d=0;d<2;d++){
						int tmpu = u1, tmpr = r1, tmpd = d1, tmpl = l1;
						if(a){
							tmpu--;
							tmpr--;
						}
						if(b){
							tmpd--;
							tmpr--;
						}
						if(c){
							tmpd--;
							tmpl--;
						}
						if(d){
							tmpu--;
							tmpl--;
						}
						
						if(tmpu >= 0 && tmpr >= 0 && tmpd >= 0 && tmpl >= 0){
							if(tmpu <= n-2 && tmpr <= n-2 && tmpd <= n-2 && tmpl <= n-2){
								possible = true;
								break;
							}
						}
					}
					if(possible) break;
				}
				if(possible) break;
			}
			if(possible) break;
		}
		
		if(possible) cout << "YES\n";
		else cout << "NO\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

