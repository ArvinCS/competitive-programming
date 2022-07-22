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
	
	bool notSorted;
	for(ui x=0;x<n;x++){
		cin >> data[x];
	}
	
	vector<pair<int, int>> segments;
	int cnt = 0, left = 0, right = 0;
	
	for(ui x=1;x<n;x++){
		if(segments.size() > 1) break;
		if(data[x] > data[x-1]){
			if(cnt != 0){
				segments.push_back({left, right});
				cnt = 0;
			}
		} else {
			if(cnt == 0) left = x-1;
			right = x;
			cnt++;
		}
	}
	
	if(cnt != 0){
		segments.push_back({left, right});
	}
//	cout << segments.size() << "\n";
	if(segments.size() <= 1){
		if(segments.size() == 1){
			int left = segments[0].first, right = segments[0].second;
			while(left < right){
				int tmp = data[left];
				data[left] = data[right];
				data[right] = tmp;
				left++;
				right--;
			}
			for(int x=1;x<n;x++){
				if(data[x] <= data[x-1]){
					cout << "no\n";
					return 0;
				}
			}
			cout << "yes\n";
			cout << segments[0].first + 1 << " " << segments[0].second + 1 << "\n";
		} else {
			cout << "yes\n";
			cout << "1 1\n";
		}
	} else {
		cout << "no\n";
	}
	
    return 0;
}
