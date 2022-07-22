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
	
	ui n;
	cin >> n;
	
	ui data[n];
	for(ui x=0;x<n;x++){
		cin >> data[x];
	}
	
	sort(data, data+n);
	
	if(data[0] != data[n-1]){
		int i = 1, j = 1;
		while(data[i] == data[0]){
			i++;
		}
		
		while(data[n-1-j] == data[n-1]){
			j++;
		}
		
		cout << data[n-1] - data[0] << " " << i * 1ll * j << "\n";
	} else {
		cout << "0 " << n*1ll*(n-1)/2 << "\n";
	}
    return 0;
}
