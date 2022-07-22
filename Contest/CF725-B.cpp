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
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int data[n], prefix[n];
		for(int x=0;x<n;x++){
			cin >> data[x];
		}
		
		sort(data, data+n, greater<int>());
		
		for(int x=0;x<n;x++){
			prefix[x] = (data[x] + (x > 0 ? prefix[x-1] : 0));
		}
		
		if(prefix[n-1]%n != 0){
			cout << "-1\n";
			continue;
		}
		
		int need = 0;
		for(int x=0;x<n;x++){
			need += max(prefix[n-1]/n - data[x], 0);
		}
		
		if(need == 0){
			cout << "0\n";
			continue;
		}
		
		int sum = 0;
		for(int x=0;x<n;x++){
			sum += data[x];
			need += prefix[n-1]/n;
			
			if(sum >= need){
				cout << x+1 << "\n";
				break;
			}
		}
	}
	
    return 0;
}



