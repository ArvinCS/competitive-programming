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

const int maxN = 505;

int parrent[maxN], len[maxN], sz[maxN];

pair<int, int> getParrent(int x){
	if(parrent[x] == x) return {x, 0};
	pair<int, int> p = getParrent(parrent[x]);
	
	parrent[x] = p.first;
	len[x] = (len[x]+p.second)%2;
	
	return {parrent[x], len[x]};
}

void merge(int x, int y){
	pair<int, int> a = getParrent(x);
	pair<int, int> b = getParrent(y);
	
	if(a.first != b.first){
		if(sz[a.first] < sz[b.first]){
			swap(a, b);
		}
		parrent[b.first] = a.first;
		len[b.first] = (b.second + 1 + a.second) % 2;
		sz[a.first] += sz[b.first];
	}
}

bool check(int x, int y){
	return (getParrent(x).first == getParrent(y).first);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	int data[n][n], mx = 0;
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			cin >> data[x][y];
			mx = max(mx, data[x][y]);
		}
	}
	
	int left = 1, right = mx, ans = 0;
	while(left <= right){
		int mid = (left+right) >> 1;
		
		for(int x=0;x<n;x++){
			parrent[x] = x;
			sz[x] = 1;
			len[x] = 0;
		}
		
		bool valid = true;
		for(int x=0;x<n;x++){
			for(int y=0;y<n;y++){
				if(x != y && data[x][y] < mid){
					if(check(x, y)){
						if(getParrent(x).second == getParrent(y).second){
							valid = false;
							break;
						}
						continue;
					}
					merge(x, y);
				}
			}
		}
		
		if(valid){
			left = mid+1;
			ans = mid;
		} else {
			right = mid-1;
		}
	}
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

