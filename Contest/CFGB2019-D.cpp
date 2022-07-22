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

int data[maxN];
bool picked[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	fill(data, data+n+1, -1);
	fill(picked, picked+n+1, false);

	int cnt = 0;
	while(cnt < k){
		vector<int> v;
		for(int x=1;x<=n;x++){
			if(picked[x]) continue;
			v.push_back(x);
			if(v.size() >= k) break;
		}
		if(v.size() < k) break;
		
		cout << "?";
		for(auto e : v){
			cout << " " << e;
		}
		cout << endl;
		
		int pos, val;
		cin >> pos >> val;
		
		picked[pos] = true;
		data[pos] = val;
	}
	
	int ans = -1;
	if(cnt < k){
		vector<pair<int, int>> v;
		for(int x=1;x<=n;x++){
			if(picked[x]){
				v.push_back({data[x], x});
			}
		}
		
		sort(v.begin(), v.end());
		
		vector<int> v2;
		for(int x=v.size()-1;x>=v.size()-k+1;x--){
			v2.push_back(x);
		}
		for(int x=1;x<=n;x++){
			if(!picked[x]){
				v2.push_back(x);
				cout << "?";
				for(auto e : v){
					cout << " " << e;
				}
				cout << endl;
				
				int pos, val;
				cin >> pos >> val;
				
				if(pos == x){
					
				} else {
					
				}
				
				break;
			}
		}
	} else {
		
	}
	cout << "! " << ans << endl;
    return 0;
}

// Santai
// Pikirin dengan benar-benar

