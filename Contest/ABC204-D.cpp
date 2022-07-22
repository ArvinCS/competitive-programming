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

const int maxN = 105, maxT = 1005;

bool table[maxN][maxN*maxT];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n;
	cin >> n;
	
	ll total = 0;
	int data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
		total += data[x];
	}
	
	fill(table[0], table[maxN], false);
	for(int x=0;x<=n;x++) table[x][0] = true;
	for(int x=1;x<=n;x++){
		for(int sum=1;sum<=maxN*maxT;sum++){
			table[x][sum] = table[x-1][sum];
			if(data[x-1] <= sum) table[x][sum] |= table[x-1][sum-data[x-1]];
		}
	}
	
	for(int sum=1;sum<=total;sum++){
		ll sum2 = total-sum;
		if(sum2 > sum) continue;
		
		if(table[n][sum] && table[n][sum2]){
			cout << sum << "\n";
			break;
		}
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

