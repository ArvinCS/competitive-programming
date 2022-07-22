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
	
	int n;
	cin >> n;
	
	int data[n];
	for(int x=0;x<n;x++) cin >> data[x];
	
	sort(data, data+n);
	
	int best = 0, bestCnt = 0;
	for(int x=2;x<=data[n-1];x++){
		int cnt = 0;
		for(int i=0;i<n;i++){
			if(data[i]%x == 0) cnt++;
		}
		if(cnt >= bestCnt){
			bestCnt = cnt;
			best = x;
		}
	}
	cout << best << "\n";
	
    return 0;
}

