#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		int	n;
		cin >> n;
		
		int num;
		int sum[n+1] = { 0 };
		for(int x=0;x<n;x++){
			cin >> num;
			sum[num]++;
		}
				
		int group = 0, remain = 0;
		for(int x=1;x<=n;x++){
			if(sum[x] > 0){
				int total = sum[x] + remain;
				group += total/x;
				remain = total%x;
			}
		}
		cout << group << "\n";
	}
	
    return 0;
}
