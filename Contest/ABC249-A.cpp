#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll a, b, c, d, e, f, x;
	cin >> a >> b >> c >> d >> e >> f >> x;
	
	ll posA = 0, posB = 0;
	ll nxtA = 0, nxtB = 0;
	for(int i=0;i<=x;i++){
		if(nxtA == i){
			posA += min(x-i, a)*b;
			nxtA += a+c;
		}
		if(nxtB == i){
			posB += min(x-i, d)*e;
			nxtB += d+f;
		}
	}
	
	if(posA < posB){
		cout << "Aoki\n";
	} else if(posA == posB){
		cout << "Draw\n";
	} else {
		cout << "Takahashi\n";
	}
    return 0;
}

