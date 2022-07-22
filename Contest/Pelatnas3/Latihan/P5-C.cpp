#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1e9 + 7;

void chadd(ll &a, ll b){
	a += b;
	if(a >= mod) a -= mod;
	if(a < 0) a += mod;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	ll a[n], b[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	for(int x=0;x<n;x++){
		cin >> b[x];
	}
	
	sort(a, a+n);
	sort(b, b+n);
	
	int cnt[n];
	fill(cnt, cnt+n, 0);
	
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			if(a[x] <= b[y]){
				cnt[y]++;
				break;
			}
		}
	}
	
	ll table[n+1];
	fill(table, table+n+1, 0);
	
	table[0] = 1;
	
	int cur = 0;
	for(int x=0;x<n;x++){
		cur += cnt[x];

		for(int y=n-1;y>=0;y--){
			if(y < cur && y+1 <= n){
				chadd(table[y+1], (cur-y)*table[y] % mod);
			}
		}
	}
	
	for(int x=0;x<=n;x++){
		cout << x << " -> " << table[x] << "\n";
	}
	
	cout << table[0] << "\n";
    return 0;
}

