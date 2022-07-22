#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	long long vektor[2][n];
	for(int x=0;x<2;x++){
		for(int y=0;y<n;y++){
			cin >> vektor[x][y];
		}	
	}
	
	sort(vektor[0], vektor[0]+n, greater<int>());
	sort(vektor[1], vektor[1]+n);
	
	long long result = 0;
	for(int x=0;x<n;x++){
		result += vektor[0][x] * vektor[1][x];
	}
	
	cout << result << "\n";
    return 0;
}
