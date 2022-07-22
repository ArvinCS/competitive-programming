#include <bits/stdc++.h>

using namespace std;

#define ll long long


const int mod = 1e9 + 7;
const int maxN = 702;

ll dp[maxN][maxN];
int lst[maxN][2*maxN+1];
vector<int> A;

void chadd(ll &a, ll b){
	if(b >= mod) b -= mod;
	
	a += b;
	if(a >= mod) a -= mod;
	if(a < 0) a += mod;
}

ll solve(int l, int r) { // O(N^4)
	int N = A.size();
	if(dp[l][r] != -1) return dp[l][r];
	if(A[l] > 0 || A[r] < 0 || -A[l] == A[r]) return dp[l][r] = 0;
	
	ll ans = 1, extra = 0;
	if(l > 0 && lst[l-1][A[l]+N] >= 0){
		extra = 0;
		for(int l2=l-1;l2>=0;l2--){
			for(int r2=l-1;r2>l2;r2--){
				if(r2 < lst[l-1][A[l]+N]) break;
				if(abs(A[r2]) != abs(A[l])){
//					if(l == 4 && r == 6) cout << l2 << " " << r2 << " " << solve(l2, r2) << "\n";
					chadd(extra, solve(l2, r2));
				}
			}
		}
	} else {
		extra = 1;
		for(int l2=0;l2<l;l2++){
			for(int r2=l2+1;r2<l;r2++){
				if(abs(A[r2]) != abs(A[l])){
					chadd(extra, solve(l2, r2));
				}
			}
		}
	}
	
	if(r > 0 && lst[r-1][A[r]+N] > l){
		ll sum = 0;
		for(int l2=r-1;l2>l;l2--){
			for(int r2=r-1;r2>l2;r2--){
				if(r2 < lst[r-1][A[r]+N]) break;
				if(abs(A[l]) != abs(A[l2]) && abs(A[r2]) != abs(A[r])){
					chadd(sum, solve(l2, r2));
				}
			}
		}
		
		ans *= sum;
		ans %= mod;
	} else {
		ll sum = 1;
		
		for(int l2=l+1;l2<r;l2++){
			for(int r2=l2+1;r2<r;r2++){
				if(abs(A[l]) != abs(A[l2]) && abs(A[r2]) != abs(A[r])){
					chadd(sum, solve(l2, r2));
				}
			}
		}
		
		ans *= sum;
		ans %= mod;
	}
	
//	cout << l << " " << r << " -> " << (ans * extra) % mod << " " << ans << " " << extra << "\n";
	return dp[l][r] = (ans * extra) % mod;
}

int main(){
	int N;
	cin >> N;
	
	for(int x=0;x<N;x++){
		int val;
		cin >> val;
		
		A.push_back(val);
	}	
	
	fill(dp[0], dp[maxN], -1);
	
	// dp[l][r]
	// make sure for [l, r]
	// the last pos of Ar which >= l must be taken
	
	for(int x=0;x<N;x++){
		for(int y=0;y<=2*N;y++){
			lst[x][y] = (x > 0 ? lst[x-1][y] : -1);	
		}
		lst[x][A[x]+N] = x;
	}
	
	ll ans = 0;
	for(int le=2;le<=N;le++){
		for(int l=0;l<N;l++){
			int r = l+le-1;
			if(r >= N) break;
			
			solve(l, r);
//			if(dp[l][r] > 0){
//				cout << l << " " << r << " -> " << dp[l][r] << "\n";
//			}
			chadd(ans, dp[l][r]);
		}
	}
	
	cout << ans << "\n";
	return 0;
}
