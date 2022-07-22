#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxRemain = 2;
const ll mod = 1e9+7;
const int maxN = 205;

vector<int> v[maxRemain];
ll table[maxN][maxN][maxN][2], new_table[maxN][maxN][maxN][2];
// removed idx A

void madd(ll &a, ll b){
	a += b;
	if(a >= mod) a -= mod;
}

int count_arrangements(string A, string B, string C) {
	int n = A.length();
	int rem[n], carry[n];
	fill(rem, rem+n, 0);
	fill(carry, carry+n, 0);
	
	int cnt[2][2], zero[2][2];
	fill(cnt[0], cnt[2], 0);
	fill(zero[0], zero[2], 0);
	
	ll ans = 0;	
		
	for(int x=0;x<n;x++){
		int sum = (A[x] - '0') + (B[x] - '0');
		rem[x] = (((C[x] - '0') - sum)%10+10)%10;
		carry[x] = (sum+rem[x] >= 10 ? 1 : 0);
		
		if(rem[x] > 1) return 0;
		cnt[carry[x]][rem[x]]++;
		
		if(A[x] == '0' || B[x] == '0' || C[x] == '0'){
			zero[carry[x]][rem[x]]++;
		}
		
		v[rem[x]].push_back(x);
	}
	
	// ....[remain]
	fill(**table[0], **table[n+1], 0);
	
	if(cnt[0][1] > 0) table[1][0][0][1] = cnt[0][1]-zero[0][1];
	if(cnt[0][0] > 0) table[0][0][0][0] = cnt[0][0]-zero[0][0];
	
	for(int x=1;x<n;x++){
		fill(**new_table[0], **new_table[n+1], 0);
		for(int b=0;b<=cnt[0][1];b++){
			if(b > x) continue;
			for(int c=0;c<=cnt[1][0];c++){
				if(b+c > x) continue;
				for(int d=0;d<=cnt[1][1];d++){
					if(b+c+d > x) continue;
					
					int a = x-b-c-d;
					for(int i=0;i<2;i++){
						if(i == 0){
							if(a < cnt[0][0]) madd(new_table[b][c][d][0], table[b][c][d][i] * (cnt[0][0]-a) % mod);
							if(b < cnt[0][1]) madd(new_table[b+1][c][d][1], table[b][c][d][i] * (cnt[0][1]-b) % mod);
						} else {
							if(c < cnt[1][0]) madd(new_table[b][c+1][d][0], table[b][c][d][i] * (cnt[1][0]-c) % mod);
							if(d < cnt[1][1]) madd(new_table[b][c][d+1][1], table[b][c][d][i] * (cnt[1][1]-d) % mod);
						}
					}
				}
			}
		}

		for(int b=0;b<=cnt[0][1];b++){
			for(int c=0;c<=cnt[1][0];c++){
				for(int d=0;d<=cnt[1][1];d++){
					for(int i=0;i<2;i++){
						table[b][c][d][i] = new_table[b][c][d][i];
						if(x == n-1){
							madd(ans, table[b][c][d][i]);
						}
					}
				}
			}
		}
	}
	return ans;
}

int main(){
	string a, b, c;
	cin >> a >> b >> c;
	
	cout << count_arrangements(a, b, c) << "\n";
}
