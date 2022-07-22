#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

const int maxA = 5e6 + 5;

int cnt[maxA];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	fill(cnt, cnt+maxA, 0);
	
	int n, m;
	cin >> n >> m;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
		cnt[a[x]]++;
	}
	
	int ans = 1;
	for(int x=1;x<=5000000;x++){
		int sum = 0;
		for(int y=1;x*y<=5000000;y++){
			sum += cnt[x*y];
		}
		
		if(sum >= m){
			ans = x;
		}
	}
	cout << ans << "\n";
	
    return 0;
}

