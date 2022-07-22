#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxA = 1e6 + 5;
const int maxN = 2e5 + 5;
const int sqrtA = 78500;

int dv[maxA];
int cnt = 0, sz = 480;
int fac[maxA];
vector<pair<int, int>> v[maxN];

bool customSort(tuple<int, int, int> a, tuple<int, int, int> b){
	if(get<0>(a)/sz == get<0>(b)/sz){
		if((get<0>(a)/sz)&1) return get<1>(a) > get<1>(b);
		else return get<1>(a) < get<1>(b);
	}
	return a < b;
}

void solve(int idx, int c){
	for(auto p : v[idx]){
		bool three = (fac[p.first] % 3 == 0);
		
		fac[p.first] += c*p.second;
		
		if(three != (fac[p.first] % 3 == 0)){
			if(three) cnt++;
			else cnt--;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	for(int x=0;x<maxA;x++){
		dv[x] = x;
	}
	
	int prime = 0;
	for(int x=2;x*x<maxA;x++){
		if(dv[x] == x){
			for(int y=2*x;y<maxA;y+=x){
				if(dv[y] == y) dv[y] = x;
			}
		}
	}
	
	fill(fac, fac+maxA, 0);
	
	int n, q;
	cin >> n >> q;
	
	for(int x=0;x<n;x++){
		int val;
		cin >> val;
		
		while(val > 1){
			int prime = dv[val];
			int cnt2 = 0;
			while(val % prime == 0){
				val /= prime;
				cnt2++;
			}
			
			v[x].push_back({prime, cnt2});
		}
	}
	
	tuple<int, int, int> p[q];
	for(int x=0;x<q;x++){
		int l, r;
		cin >> l >> r;
		
		l--; r--;
		p[x] = make_tuple(l, r, x);
	}
	
	sz = sqrt(n);
	
	sort(p, p+q, customSort);
	
	bool ans[q];
	int curL = 0, curR = 0;
	for(int x=0;x<q;x++){ // [L, R)
		int l = get<0>(p[x]), r = get<1>(p[x]);
		
		while(curR <= r){
			solve(curR, 1);
			curR++;
		}
		while(curL > l){
			curL--;
			solve(curL, 1);
		}
		
		while(curR > r+1){
			curR--;
			solve(curR, -1);
		}
		while(curL < l){
			solve(curL, -1);
			curL++;
		}
		
		ans[get<2>(p[x])] = (cnt == 0);
	}
	
	for(int x=0;x<q;x++){
		cout << (ans[x] ? "Yes" : "No") << "\n";
	}
    return 0;
}

