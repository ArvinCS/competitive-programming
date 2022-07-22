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

const int maxN = 105;
const int maxSum = 2001*maxN;

bool table[maxN][maxSum];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	int sum = 0;
	int data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
		sum += data[x];
	}
	
	if(sum&1){
		cout << "0\n";
		return 0;
	}
	
	fill(table[0], table[maxN], false);
	for(int x=0;x<=n;x++) table[x][0] = true;
	for(int x=1;x<=n;x++){
		for(int i=1;i*2<=sum;i++){
			if(i < data[x-1]) table[x][i] = table[x-1][i];
			else table[x][i] = (table[x-1][i] || table[x-1][i-data[x-1]]);
		}
	}
	if(!table[n][sum/2]){
		cout << "0\n";
		return 0;
	}
	
	for(int x=0;x<n;x++){
		if((sum-data[x])&1){
			cout << "1\n";
			cout << x+1 << "\n";
			return 0;
		}
		if(!table[n][(sum-data[x])/2]){
			cout << "1\n";
			cout << x+1 << "\n";
			return 0;
		}
	}
	
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

