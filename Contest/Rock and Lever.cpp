#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
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
		
		ui data[n];
		for(ui x=0;x<n;x++){
			cin >> data[x];
		}
		
		sort(data, data+n);

		ull ans = 0, cnt = 0;
		for(ui x=0;x<n-1;x++){
			if((data[x] & data[x+1]) >= (data[x] ^ data[x+1])){
				cnt++;
			} else {
				if(cnt > 0) ans += max((cnt * (cnt+1))/2, cnt);
				cnt = 0;
			}
		}
		if(cnt > 0){
//			cout << "cnt: " << cnt << "\n";
			ans += max((cnt * (cnt+1))/2, 1ull);
		}
		cout << ans << "\n";
	}
	
    return 0;
}

