#include <bits/stdc++.h>

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
	
	us t;
	cin >> t;
	
	while(t--){
		int n, k;
		cin >> n >> k;
		
		unordered_map<ll, int> mp;
		ll data[n];
		for(int x=0;x<n;x++){
			cin >> data[x];
			mp[data[x]]++;
		}
		
		int gift[k];
		for(int x=0;x<k;x++) cin >> gift[x];
		
		sort(data, data+n);
		sort(gift, gift+k);
		
		ll total = 0;
		int currK = 0, left = 0, right = n-1;
		while(currK < k && gift[currK] == 1){
			total += 2 * data[right--];
			currK++;
		}
		
		for(int x=k-1;x>=currK;x--){
			total += data[right--] + data[left++];
			gift[x] -= 2;
			
			while(gift[x] > 0){
				left++;
				gift[x]--;
			}
		}
		cout << total << "\n";
	}
	
    return 0;
}

