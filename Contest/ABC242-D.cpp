#include <bits/stdc++.h>

using namespace std;

#define ll long long

char m[3][2] = {{'B', 'C'}, {'C', 'A'}, {'A', 'B'}};

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	string s;
	cin >> s;
	
	int q;
	cin >> q;
	
	for(int x=0;x<q;x++){
		ll t, k;
		cin >> t >> k;
		
		ll msb = log2(k);
		int idx = (t < 60 ? (k-1) / pow(2ll, t) : 0);
		char c = s[idx];
		
		if(idx > 0){
			k -= (1ll << t)*idx;
		}
		
		if(t-1 > 59){
			ll remain = t-1-59;
			for(ll x=0;x<(remain%3ll);x++){
				c = m[(c - 'A')][0];
			}
		}
		
		for(ll i=min(59ll, t-1);i>=0;i--){
			ll bit = (1ll << i);
			
			if(k > bit){
				k -= bit;
				c = m[(c - 'A')][1];
			} else {
				c = m[(c - 'A')][0];
			}
		}
		
		cout << c << "\n";
	}
	
    return 0;
}

