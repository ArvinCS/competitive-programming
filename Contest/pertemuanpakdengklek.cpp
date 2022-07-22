#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool sortNama(string a, string b){
	if(a.length() < b.length()) return true;
	else if(a.length() > b.length()) return false;
	else {
		for(int x=0;x<a.length();x++){
			if(a[x] == b[x]) continue;
			return a[x] < b[x];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	string nama[n];
	for(int x=0;x<n;x++){
		cin >> nama[x];
	}
	
	sort(nama, nama+n, sortNama);
	
	for(int x=0;x<n;x++){
		cout << nama[x] << "\n";
	}
	
    return 0;
}
