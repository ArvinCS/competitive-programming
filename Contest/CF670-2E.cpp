#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;

int prime[maxN], cnt = 0;
bool exist[maxN];

int opA(int x){
	cout << "A " << x << endl;
	cnt++;
	
	int res;
	cin >> res;
	
	return res;
}

int opB(int x){
	cout << "B " << x << endl;
	cnt++;
	
	int res;
	cin >> res;
	
	return res;
}

void opC(ll x){
	cout << "C " << x << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	
	for(int x=0;x<maxN;x++){
		prime[x] = x;
	}
	for(int x=2;x*x<maxN;x++){
		if(prime[x] == x){
			for(int y=x*2;y<maxN;y+=x){
				if(prime[y] == y) prime[y] = x;
			}
		}
	}
	
	int n;
	cin >> n;
	
	int sum = n, sz = 0;
	for(int x=1;x<=n;x++){
		if(prime[x] == x) sz++;
		exist[x] = true;
	}
	
	sz = sqrt(sz);
	
	ll ans = 1;
	vector<array<int, 3>> v;
	for(int x=2;x<=n;x++){
		if(prime[x] == x){
			int cur = opB(x), cur2 = 0;
			for(int y=1;y*x<=n;y++){
				if(exist[y*x]){
					cur2++;
					sum--;
					exist[y*x] = false;
				}
			}
			
			cur = cur2;
			v.push_back({x, cur2, cur});
			
			if(v.size() == sz || sum == 1){
				if(opA(1) == sum){
					v.clear();
					continue;
				}
				
				int val = 0;
				for(int y=sz-1;y>=0;y--){
					if(opA(v[y][0]) != 0){
						val = v[y][0];
						break;
					}
				}
				
				bool found = true;
				while(found){
					found = false;
					for(int y=2;y<=n;y++){
						if(prime[y] == y && y*1ll*val <= n){
							if(opA(y*val) != 0){
								found = true;
								val *= y;
								break;
							}
						}
					}
				}
				ans = val;
				break;
			}
		}
	}
	
	opC(ans);
    return 0;
}

