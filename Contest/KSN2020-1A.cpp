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

const int maxK = 1e5 + 5;

pair<ll, ll> data[maxK];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ll n, m, k;
	cin >> n >> m >> k;
	
	for(int x=0;x<k;x++){
		cin >> data[x].first;
		data[x].second = x;
	}
	
	pair<pair<int, int>, pair<int, int>> ans[k];
	sort(data, data+k);
	
	ll total = n*m;
//	ll curX = 0, curY = 0;
//	for(int a=0;a<k;a++){
//		if(curX+data[a].first > n){
//			if(curY+2 <= m){
//				curY++;
//			} else {
//				ans[data[a].second] = {make_pair(-1, -1), make_pair(-1, -1)};
//				continue;
//			}
//		}
//		ans[data[a].second] = {make_pair(curX, curX+data[a].first), make_pair(curY, curY+1)};	
//		curX += data[a].first;
//	}
//	
//	for(int x=0;x<k;x++){
//		cout << ans[x].first.first << " " << ans[x].first.second << " " << ans[x].second.first << " " << ans[x].second.second << "\n"; 
//	}
	
	for(int a=0;a<k;a++){
		if(total >= data[a].first){
			cout << data[a].second << " ";
			total -= data[a].first;
		}
	}
	cout << "\n";
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

