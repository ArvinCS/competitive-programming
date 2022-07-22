#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n,k;
	cin >> n >> k;
	
	int data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	sort(data, data+n);
	
	int counter = 0;
	int max = 0;
	int modus = 0;
	for(int x=0;x<n;x++){
		if(data[x] == data[x+1]){
			counter++;
			if(counter > max){
				max = counter;
				modus = data[x];
			}
		} else {
			counter = 1;
		}
	}
	
	int ans = 0;
	int l = 0, h = n-1;
	cout << "h: " << h << "\n";
	while(l < h && max < k){
		while(data[l] == modus && l < h){
			l++;
		}
		while(data[h] <= modus && l < h){
			h--;
		}
		cout << l << " " << h << "\n";
		int l_range = modus - data[l];
		int h_range = abs(data[h] - modus);

		if(l_range > 0 && l_range <= h_range){
			cout << l << " increase \n";
			data[l]++;
			if(data[l] == modus) max++;
			ans++;
		} else {
			cout << h << " decrease \n";
			data[h]--;
			if(data[h] == modus) max++;
			ans++;
		}
		cout << data[0] << data[1] << data[2] << data[3] << data[4] << data[5] << "\n";
		cout << data[l] << " " << data[h] << "\n";
	}
	cout << ans << "\n";
    return 0;
}
