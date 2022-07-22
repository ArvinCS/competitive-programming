#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int badges[n];
	for(int x=0;x<n;x++){
		cin >> badges[x];
	}
	
	sort(badges, badges+n);
	
	int cost = 0;
	for(int x=1;x<n;x++){
		if(badges[x] == badges[x-1]){
			badges[x]++;
			cost++;
		} else if(badges[x] < badges[x-1]){
			int temp = badges[x-1] - badges[x] + 1;
			badges[x] += temp;
			cost += temp;
		}
	}
	
	cout << cost << "\n";
    return 0;
}
