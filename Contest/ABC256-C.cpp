#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int row[3], col[3];
	for(int x=0;x<3;x++){
		cin >> row[x];
	}
	for(int x=0;x<3;x++){
		cin >> col[x];
	}
	
	ll ans = 0;
	for(int a=1;a<=30;a++){
		for(int b=1;b<=30;b++){
			for(int c=1;c<=30;c++){
				for(int d=1;d<=30;d++){
					bool valid = true;
					if(row[0]-a-b <= 0){
						valid = false;
					}
					if(row[1]-c-d <= 0){
						valid = false;
					}
					if(col[0]-a-c <= 0){
						valid = false;
					}
					if(col[1]-b-d <= 0){
						valid = false;
					}
					
					// a b e
					// c d f
					// g h i
					int e = row[0]-a-b;
					int f = row[1]-c-d;
					int g = col[0]-a-c;
					int h = col[1]-b-d;
					int i = col[2]-e-f;
					
					if(col[2]-e-f <= 0){
						valid = false;
					}
					if(row[2]-g-h <= 0){
						valid = false;
					}
					
					if(valid && (a+b+e == row[0]) && (c+d+f == row[1]) && (g+h+i == row[2]) && (a+c+g == col[0]) && (b+d+h == col[1]) && (e+f+i == col[2])){
						ans++;
					}
				}
			}
		}
	}
	
	cout << ans << "\n";
    return 0;
}

