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

ull pr[1001][1001];

ull mm(ull a, ull b) { 
    ull res = 0;
    a = a % mod; 
    while (b > 0) { 
        if (b % 2 == 1) res = (res + a) % mod; 
        a = (a * 2) % mod; 
        b /= 2; 
    } 

    return res % mod; 
} 

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	pr[0][0] = 1;
	pr[1][0] = pr[1][1] = 1;
	
	for(short x=2;x<=1000;x++){
		pr[x][0] = 1;
		for(short y=1;y<=x;y++){
			pr[x][y] = mm(x * 1ll, pr[x-1][y-1]);
		}
	}
	
	int n, x, pos;
	cin >> n >> x >> pos;
	
	int great = 0, less = 0;
	short state[n];
	fill(state, state+n, 0);
	
	int left = 0, right = n;
	while(left < right){
		int mid = (left + right)/2;
//		cout << "went to " << mid << " (" << left << "|" << right << ")\n";
		if(mid == pos){
			left = mid + 1;
		} else if(mid > pos){
			state[mid] = 1;
			right = mid;
			great++;
		} else {
			state[mid] = -1;
			left = mid + 1;
			less++;
		}
	}
	
	if(n-x < great || x-1 < less){
		cout << "0\n";
		return 0;
	}
//	for(int x=0;x<n;x++){
//		if(x> 0 ) cout << " ";
//		cout << state[x];
//	}
//	cout << "\n";
//	cout << great << " | " << less << "\n";
	cout << mm(mm(pr[n-x][great], max(1ull, pr[x-1][less])), pr[n-great-less-1][n-great-less-1]) << "\n";
	
    return 0;
}

