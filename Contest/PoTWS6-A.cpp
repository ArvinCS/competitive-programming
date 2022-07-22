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

const int maxN = 18+5;

ll table[maxN][3];
vector<int> low, high;

ll solve(int len, int mx, int cnt, bool great, bool less){
	if(cnt > 3) return 0;
	if(great && less && table[mx-len+1][cnt] != -1) return table[mx-len+1][cnt];
	if(len >= mx){
		return 1;
	}
	
	ll ans = 0;
	int start = (great ? 0 : low[len]);
	int end = (less ? 9 : high[len]);
	for(int x=start;x<=end;x++){
		ans += solve(len+1, mx, cnt+(x != 0 ? 1 : 0), great||(x > start ? true : false), less||(x < end ? true : false));
	}
	
	if(great && less){
		table[mx-len+1][cnt] = ans;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	fill(table[0], table[maxN], -1);
	
	us t;
	cin >> t;
	
	while(t--){
		ll l, r;
		cin >> l >> r;
		
		low.clear(); high.clear();
		while(l > 0){
			low.push_back(l%10);
			l /= 10;
		}
		while(r > 0){
			high.push_back(r%10);
			r /= 10;
		}
		while(low.size() < high.size()){
			low.push_back(0);
		}
		
		reverse(low.begin(), low.end());
		reverse(high.begin(), high.end());
		
		cout << solve(0, high.size(), 0, false, false) << "\n";
	}
	
    return 0;
}

