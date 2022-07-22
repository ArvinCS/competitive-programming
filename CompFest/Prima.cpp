#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ui n, k;
	cin >> n >> k;
	
	bool prime[611954];
	fill(begin(prime), end(prime), true);
	
	vector<ui> primes;
	for(ui x=2;x<=611954;x++){
		if(prime[x]){
			primes.push_back(x);
			for(ui y=x*2;y<=611954;y+=x){
				prime[y] = false;
			}
		}
	}
	
	for(ui x=0;x<n;x++){
		cout << primes[x*k] << "\n";
	}
    return 0;
}

