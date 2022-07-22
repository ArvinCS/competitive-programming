#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int d[10];
		fill(d, d+10, -1);
		
		for(int x=0;x<n;x++){
			int b, dif;
			cin >> b >> dif;
			
			d[dif-1] = max(d[dif-1], b);	
		}
		
		int sum = 0;
		for(int x=0;x<10;x++){
			if(d[x] == -1){
				sum = -1;
				break;
			}
			
			sum += d[x];
		}
		
		if(sum == -1){
			cout << "MOREPROBLEMS\n";
		} else {
			cout << sum << "\n";
		}
	}
	
    return 0;
}

