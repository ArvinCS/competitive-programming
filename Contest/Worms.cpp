#include <iostream>

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
	
	int n, m, tmp;
	cin >> n;
	
	int pill[n];
	for(ui x=0;x<n;x++){
		cin >> pill[x];
		pill[x] += (x > 0 ? pill[x-1] : 0);
	}
	
	cin >> m;
	while(m--){
		cin >> tmp;
		int l = 0, r = n-1;
		while(l<=r){
			int mid = l + (r-l)/2;
			if(pill[mid] >= tmp && (mid > 0 ? pill[mid-1] : 0) < tmp){
				cout << mid + 1 << "\n";
				break;
			}
			
			if(pill[mid] > tmp){
				r = mid - 1;
			} else if(pill[mid] < tmp){
				l = mid + 1;
			}
		}
	}
    return 0;
}
