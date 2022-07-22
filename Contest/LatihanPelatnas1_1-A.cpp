#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll maxN = 1e14 + 5;
const ll sqrtN = 1e7 + 5;

bool prime[sqrtN];
vector<int> v, w;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	fill(prime, prime+sqrtN, true);
	prime[1] = false;
	for(int x=2;x*x<sqrtN;x++){
		if(prime[x]){
			for(int y=2*x;y<sqrtN;y+=x){
				prime[y] = false;
			}
		}
	}
	for(int x=2;x<sqrtN;x++){
		if(prime[x]){
			v.push_back(x);
			w.push_back(x-1);
		}
	}
	
	ll l, r;
	cin >> l >> r;
	
	ll ans = 0;
	for(int x=0;x<v.size();x++){
		int mx = 0, mn = 0;
		ll cur = r;
		while(cur >= v[x]){
			mx++;
			cur /= v[x];
		}
		
		cur = l-1;
		while(cur >= v[x]){
			mn++;
			cur /= v[x];
		}
		
		mn = max(1, mn);
		
		int idxRight = lower_bound(w.begin(), w.end(), mx+1) - w.begin();
		int idxLeft = lower_bound(w.begin(), w.end(), mn+1) - w.begin();
		
		ans += max(0, idxRight-idxLeft);
	}
	
	cout << ans << "\n";
    return 0;
}

