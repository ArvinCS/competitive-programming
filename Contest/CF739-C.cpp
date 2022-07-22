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
		ll k;
		cin >> k;
		
		ll left = 1, right = inf_int;
		ll col = 1;
		while(left <= right){
			ll mid = (left+right) >> 1;
			
			ll sum = 1 + (mid-1) + (mid-1)*(mid-2);
			if(sum <= k){
				col = max(col, mid);
				left = mid+1;
			} else {
				right = mid-1;
			}
		}
		
		ll sum = 1 + (col-1) + (col-1)*(col-2);
		ll row = 0;
		if(k-sum < col){
			row = k-sum+1;
		} else {
			row = col;
			col = row-(k-(sum+row-1));
		}
		
		cout << row << " " << col << "\n";
	}

    return 0;
}

