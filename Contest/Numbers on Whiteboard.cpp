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
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		vector<int> data;
		for(int x=1;x<=n;x++){
			data.push_back(x);
		}
		
		vector<pair<int, int>> steps;
		
		cout << "2\n";
		while(data.size() > 2){
			for(int x=data.size()-2;x>=0;x--){
				if((data[x] % 2) == (data.back() % 2)){
					cout << data[x] << " " << data.back() << "\n";
					data[x] = (data.back() + data[x] + 1)/2;
					data.pop_back();
					break;
				}
			}
		}
		cout << data.front() << " " << data.back() << "\n";
	}
	
    return 0;
}

