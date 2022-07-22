#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

bool customSort(pair<ui, us> a, pair<ui, us> b){
	return a.first < b.first && a.second != b.second;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	us t;
	cin >> t;
	
	while(t--){
		us n;
		cin >> n;
		
		bool sorted = true;
		ui data[n], fcnt = 0, scnt = 0;
		for(us x=0;x<n;x++){
			cin >> data[x];
			if(x > 0 && data[x] < data[x-1]) sorted = false;
		}
		
		us tmp;
		for(us x=0;x<n;x++){
			cin >> tmp;
			if(tmp == 1){
				scnt++;
			} else fcnt++;
		}
		
		if(sorted || (fcnt != 0 && scnt != 0)){
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
	
    return 0;
}
