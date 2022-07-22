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
	
	ui t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		us data[n];
		int one = 0, zero = 0;
		for(ui x=0;x<n;x++){
			cin >> data[x];
			if(data[x] == 1) one++;
			else zero++;
		}
		
		if(one % 2 == 1) one--;
		if(one > zero){
			cout << one << "\n";
			cout << "1";
			for(int x=1;x<one;x++) cout << " 1";
			cout << "\n";
		} else {
			cout << zero << "\n";
			cout << "0";
			for(int x=1;x<zero;x++) cout << " 0";
			cout << "\n";
		}
	}
	
    return 0;
}

