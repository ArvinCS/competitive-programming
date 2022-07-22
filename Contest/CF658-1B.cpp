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

const int maxN = 4005;

int arr[maxN];

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
		
		for(int x=1;x<=2*n;x++){
			cin >> arr[x];
		}
		
		vector<int> v;
		int last = 1;
		for(int x=2;x<=2*n;x++){
			if(arr[last] < arr[x]){
				v.push_back(x-last);
				last = x;
			}
		}
		v.push_back(2*n-last+1);
		
		bool table[2*n+1][2*n+1];
		fill(table[0], table[2*n+1], false);
		
		table[0][0] = true;
		
		for(int x=1;x<=v.size();x++){
			for(int y=1;y<=n;y++){
				table[x][y] = table[x-1][y];
				if(v[x-1] <= y && table[x-1][y-v[x-1]]){
					table[x][y] = true;
				}
			}
		}
		
		if(table[v.size()][n]){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

