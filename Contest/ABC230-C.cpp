#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll n, a, b;
	cin >> n >> a >> b;
	
	ll p, q, r, s;
	cin >> p >> q >> r >> s;
	
	for(ll x=p;x<=q;x++){
		for(ll y=r;y<=s;y++){
			if(abs(x-a) == abs(y-b)){
				cout << "#";
			} else {
				cout << ".";
			}
		}cout << "\n";
	}
    return 0;
}

