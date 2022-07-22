#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	int p[n][3];
	for(int x=0;x<n;x++){
		for(int y=0;y<3;y++){
			cin >> p[x][y];
		}
	}
	
	vector<int> v;
	for(int x=0;x<n;x++){
		int sum = 0;
		for(int y=0;y<3;y++){
			sum += p[x][y];
		}
		v.push_back(sum);
	}
	
	sort(v.begin(), v.end());
	
	for(int x=0;x<n;x++){
		int sum = 0;
		for(int y=0;y<3;y++){
			sum += p[x][y];
		}
		
		auto it = lower_bound(v.begin(), v.end(), sum+300+1);
		if(v.size()-(it - v.begin()) < k){
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
    return 0;
}

