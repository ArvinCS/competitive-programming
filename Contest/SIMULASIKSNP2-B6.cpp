#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 50;

ll cnt[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	fill(cnt, cnt+n+5, 0);
	
	for(int i=1;i<=q;i++){
		int t, node;
		cin >> t >> node;
		
		if(t == 1){
			ll val;
			cin >> val;
			
			cnt[node] += val;
		} else {
			ll ans = 0;
			for(int x=1;x*x<=node;x++){
				if(node%x == 0){
					ans += cnt[x];
					if(node/x != x) ans += cnt[node/x];
				}
			}
			cout << ans << "\n";
		}
	}

    return 0;
}

