#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;
const int logN = log2(maxN)+1;
const ll mod = 998244353;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<int> v;
	int a[n], b[m];
	for(int x=0;x<n;x++){
		cin >> a[x];
		v.push_back(a[x]);
	}
	for(int x=0;x<m;x++){
		cin >> b[x];
		v.push_back(b[x]);
	}
	
	ll ans = 1;
	int pos = n-1;
	for(int x=m-1;x>=0;x--){
		if(pos == -1){
			ans = 0;
			break;
		}
		
		ll cnt = 0;
		while(pos >= 0 && a[pos] >= b[x]){
			if(a[pos] == b[x] && cnt == 0){
				cnt = 1;
			} else if(cnt > 0){
				cnt++;
			}
			pos--;
		}
		
		if(x == 0 && pos != -1){
			ans = 0;
			break;
		}
		if(x == 0){
			ans *= min(cnt, 1ll);
			break;
		}
		
		ans *= cnt;
		ans %= mod;
	}
	
	cout << ans << "\n";
    return 0;
}

