#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, b;
	cin >> n >> b;
	int height[n];
	for(int x=0;x<n;x++){
		cin >> height[x];
	}
	
	sort(height, height+n);
	int currentHeight = 0;
	int counter = 0;
	for(int x=n-1;x>=0;x--){
		if(currentHeight < b){
			currentHeight += height[x];
			counter++;
		} else {
			break;
		}
	}
	
	cout << counter << "\n";
    return 0;
}
