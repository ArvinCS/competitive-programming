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

const int maxN = 1e5 + 5;

vector<int> w[maxN];

struct Celebrity {
	int time, x, y;
};

vector<Celebrity> v;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m;
	cin >> n >> m;
	
	for(int x=0;x<m;x++){
		int t, a, b;
		cin >> t >> a >> b;
		
		if(a+b-2 > t) continue;
		v.push_back(Celebrity({t, a, b}));
	}
	
	int ans = 0, mx = 1;	
	for(int x=0;x<v.size();x++){
		int cnt = 1;
		int left = 1, right = mx;
		while(left <= right){
			int mid = (left+right) >> 1;
			
			bool found = false;
			for(auto prv : w[mid]){
				if(v[prv].time+abs(v[x].x-v[prv].x)+abs(v[x].y-v[prv].y) <= v[x].time){
					found = true;
					break;
				}
			}
			if(found){
				left = mid+1;
				cnt = max(cnt, mid+1);
			} else {
				right = mid-1;
			}
		}
		w[cnt].push_back(x);
		ans = max(ans, cnt);
		mx = max(mx, cnt);
	}
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

