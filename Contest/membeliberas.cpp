#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool descend(float a, float b){
	return a > b;	
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, t;
	cin >> n >> t;
	long double berat[n];
	long double harga[n];
	int total = 0;
	for(int x=0;x<n;x++){
		int input;
		cin >> input;
		berat[x] = input;
		total += input;
	}
	
	for(int x=0;x<n;x++){
		cin >> harga[x];
	}
	
	vector<long double> beras(total);
	int a = 0;
	for(int x=0;x<n;x++){
		long double perkilo = harga[x]/berat[x];
		for(int y=0;y<berat[x];y++){
			beras[a] = perkilo;
			a++;
		}
	}
	
	// 4 3 3 3 2.5 2.5 1 1 1 1 0.5 0.5 0.5 0.5 0.5
	
	sort(beras.begin(), beras.end(), descend);
	long double ans = 0;
	for(int x=0;x<t && x < total;x++) ans += beras.at(x);
	cout << setprecision(5) << fixed << ans << "\n";
    return 0;
}
