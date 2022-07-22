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
	
	int n, k;
	cin >> n >> k;

	for(int x=1;x<=k;x++){
		int curA = 0, curB = 0;
		for(int i=0;i<=9;i++){
			int tmp = n;
			while(tmp > 0){
				if(tmp % 10 == i){
					curA *= 10;
					curA += tmp % 10;
				}
				tmp /= 10;
			}
		}
		for(int i=9;i>=0;i--){
			int tmp = n;
			while(tmp > 0){
				if(tmp % 10 == i){
					curB *= 10;
					curB += tmp % 10;
				}
				tmp /= 10;
			}
		}
		
//		cout << curA << " " << curB << "\n";
		n = curB - curA;
	}
	
	cout << n << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

