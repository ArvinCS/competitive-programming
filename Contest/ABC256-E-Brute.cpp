#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int m[n], c[n];
	for(int x=0;x<n;x++){
		cin >> m[x];
		m[x]--;
	}
	for(int x=0;x<n;x++){
		cin >> c[x];
	}
	
	int p[n];
	for(int x=0;x<n;x++){
		p[x] = x;
	}
	
	ll ans = 1e18;
	do {
		ll sum = 0;
		bool exist[n];
		fill(exist, exist+n, false);
		
		for(int x=0;x<n;x++){
			if(exist[m[p[x]]]){
				sum += c[p[x]];
			}
			exist[p[x]] = true;
		}
		
//		if(sum <= ans){
//			cout << sum << ":\n";
//			for(int x=0;x<n;x++){
//				cout << p[x] << " ";
//			}cout << "\n";
//		}
		ans = min(ans, sum);
	} while(next_permutation(p, p+n));
	
	cout << ans << "\n";
    return 0;
}

