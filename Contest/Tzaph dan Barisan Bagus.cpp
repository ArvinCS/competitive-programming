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

const int maxN = 1e5 * 2 + 5;
int data[maxN], pre[maxN], nex[maxN], dist[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	for(int x=0;x<n;x++){
		cin >> data[x];
		pre[x] = -1;
		nex[x] = n;
	}
	
	for(int x=0;x<n;x++){
		dist[x] = (pre[data[x]] == -1 ? x : x-pre[data[x]]);
		if(pre[data[x]] >= 0) nex[pre[data[x]]] = x;
		pre[data[x]] = x;
	}
	
	for(int x=0;x<n;x++){
		if(x > 0) cout << " ";
		cout <<"("<<x <<")"<< nex[x];
	}
	cout << "\n";
	
	for(int x=0;x<n;x++){
		int maxDist = max(dist[x], nex[x]);
		if(maxDist < n-1){
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
    return 0;
}

