#include <bits/stdc++.h>
#include <chrono>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	
	int t;
	cin >> t;
	
	for(int i=1;i<=t;i++){
		int n, k;
		cin >> n >> k;
		
		ll ans = 0;
		
		bool visited[n];
		fill(visited, visited+n, false);
		
		int room = 0;
		ll pas = 0;
		auto check = [&]() -> void {
			int a;
			ll b;
			cin >> a >> b;
			
			a--;
			
			visited[a] = true;
			room = a;
			pas = b;
			ans += pas;
		};
		
		auto go = [&](int nxt) -> void {
			cout << "T " << nxt+1 << endl;
		};
		
		check();
		
		if(n <= k){
			for(int x=0;x<n;x++){
				if(!visited[x]){
					go(x);
					check();
				}
			}
			
			ans /= 2;
		} else {
			pair<int, int> mx = {pas, room};
			for(int x=0;x<k/2-1;x++){
				int nxt = rng() % n;
				while(visited[nxt]){
					nxt = rng() % n;
				}
				
				go(nxt);
				check();
				
				mx = max(mx, {pas, room});
			}
			
			go(mx.second);
			check();
			
			map<int, ll> mp, mp2;
			for(int x=0;x<k/2;x+=2){
				cout << "W" << endl;
				
				check();
				
				mp[room]++;
				mp2[room] = pas;
			}
			
			ans = 0;
			
			pair<ll, ll> pr = {-1, -1};
			for(auto p : mp){
				if(pr.first == -1){
					pr = p;
				} else {
					pr = {pr.first*p.second+p.first*pr.second, pr.second*p.second};
					
					int gcd = __gcd(pr.first, pr.second);
					pr.first /= gcd;
					pr.second /= gcd;
				}
				
				ans += mp2[p.first]-1;
			}
			
			ans += pr.second/pr.first;
			ans += n;
		}
		
		cout << "E " << ans << endl;
	}
	
    return 0;
}

