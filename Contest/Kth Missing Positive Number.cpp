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

	int n, k;
	cin >> n >> k;
	
	vector<int> arr;
	for(int x=0;x<n;x++){
		int tmp;
		cin >> tmp;
		
		arr.push_back(tmp);
	}
	
	if(arr[0]-1 >= k){
		cout << k << "\n";
		return 0;
	}
	
	int cnt = arr[0]-1;
	for(int x=1;x<n;x++){
//		cout << "-" << cnt << "\n";
		if(arr[x]-1 != arr[x-1]){
			int diff = arr[x]-arr[x-1]-1;
			
			if(cnt+diff >= k){
				cout << arr[x-1]+k-cnt << "\n";
				return 0;
			}
			cnt += diff;
		}
//		cout << "---" << cnt << "\n";
	}
	cout << arr[n-1]+(k-cnt) << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

