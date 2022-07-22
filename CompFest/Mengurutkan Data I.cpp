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
	
	us n;
	cin >> n;
	
	ui data[n];
	for(us x=0;x<n;x++) cin >> data[x];
	
	sort(data, data+n);
	
	cout << data[0];
	for(us x=1;x<n;x++){
		cout << " " << data[x];	
	}
	cout << "\n";
	
    return 0;
}

