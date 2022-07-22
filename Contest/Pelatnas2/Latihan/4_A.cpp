#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1e9 + 9;
const int maxM = 5e3 + 5;

ll pw[maxM];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	pw[0] = 1;
	for(int x=1;x<maxM;x++){
		pw[x] = (137ll * pw[x-1]) % mod;
	}
	
	int n, m;
	cin >> n >> m;
	
	string s[n], t[n];
	for(int x=0;x<n;x++){
		cin >> s[x];
		t[x] = s[x];
	}
	
	bool empty[n];
	fill(empty, empty+n, true);
	
	ll hash[n][2*m];
	for(int x=0;x<n;x++){
		ll val = 0;
		for(int y=0;y<2*m;y++){
			if(y >= m) t[x].push_back(s[x][y%m]);
			val *= pw[1];
			val %= mod;
			
			val += (s[x][y%m] == '*' ? 1 : 0);
			val %= mod;
			
			hash[x][y] = val;
			
			if(s[x][y%m] == '*'){
				empty[x] = false;
			}
		}
	}
	
	// step:
	// compare config i and j
	// start from n to 1
	// if string_i idx == string_j idx
	// continue
	// if string_i idx < string_j idx
	// i best
	// else 
	// j best
	
	int opt[n];
	fill(opt, opt+n, 0);
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			int left = 0, right = m-1, bound = m;
			while(left <= right){
				int mid = (left+right) >> 1;
				
				ll valopt = (hash[x][m+m-1-opt[x]] - (hash[x][m+mid-1-opt[x]] * pw[m-mid] % mod) + 3*mod) % mod;
				ll valcur = (hash[x][m+m-1-y] - (hash[x][m+mid-1-y] * pw[m-mid] % mod) + 3*mod) % mod;
				
				if(valcur == valopt){
					bound = min(bound, mid);
					right = mid-1;
				} else {
					left = mid+1;
				}
			}
			
			if(bound == 0){
				continue;
			}
			
			assert(t[x][m+bound-1-y] != t[x][m+bound-1-opt[x]]);
			
			if(t[x][m+bound-1-y] > t[x][m+bound-1-opt[x]]){
				opt[x] = y;
			}
		}
	}
	
	pair<int, int> best = {0, 0};
	for(int x=0;x<n;x++){
		int pos = opt[x];
		
		if(empty[x]){
			for(int y=0;y<n;y++){
				if(!empty[(x-y+n)%n]){
					assert((x-y+n)%n >= 0);
					
					pos = opt[(x-y+n)%n];
					break;
				}
			}
		}
		
		bool better = false;
		for(int y=0;y<n;y++){
			int rowcur = (x-y+n)%n;
			int rowbest = (best.first-y+n)%n;
			
			assert(rowcur >= 0 && rowbest >= 0);
			
			int left = 0, right = m-1, bound = m;
			while(left <= right){
				int mid = (left+right) >> 1;
				
				ll valopt = (hash[rowbest][m+m-1-best.second] - (hash[rowbest][m+mid-1-best.second] * pw[m-mid] % mod) + 3*mod) % mod;
				ll valcur = (hash[rowcur][m+m-1-pos] - (hash[rowcur][m+mid-1-pos] * pw[m-mid] % mod) + 3*mod) % mod;
				
				assert(valopt >= 0 && valcur >= 0);
				
				if(valcur == valopt){
					bound = min(bound, mid);
					right = mid-1;
				} else {
					left = mid+1;
				}
			}
			
			if(bound == 0){
				better = true;
				continue;
			}
			
			assert(m+bound-1-pos >= 0 && m+bound-1-best.second >= 0);
			assert(t[rowcur][m+bound-1-pos] != t[rowbest][m+bound-1-best.second]);
			
			if(t[rowcur][m+bound-1-pos] >= t[rowbest][m+bound-1-best.second]){ // . > *
				better = true;
			} else {
				better = false;
			}
			break;
		}
		
		if(better){
			best = {x, pos};
		}
	}
	
//	cout << best.first << " " << best.second << "\n";
	for(int x=n-1;x>=0;x--){
		for(int y=0;y<m;y++){
			cout << s[(best.first-x+n)%n][(y-best.second+m)%m];
			assert((best.first-x+n)%n >= 0);
			assert((y-best.second+m)%m >= 0);
		}
		cout << "\n";
	}
    return 0;
}

