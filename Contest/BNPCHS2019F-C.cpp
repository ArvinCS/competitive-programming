#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int t;
	cin >> t;
	
	for(int i=1;i<=t;i++){
		int n;
		string s;
		cin >> n >> s;
		
		int cnt[2];
		cnt[0] = cnt[1] = 0;
		
		ll ans = -1;
		for(int x=0;x<n;x++){
			cnt[(s[x] - '0')]++;
		}
		
		if((cnt[0]-1)/2 <= cnt[1]){
			ans = 0;
			
			bool found = true;
			int cur = 0;
			for(int x=0;x<n;x++){
				if(s[x] == '1'){
					ans += (cur-found)/2;
					if(cur > 1) found = false;
					cur = 0;
				} else {
					cur++;
				}
			}
			
			ans += (cur-found)/2;
			if(cur > 1) found = false;
			cur = 0;
		}
		
		cout << "Case #" << i << ": " << ans << "\n";
	}

    return 0;
}

