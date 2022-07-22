#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

bool sortName(string a, string b){
	for(int x=0;x<max(a.length(), b.length());x++){
		if(a[x] == b[x]) continue;
		return a[x] < b[x];
	}
	if(a.length() < b.length()) return true;
	else if(a.length() > b.length()) return false;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	string bebeks[n];
	for(int x=0;x<n;x++){
		string name;
		cin >> name;
		bebeks[x] = name;
		if(n == 1) {
			cout << "1\n";
		} else {
			sort(bebeks, bebeks+x+1, sortName);
			for(int y=0;y<=x;y++){
				if(bebeks[y] == name){
					cout << y+1 << "\n";
					break;
				}
			}
		}
	}
    return 0;
}
