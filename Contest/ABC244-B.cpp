#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	string t;
	cin >> t;
	
	int posX = 0, posY = 0;
	int dir = 0;
	
	for(int x=0;x<n;x++){
		if(t[x] == 'R'){
			dir++;
			dir %= 4;
		} else {
			if(dir == 0){
				posX++;
			} else if(dir == 1){
				posY--;
			} else if(dir == 2){
				posX--;
			} else {
				posY++;
			}
		}
	}
	
	cout << posX << " " << posY << "\n";
    return 0;
}

