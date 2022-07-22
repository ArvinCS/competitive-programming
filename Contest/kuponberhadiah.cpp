#include <iostream>
#include <cmath>
#include <bits/stdc++.h> 

using namespace std;

int n,x;

bool sorting(int a, int b){
	int temp1 = abs(a-x);
	int temp2 = abs(b-x);
	if(temp1 > temp2) return false;
	else if(temp1 == temp2) return a<b;
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n >> x;
	int coupons[n];
	for(int x=0;x<n;x++){
		cin >> coupons[x];
	}
	
	sort(coupons, coupons+n, sorting);
	
	cout << coupons[0] << "\n";
    return 0;
}
