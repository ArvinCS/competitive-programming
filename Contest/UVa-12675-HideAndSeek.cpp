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

pair<int, int> center;
bool customSort(pair<int, int> a, pair<int, int> b){
	return -atan2(a.first-center.first, a.second-center.second) < -atan2(b.first-center.first, b.second-center.second);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	us t;
	cin >> t;
	
	int s, k, w;
	cin >> s >> k >> w;
	
	while(t--){
		pair<int, int> kid[k], wall[w], seek[s];
		for(int x=0;x<k;x++){
			cin >> kid[x].first >> kid[x].second;
			if(x < s){
				seek[x] = kid[x];
			}
		}
		for(int x=0;x<w;x++){
			cin >> wall[x].first >> wall[x].second;
		}
		
		for(int x=0;x<s;x++){
			vector<int> ver, hor;
			map<double, vector<int>> mp;
			
			cout << x << "----\n";
			for(int y=0;y<k;y++){
				if(x == y) continue;
				if(kid[x].first == kid[y].first){
					ver.push_back(y);
				} else if(kid[x].second == kid[y].second){
					hor.push_back(y);
				} else {
					int a = kid[x].first-kid[y].first;
					int b = kid[x].second-kid[y].second;
					
					double angle = (b == 0 ? 0 : a*1.0/b);
					mp[angle].push_back(y);	
				}
			}
			
			mp[-inf_int] = ver;
			mp[inf_int] = hor;
			for(auto m : mp){
				for(auto )
			}
		}
		break;
	}

    return 0;
}

