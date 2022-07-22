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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		vector<pair<int, int>> v;
		for(int x=0;x<n;x++){
			if(a[x] > 0){
				v.push_back(make_pair(max(x-a[x]+1, 0), x));
			}
		}
		
		sort(v.begin(), v.end());
		
		int i = 0;
		for(int x=0;x<n;x++){
			if(x > 0) cout << " ";
			while(i < v.size() && v[i].second < x){
				i++;
			}
			if(i < v.size() && v[i].first <= x && x <= v[i].second){
				cout << "1";
			} else {
				cout << "0";
			}
		}
		cout << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

