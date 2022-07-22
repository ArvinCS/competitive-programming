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

bool customSort(pair<int, int> a, pair<int, int> b){
	if(a.first-a.second+1 == b.first-b.second+1){
		if(a.first == b.first) return a.second < b.second;
		return a.first < b.first;
	}
	return a.first-a.second+1 < b.first-b.second+1;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		pair<int, int> p[n];
		for(int x=0;x<n;x++){
			cin >> p[x].first;
		}
		for(int x=0;x<n;x++){
			cin >> p[x].second;
		}
		
		sort(p, p+n, customSort);
		
		int ans = 0, level = 1, pos = 1;
		for(int x=0;x<n;x++){
			int cur = p[x].first-p[x].second+1;
			if(level < cur && (level+1)/2 != (cur+1)/2){
				ans += (cur+1)/2-(level+1)/2;
			} else if(level == cur && level&1){
				ans += p[x].second-pos;
			}
			level = cur;
			pos = p[x].second;
		}
		cout << ans << "\n";
	}

    return 0;
}

