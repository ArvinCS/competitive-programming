#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Cokelat {
	unsigned long long harga, bebek;
};

bool sortCokelat(Cokelat a, Cokelat b){
	return a.harga < b.harga;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	unsigned long long n, d;
	cin >> n >> d;
	
	Cokelat list[n];
	
	for(int x=0;x<n;x++){
		cin >> list[x].harga >> list[x].bebek;
	}
	
	sort(list, list+n, sortCokelat);
	
	int result = 0;
	for(int x=0;x<n;x++){
		while(list[x].bebek-- && list[x].harga <= d){
			d -= list[x].harga;
			result++;
		}
	}
	
	cout << result << "\n";
    return 0;
}
