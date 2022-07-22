#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int b,g;
	
	cin >> b;
	int boys[b];
	for(int x=0;x<b;x++) cin >> boys[x];
	
	cin >> g;
	vector<int> girls;
	for(int x=0;x<g;x++){
		int input;
		cin >> input;
		girls.push_back(input);
	}
	
	sort(boys, boys+b);
	sort(girls.begin(), girls.end());
	
	int pair = 0;
	int lastGirl = 0;
	for(int x=0;x<b;x++){
		for(int y=lastGirl;y<girls.size();y++){
			if(abs(boys[x] - girls[y]) <= 1){
				girls.erase(girls.begin() + y);
				pair++;
				break;
			}
		}
	}
	
	cout << pair << "\n";
    return 0;
}
