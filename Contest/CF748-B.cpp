#include <bits/stdc++.h>

using namespace std;

#define ll long long

int need[4][2] = {{2, 5}, {5, 0}, {7, 5}, {0, 0}};

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int t;
	cin >> t;
	
	while(t--){
		ll n;
		cin >> n;
		
		vector<ll> v;
		ll cur = n;
		while(cur > 0){
			v.push_back(cur%10);
			cur /= 10;
		}
		
		reverse(v.begin(), v.end());
		
		int ans = 1e8;
		for(int x=0;x<4;x++){
			int pos[2];
			fill(pos, pos+2, -1);
			
			for(int y=v.size()-1;y>=0;y--){
				if(pos[1] == -1){
					if(v[y] == need[x][1]){
						pos[1] = y;
					}
				} else if(pos[0] == -1){
					if(v[y] == need[x][0]){
						pos[0] = y;
					}
				}
			}
			
			if(pos[0] != -1 && pos[1] != -1){
				ans = min(ans, ((int) v.size())-1-pos[0]-1);
			}
		}
		cout << ans << "\n";
	}

    return 0;
}

