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
	
	short t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int data[n], cnt[n+1], diff = 0;
		fill(cnt, cnt+n+1, 0);
		
		for(int x=0;x<n;x++){
			cin >> data[x];
			if(cnt[data[x]] == 0) diff++;
			cnt[data[x]]++;
		}
		
		int maxDup = 1, maxCnt = 1;
		for(int x=1;x<=n;x++){
			if(cnt[x] > maxDup){
				maxDup = cnt[x];
				maxCnt = 1;
			} else if(cnt[x] == maxDup){
				maxCnt++;
			}
		}
		
		if(maxDup == n){
			cout << "0\n";
		} else if(maxDup == 2){
			cout << diff-1 << "\n";
		} else {
			cout << (n-maxCnt)/(maxDup-1) - 1 << "\n";
		}
//		cerr << diff << " - " << maxDup << "\n";
	}
	
    return 0;
}

