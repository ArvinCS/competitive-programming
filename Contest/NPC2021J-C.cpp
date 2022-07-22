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

const int maxS = 10000;

int cnt[maxS];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	fill(cnt, cnt+maxS, 0);
	pair<string, int> v[n];
	for(int x=0;x<n;x++){
		cin >> v[x].first >> v[x].second;
	}
	
	for(int x=0;x<n;x++){
		for(int y=1;y<v[x].first.length();y++){
			if(v[x].first[y] == '0') continue;
			
			int sum = (v[x].first[y] - '0');
			for(int z=y+1;z<v[x].first.length();z++){
				s += v[x].first[z];
			}
		}
	}
	cout << ans << "\n";
    return 0;
}

