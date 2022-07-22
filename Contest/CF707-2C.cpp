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

const int maxN = 2 * 1e5 + 5;

int data[maxN];
map<int, pair<int, int>> mp;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
		
	for(int x=0;x<n;x++){
		for(int y=x+1;y<n;y++){
			int cnt = data[x] + data[y];
			if(mp.find(cnt) == mp.end()){
				mp[cnt] = make_pair(x, y);
			} else {
				pair<int, int> p = mp[cnt];
				
				if(p.first != x && p.first != y && p.second != x && p.second != y){
					cout << "YES\n";
					cout << p.first+1 << " " << p.second+1 << " " << x+1 << " " << y+1 << "\n";
					return 0;
				}
			}
		}
	}
	
	cout << "NO\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

