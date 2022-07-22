#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		int n,a, maxValue = 0;
		cin >> n >> a;
		bool filled[201] = { false };
		for(int x=0;x<n;x++){
			int value;
			cin >> value;
			filled[value] = true;
			maxValue = max(maxValue, value);
		}
		
		for(int x=1;x<=200 && a != 0;x++){
			if(!filled[x]){
				filled[x] = true;
				a--;
				maxValue = max(maxValue, x);
			}
		}
		
		int count = 0;
		for(int x=1;x<=maxValue;x++){
			if(filled[x]){
				count++;	
			} else {
				break;
			}
		}
		cout << count << "\n";
	}
    return 0;
}
