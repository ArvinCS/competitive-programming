#include <bits/stdc++.h>

using namespace std;

#define ll long long

void draw(int r){
	for(int x=-r;x<=r;x++){
		int y = round(sqrt(r*r - x*x));
		
		cout << x << " " << y << "\n";
		cout << x << " " << -y << "\n";
		cout << y << " " << x << "\n";
		cout << -y << " " << x << "\n";
		cout << "...\n";
	}
	cout << "====\n";
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	draw(2);
	
    return 0;
}

