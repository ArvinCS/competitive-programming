#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	long long data[n];
	for(int x=0;x<n;x++) cin >> data[x];
	
	int ans = 1;
	vector<int> left(n,1), right(n,1);
	
	for(int x=n-2;x>=0;x--){
		if(data[x] < data[x+1]) right[x] = right[x+1] + 1;
		ans = max(ans, right[x]);
	}
	
	for(int x=1;x<n;x++){
		if(data[x-1] < data[x]) left[x] = left[x-1] + 1;
		ans = max(ans, left[x]);
	}
	
	for(int x=0;x<n-2;x++){
		if(data[x] < data[x+2]) ans = max(ans, left[x] + right[x+2]);
	}
	
	cout << ans << "\n";
    return 0;
}
