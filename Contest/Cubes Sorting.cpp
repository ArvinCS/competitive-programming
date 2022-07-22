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
		int n;
		cin >> n;
		
		ui data[n], cnt = 0;
		for(ui x=0;x<n;x++) cin >> data[x];

//		int diff = 0;
		for(int x=n-2;x>=0;x--){
			for(ui y=x+1;y<n;y++){
				if(data[x] > data[y]){
					cnt++;
				} else {
					break;
				}
			}
		}
		
//		for(ui x=0;x<n;x++){
//			cout << data[x] << " ";
//		}
//		cout << "\n";
//		cout << "cost: " << cnt << "\n";
		if(cnt > ((n-1)*n)/2 - 1){
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}
	
    return 0;
}

