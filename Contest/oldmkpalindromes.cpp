#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

#define mod 1000000007

ll fac[201], comb[201][201];
us n;
string s;

bool check(string a){
	short i = 0, len = a.length();
	for(short x=0;x<len;x++){
		if(a[x] == s[i]){
			i++;
		}
		if(i == s.length()) break;
	}	
	for(short x=len-1;x>=0;x--){
		if(i == s.length()) break;
		if(a[x] == s[i]){
			i++;
		}
	}	
	return i == s.length();
}

unordered_set<string> visited;
ll solve(short l, short r, string t){
	if(visited.count(t)) return 0;	// biar tidak ada string yang sama
	visited.insert(t); // masukin

//	cout << t  << " -> " << check(t) << "\n";
	if(l > r){ // jika length t == length s
		return check(t); // cek apakah cocok
	}
//	cout << l << " - " << r << " -> " << memo[l][r] << " " << (fac[n] / (fac[t.length()] * fac[n-t.length()]) * 25) << "\n";
	
	ll tmp = check(t) * comb[n][t.length()] % mod * 25; // biar gampang dilihat
	return (tmp % mod + (solve(l, r-1, t+s[r]) + solve(l+1, r, t+s[l])) % mod) % mod;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n >> s;
	
	comb[0][0] = 1;
	for(us x=1;x<=n;x++){
		for(us y=0;y<=n;y++){
			if(y == 0){
				comb[x][y] = 1;
			} else {
				comb[x][y] = (comb[x-1][y-1] % mod + comb[x-1][y] % mod) % mod;
			}
		}
	}
	
	string t;
	cout << solve(0, n-1, t) % mod << "\n";
	
    return 0;
}
