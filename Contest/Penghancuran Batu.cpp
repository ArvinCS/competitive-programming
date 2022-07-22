#include <iostream>
#include <vector>

using namespace std;

short inf = 10001;

unsigned long long solve(int n, vector<short> data){
	unsigned long long ans = 0;
	while(data.size() > 1){
		for(int x=0;x<data.size();x++){
			short left = (x-1 >= 0 ? data[x-1] : inf);
			short right = (x+1 < data.size() ? data[x+1] : inf);
			if(left >= data[x] && data[x] <= right){
				ans += min(left, right);
				data.erase(data.begin() + x);
				break;
			}
		}
	}
	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	vector<short> data;
	for(int x=1;x<=n;x++){
		short tmp;
		cin >> tmp;
		data.push_back(tmp);
	}
    
	cout << solve(n, data) << "\n";
	return 0;
}
