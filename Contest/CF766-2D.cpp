#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1e9 + 7;
const int maxA = 1e6 + 5;

ll cnt[maxA], freq[maxA];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	fill(cnt, cnt+maxA, 0);
	fill(freq, freq+maxA, 0);
	
	int n;
	cin >> n;
	
	for(int x=0;x<n;x++){
		int val;
		cin >> val;
		
		freq[val]++;
	}
	
	ll ans = 0;
	for(int x=maxA-5;x>=1;x--){
		ll sum = 0;
		ll cnt2 = 0;
		for(int y=1;y*x<maxA;y++){
			cnt2 += freq[y*x];
		}
		
		sum += cnt2*(cnt2-1)/2;
		
		for(int y=2;y*x<maxA;y++){
			sum -= cnt[y*x];
		}
		
		cnt[x] = sum;
		
		if(cnt[x] > 0 && freq[x] == 0){
			ans++;
			cnt[x] += cnt2;
			freq[x]++;
		}
	}
	
	cout << ans << "\n";
    return 0;
}

