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

const int maxN = 1e9 + 5;

int dsu[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, q;
	cin >> n;
	
	int data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	cin >> q;
	
	int ask[q];
	for(int x=0;x<q;x++){
		cin >> ask[x];
	}
	
	
	ull cur = 0;
	
    return 0;
}

