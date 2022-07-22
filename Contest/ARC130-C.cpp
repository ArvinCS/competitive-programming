#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	string a, b;
	cin >> a >> b;
	
	int cntA[10], cntB[10];
	for(int x=0;x<10;x++) cntA[x] = cntB[x] = 0;
	
	int szA = a.length(), szB = b.length();
	for(int x=0;x<szA;x++){
		cntA[(a[x] - '0')]++;
	}
	for(int x=0;x<szB;x++){
		cntB[(b[x] - '0')]++;
	}
	
	string ansA, ansB;
	ll mx = 1e18;
	for(int x=10;x<=18;x++){
		for(int y=1;y<10;y++){
			if(x-y >= 10 || x-y <= 0) continue;
			if(min(cntA[y], cntB[x-y]) == 0) continue;
			
			ll sum = 1 + (x % 10);
			string tmpA, tmpB;
			cntA[y]--; cntB[x-y]--;
			tmpA.push_back(('0' + y));
			tmpB.push_back(('0' + x-y));
			
			for(int z=1;z<10;z++){
				int mn = min(cntA[z], cntB[9-z]);
				cntA[z] -= mn;
				cntB[9-z] -= mn;
				
				for(int i=0;i<mn;i++){
					tmpA.push_back(('0' + z));
					tmpB.push_back(('0' + 9-z));
				}
			}
			
			for(int z=10;z<=18;z++){
				for(int i=1;i<10;i++){
					if(z-i >= 10 || z-i <= 0) continue;
					if(min(cntA[i], cntB[z-i]) == 0) continue;
					
					int mn = min(cntA[i], cntB[z-i]);
					cntA[i] -= mn;
					cntB[z-i] -= mn;
					sum += z*mn;
					
					for(int j=0;j<mn;j++){
						tmpA.push_back(('0' + i));
						tmpB.push_back(('0' + z-i));
					}
				}
			}
			for(int z=9;z>0;z--){
				if(z < 9){
					sum += cntA[z]*z + cntB[z]*z;
				}
				
				for(int i=0;i<cntA[z];i++){
					tmpA.push_back(('0' + z));
				}
				for(int i=0;i<cntB[z];i++){
					tmpB.push_back(('0' + z));
				}
				cntA[z] = cntB[z] = 0;
			}
			
			if(sum < mx){
//				cout << sum << " " << x << " " << y << "\n";
				mx = sum;
				ansA = tmpA;
				ansB = tmpB;
			}
			
			for(int x=0;x<tmpA.length();x++){
				cntA[(tmpA[x] - '0')]++;
			}
			for(int x=0;x<tmpB.length();x++){
				cntB[(tmpB[x] - '0')]++;
			}
		}
	}
	
	if(mx == 1e18){
		ansA = a;
		ansB = b;	
	}
	
	reverse(ansA.begin(), ansA.end());
	reverse(ansB.begin(), ansB.end());
	
//	cout << mx << "\n";
	cout << ansA << "\n";
	cout << ansB << "\n";
    return 0;
}

