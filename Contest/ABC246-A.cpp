#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int x[3], y[3];
	for(int i=0;i<3;i++){
		cin >> x[i] >> y[i];
	}
	
	map<int, int> mpX, mpY;
	for(int i=0;i<3;i++){
		mpX[x[i]]++;
		mpY[y[i]]++;
	}
	
	int ansX = -1, ansY = -1;
	for(auto p : mpX){
		if(p.second&1) ansX = p.first;
	}
	for(auto p : mpY){
		if(p.second&1) ansY = p.first;
	}
	
	cout << ansX << " " << ansY << "\n";
    return 0;
}

