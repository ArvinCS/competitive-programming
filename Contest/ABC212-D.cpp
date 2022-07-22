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
	
	int q;
	cin >> q;
	
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	ll cur = 0;
	
	for(int i=1;i<=q;i++){
		int t;
		cin >> t;
		
		if(t == 3){
			cout << pq.top()+cur << "\n";
			pq.pop();
		} else {
			ll val;
			cin >> val;
			
			if(t == 1){
				pq.push(val-cur);
			} else {
				cur += val;
			}
		}
	}
	
    return 0;
}

