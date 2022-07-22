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

const int maxA = 1e6 + 5;

ll prime[maxA], form[maxA];

bool perfect(ll n){
	return ceil(sqrt(n*1.0)) == floor(sqrt(n*1.0));
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	for(int x=0;x<maxA;x++){
		prime[x] = x;
	}
	for(int x=2;x*x<maxA;x++){
		if(prime[x] == x){
			for(int y=x+x;y<maxA;y+=x){
				if(prime[y] == y) prime[y] = x;
			}
		}
	}
	
	form[1] = 1;
	for(int x=2;x<maxA;x++){
		int ans = 1;
		int cur = x;
		while(cur > 1){
			int div = prime[cur];
			int cnt = 0;
			while(cur % div == 0){
				cnt++;
				cur /= div;
			}
			
			if(cnt&1) ans *= div;
		}	
		form[x] = ans;
	}
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		map<int, int> mp;
		int data[n];
		for(int x=0;x<n;x++){
			cin >> data[x];
			mp[form[data[x]]]++;
		}
				
		int q;
		cin >> q;
		
		ll ans[q];
		for(int i=0;i<q;i++){
			cin >> ans[i];
		}
				
		ll cnt = 0, cnt2 = 0;
		for(auto e : mp){
			cnt = max(cnt, e.second*1ll);	
		}
		
		for(auto e : mp){
			if(e.first == 1 || e.second%2 == 0){
				cnt2 += e.second*1ll;
			}
		}
		
		for(int x=0;x<q;x++){
			if(x > 0) cout << " ";
			if(ans[x] == 0) cout << cnt;
			else cout << max(cnt, cnt2);
		}
		cout << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

