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
	
	while(t--){
		int n, k;
		cin >> n >> k;
		
		int pos[k];
		for(int x=0;x<k;x++){
			cin >> pos[x];
		}
		
		sort(pos, pos+k);
		
		int cnt = 0, ans = 0;
		for(int x=k-1;x>=0;x--){
			if(pos[x] > cnt){
				cnt += n-pos[x];
				ans++;
			}
		}
		
		cout << ans << "\n";
	}

    return 0;
}

