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

int askAnd(int x, int y){
	cout << "and " << x << " " << y << endl;
	
	int ans;
	cin >> ans;
	
	return ans;
}

int askOr(int x, int y){
	cout << "or " << x << " " << y << endl;
	
	int ans;
	cin >> ans;
	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, k;
	cin >> n >> k;
	
	int ans[n];
	fill(ans, ans+n, 0);
	
	int tmp1 = askAnd(1, 2), tmp2 = askAnd(1, 3), tmp3 = askOr(1, 2), tmp4 = askOr(1, 3);
	int tmp5 = askAnd(2, 3);
	
	for(int x=30;x>=0;x--){
		int bit = (1 << x);
		if((bit&tmp1) || (bit&tmp2)){
			ans[0] |= bit;
		} else if((bit&tmp3) && (bit&tmp4)){
			if(!(bit&tmp5)){
				ans[0] |= bit;
			}
		}
	}
	
	for(int x=30;x>=0;x--){
		int bit = (1 << x);
		if(bit&tmp1){
			ans[1] |= bit;
		} else if(bit&tmp3){
			if(!(bit&ans[0])){
				ans[1] |= bit;
			}
		}
		
		if(bit&tmp2){
			ans[2] |= bit;
		} else if(bit&tmp4){
			if(!(bit&ans[0])){
				ans[2] |= bit;
			}
		}
	}
	
	for(int x=3;x<n;x++){
		int tmp1 = askAnd(1, x+1), tmp3 = askOr(1, x+1);
		
		for(int i=30;i>=0;i--){
			int bit = (1 << i);
			if(bit&tmp1){
				ans[x] |= bit;
			} else if(bit&tmp3){
				if(!(bit&ans[0])){
					ans[x] |= bit;
				}
			}
		}
	}
	
	sort(ans, ans+n);
	
	cout << "finish " << ans[k-1] << endl;
    return 0;
}
