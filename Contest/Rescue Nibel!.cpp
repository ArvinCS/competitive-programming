#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007

const ull smod = 998244353;
const int maxN = 3 * 1e5 + 5;

ull fac[maxN];
int segment[maxN];

ull power(ull x, ull y){
	ull ans = 1;
	x %= smod;
	
	while(y > 0){
		if(y&1) ans = (ans * x) % smod;
		
		x = (x*x)%smod;
		y >>= 1;
	}
	
	return ans % smod;
}

ull modInverse(ull x){
	return power(x, smod-2);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	fac[0] = 1;
	for(ull x=1;x<=maxN;x++){
		fac[x] = (fac[x-1] * x) % smod;	
	}	
	
	int n, k;
	cin >> n >> k;
	
	set<int> s;
	unordered_map<int, int> mp;
	
	pair<int, int> lamp[n];
	for(int x=0;x<n;x++){
		cin >> lamp[x].first >> lamp[x].second;
		s.insert(lamp[x].first);
		s.insert(lamp[x].second);		
	}
	
	int index = 0;
	for(set<int>::iterator it=s.begin();it != s.end();it++){
		mp[*it] = index++;	
	}
	
	for(int x=0;x<n;x++){
		lamp[x].first = mp[lamp[x].first];
		lamp[x].second = mp[lamp[x].second];	
	}
	
	if(k == 1){
		cout << n << "\n";
		return 0;
	}
	
	for(int x=0;x<n;x++){
		segment[x] = 0;
	}
	
	sort(lamp, lamp+n);
	
	for(int x=0;x<k-1;x++){
		for(int y=x;y<n;y++){
			if(lamp[x].second < lamp[y].first) break;
			segment[y]++;
		}	
	}
	
	ull ans = 0;
	for(int x=k-1;x<n;x++){
		for(int y=x;y<n;y++){
			if(lamp[x].second < lamp[y].first) break;
			segment[y]++;
		}
		if(segment[x] >= k){
			int total = segment[x]-1;
			ans += (fac[total] * modInverse(fac[k-1]) % smod * modInverse(fac[total-(k-1)]) % smod) % smod;
			ans %= smod;
		}
//		cout << x << " -> " << ans << " " << segment[x] << "\n";
	}
	
	cout << ans % smod << "\n";
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

