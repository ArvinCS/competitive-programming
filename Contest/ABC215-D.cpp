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

const int maxA = 1e5 + 5;

int prime[maxA];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	for(int x=0;x<maxA;x++){
		prime[x] = x;
	}
	
	for(int x=2;x*x<maxA;x++){
		if(prime[x] == x){
			for(int y=x+x;y<maxA;y+=x){
				if(prime[y] == y){
					prime[y] = x;
				}
			}
		}
	}
	
	int n, m;
	cin >> n >> m;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	set<int> st;
	for(int x=0;x<n;x++){
		int cur = a[x];
		while(cur > 1){
			int div = prime[cur];
			while(cur % div == 0){
				cur /= div;
			}
			st.insert(div);
		}
	}
	
	vector<int> ans;
	for(int x=1;x<=m;x++){
		bool ok = true;
		for(auto val : st){
			if(x % val == 0){
				ok = false;
				break;
			}
		}
		
		if(ok) ans.push_back(x);
	}
	
	cout << ans.size() << "\n";
	for(auto val : ans){
		cout << val << "\n";
	}
    return 0;
}

