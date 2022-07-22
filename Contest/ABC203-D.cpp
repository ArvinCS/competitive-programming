#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n, k;
	cin >> n >> k;
	
	int data[n][n];
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			cin >> data[x][y];
		}
	}
	
	int mn = inf_int;
	for(int x=0;x+k<=n;x++){
		ordered_set st;
		for(int y=0;y<n;y++){
			if(y-k >= 0){
				for(int z=0;z<k;z++){
					st.erase(st.find(data[x+z][y-k]));
				}
			}
			for(int z=0;z<k;z++){
				st.insert(data[x+z][y]);
			}
			
			if(y >= k-1) mn = min(mn, *(st.find_by_order((k*k+1)/2-1)));
		}
	}
	cout << mn << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

