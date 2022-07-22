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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m, k;
	cin >> n >> m >> k;
	
	pair<int, int> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
		p[x].first = (p[x].first+k-1)/k * k;
		p[x].second = p[x].second/k * k;
	}
	
	int ans = 0;
	for(int a=p[0].first;a<=p[0].second;a+=k){
		for(int b=p[1].first;b<=p[1].second;b+=k){
			for(int c=p[2].first;c<=p[2].second;c+=k){
				if(a+b+c > m) break;
				for(int d=p[3].first;d<=p[3].second;d+=k){
					if(a+b+c+d > m) break;
					for(int e=p[4].first;e<=p[4].second;e+=k){
						if(a+b+c+d+e <= m){
							ans++;
						}
					}
				}
			}
		}
	}
	cout << ans << "\n";
    return 0;
}

