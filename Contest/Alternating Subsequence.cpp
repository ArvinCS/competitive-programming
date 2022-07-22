#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	for(int x=1;x<=t;x++){
		int n;
		cin >> n;
		
		int numbers[n];
		for(int x=0;x<n;x++) cin >> numbers[x];
		
		bool positive = true;
		int lastMax = 0;
		long long sum = 0;
		for(int x=0;x<n;x++){
			bool currentPositive = numbers[x] > 0;
			if(currentPositive == positive){
				if(lastMax != 0){
					lastMax = max(lastMax, numbers[x]);
				} else {
					lastMax = numbers[x];
				}
			} else {
				sum += lastMax;
				positive = currentPositive;
				lastMax = numbers[x];
			}
		}
		sum += lastMax;
		cout << sum << "\n";
	}
	
    return 0;
}
