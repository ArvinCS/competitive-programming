#include <iostream>

using namespace std;

int findJenis(int n, int q, int jenis[]){
	int l1 = 0, h1 = n-1;
	int ans = -1;
	while(ans == -1){
		int mid = (l1 + h1)/2;
		//cout << l1 << " " << h1 << "\n";
		if(jenis[mid] < q){
			l1 = mid+1;
		} else if(mid > 0 && jenis[mid] > q && jenis[mid-1] >= q){
			h1 = mid-1;
		} else {
			ans = mid;
		}
	}
	return ans + 1;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n,q;
	cin >> n;
	long long value = 0;
	int jenis[n];
	for(int x=0;x<n;x++){
		int input;
		cin >> input;
		value += input;
		jenis[x] = value;
	}
	cin >> q;
	for(int x=0;x<q;x++){
		int input;
		cin >> input;
		cout << findJenis(n,input,jenis) << "\n";
	}
    return 0;
}
