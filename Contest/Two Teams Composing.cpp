#include <iostream>

using namespace std;

#define ull unsigned long long
#define ll long long
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int tmp, cnt[n+1], distinct = 0;
		fill(cnt, cnt+n+1, 0);
		
		for(int x=0;x<n;x++){
			cin >> tmp;
			cnt[tmp]++;
			if(cnt[tmp] == 1){
				distinct++;
			}
		}
		
		int maxCount = 0;
		for(int x=1;x<=n;x++){
			maxCount = max(maxCount, cnt[x]);
		}
		
		cout << max(min(distinct, maxCount-1), min(distinct-1, maxCount)) << "\n";
	}
	
    return 0;
}
