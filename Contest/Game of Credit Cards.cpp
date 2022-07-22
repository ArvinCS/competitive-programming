#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	char sherlock[n], moriary[n];
	for(int x=0;x<n;x++) cin >> sherlock[x];
    for(int x=0;x<n;x++) cin >> moriary[x];
    
    sort(sherlock, sherlock+n);
    sort(moriary, moriary+n);
    
    int same = 0, more = 0;
    
    for(int x=0;x<n;x++){
    	if(moriary[x] >= sherlock[same]){
    		same++;
		}
		if(moriary[x] > sherlock[more]){
			more++;
		}
	}
	
	cout << (n-same) << "\n" << more << "\n";
	
	return 0;
}
