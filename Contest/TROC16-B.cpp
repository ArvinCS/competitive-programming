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

	int n, m;
	cin >> n >> m;
	
	int data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	sort(data, data+n);
	
	vector<int> v;
	for(int x=1;x<n;x++){
		if(data[x-1] != data[x]){
			v.push_back(data[x]-data[x-1]);
		}
	}
	if(n > 0 && data[n-1] != data[0]){
		v.push_back(data[0]+(m-data[n-1]));
	}
	
	int sum = 0, mx = 0;
	for(int x=0;x<v.size();x++){
		sum += v[x];
		mx = max(mx, v[x]);
	}
	
	cout << sum-mx << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

