#include <iostream>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

#define mod 1000000007

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us n;
	cin >> n;
	
	us data[n];
	for(us x=0;x<n;x++){
		cin >> data[x];
	}
	
	ull len[n], cnt[n];
	for(us x=0;x<n;x++){
		len[x] = 1;
		cnt[x] = 1;
	}
	
	for(us x=1;x<n;x++){
		for(us y=0;y<x;y++){
			if(data[y] < data[x]){
				if(len[x] < len[y] + 1){
					cnt[x] = cnt[y];
					len[x] = len[y] + 1;
				} else if(len[x] == len[y] + 1) cnt[x] += cnt[y];
				cnt[x] %= mod;
			}
		}
	}
	
	ull ans1 = 0, ans2 = 0;
	for(us x=0;x<n;x++){
		if(ans1 < len[x]){
			ans1 = len[x];
			ans2 = cnt[x];
		} else if(ans1 == len[x]){
			ans2 += cnt[x];
		}
		ans2 %= mod;
	}
	cout << ans1 << " " << ans2 << "\n";
    return 0;
}

