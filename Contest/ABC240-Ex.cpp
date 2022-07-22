#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	string tmp(n, 'a');
	
	int left = 1, right = 5000;
	while(left <= right){
		int mid = (left+right) >> 1;
		
		string table[mid+1][n+1];
		fill(table[0], table[mid+1], tmp);
		
	}
	
    return 0;
}

