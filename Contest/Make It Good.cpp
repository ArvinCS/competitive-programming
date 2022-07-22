#include <iostream>
#include <vector>

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
		ull n, tmp;
		cin >> n;
		
		vector<ull> data;
		ull cnt[n];
		for(ull x=0;x<n;x++){
			cin >> tmp;
			data.push_back(tmp);
			cnt[x] = 1;
			if(x > 0){
				cnt[x] += (data[x-1] <= data[x] ? cnt[x-1] : 0);
			}
		}

		ll bestIndex = n-1;
		for(ll x=n-2;x>=0;x--){
			if(data[x] >= data[x+1]){
				bestIndex = x;
			} else break;
		}
		cout << n - (cnt[bestIndex] + (n-bestIndex-1)) << "\n";
	}
	
    return 0;
}
