#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxQ = 1e5;
const ll inf = 1e18;

bool prime[maxQ];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	fill(prime, prime+maxQ, true);
	vector<int> v;
	for(int x=2;x<maxQ;x++){
		if(prime[x]){
			v.push_back(x);
			for(int y=2*x;y<maxQ;y+=x){
				prime[y] = false;
			}
		}
	}
	
	int t;
	cin >> t;
	
	while(t--){
		ll ans = 1;
		ll val = 1;
		
		int pos = 0;
		vector<ll> primes;
		while(pos < v.size() && v[pos] <= 179){
			vector<ll> w;
			ll cur = 1;
			while(pos < v.size() && cur <= inf/v[pos]){
				w.push_back(v[pos]);
				cur *= v[pos];
				pos++;
				assert(cur > 1 && cur < inf);
			}
			
			assert(cur > 1 && cur < inf);
			
			cout << "? " << cur << endl;
			
			ll res;
			cin >> res;
			
			for(int x=0;x<w.size();x++){
				if(res % w[x] != 0) continue;
				
				primes.push_back(w[x]);
				res /= w[x];
			}
		}
		
		for(int x=0;x<primes.size();x+=2){
			ll cur = 1;
			ll cur2 = 1;
			
			while(cur <= 1e9/primes[x]){
				cur *= primes[x];
			}
			
			if(x+1 < primes.size()){
				while(cur2 <= 1e9/primes[x+1]){
					cur2 *= primes[x+1];
				}
			}
			
			cout << "? " << cur*cur2 << endl;
			
			ll res;
			cin >> res;
			
			int cnt = 0;
			while(res % primes[x] == 0){
				res /= primes[x];
				val *= primes[x];
				cnt++;
			}
			
			ans *= cnt+1;
			
			if(x+1 < primes.size()){
				cnt = 0;
				while(res % primes[x+1] == 0){
					res /= primes[x+1];
					val *= primes[x+1];
					cnt++;
				}
				
				ans *= cnt+1;
			}
		}
		
		if(val == 1){
			cout << 8 << endl;
			continue;
		}
		
		
		cout << "! " << max(ans+7, ans*2) << endl;
	}
    return 0;
}

