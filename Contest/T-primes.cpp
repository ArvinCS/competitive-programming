#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

set<ull> nonprimes;
set<ull> tprimes;

ull maxN = 1e12;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	for(ull i=2;i*i<=maxN;i++){
		if(nonprimes.count(i) == 0){
			if(nonprimes.count(i*i) == 0) tprimes.insert(i*i);
			for(ull x=i*2;x*x<=maxN;x+=i) nonprimes.insert(x);
		}
	}
	
	int n;
	cin >> n;
	
	ull tmp;
	for(int i=0;i<n;i++){
		cin >> tmp;
		
		if(tprimes.count(tmp) == 1){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	
    return 0;
}
