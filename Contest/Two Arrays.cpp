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
		int n, t;
		cin >> n >> t;
		
		int data[n];
		for(int x=0;x<n;x++) cin >> data[x];
		
		unordered_map<int, int> mpC, mpD;
		mpC[data[0]]++;
		
		cout << "0";
		for(int x=1;x<n;x++){
			if(t-data[x] < 0){
				mpC[data[x]]++;
				data[x] = 0;
				cout << " 0";
			}
			if(mpC[t-data[x]] > mpD[t-data[x]]){
				mpD[data[x]]++;
				cout << " 1";
			} else {
				mpC[data[x]]++;
				cout << " 0";
			}
		}	
		cout << "\n";
	}
	
    return 0;
}

