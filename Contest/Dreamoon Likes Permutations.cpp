#include <iostream>

using namespace std;

#define ll long long
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		int l;
		cin >> l;
		int a[l] = { 0 };
		for(int x=0;x<l;x++){
			cin >> a[x];
		}	
		
		int ways = 0;
	    int possibility[l][2];

		for(int l1=1;l1<l;l1++){
			int sumP1 = 0;
			bool filledP1[l1+1] = { false };
			for(int x=0;x<l1;x++){
				if(filledP1[a[x]]){
					sumP1 = 0;
					break;
				}
				sumP1 += a[x];
				filledP1[a[x]] = true;
			}
			
			if(sumP1 == (l1 * (l1+1) / 2)){
				int l2 = l - l1;
				int sumP2 = 0;
				bool filledP2[l2+1] = { false };
				for(int x=l1;x<l;x++){
					if(filledP2[a[x]]){
						sumP2 = 0;
						break;
					}
					sumP2 += a[x];
					filledP2[a[x]] = true;
				}
				
				if(sumP2 == (l2 * (l2+1)/2)) {
					possibility[ways][0] = l1;
					possibility[ways][1] = l2;
					ways++;
				}
			}
		}
			
		cout << ways << "\n";
		for(int x=0;x<ways;x++){
			cout << possibility[x][0] << " " << possibility[x][1] << "\n";
		}
	}
	
    return 0;
}
