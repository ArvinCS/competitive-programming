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
		ll n, k;
		cin >> n >> k;
		
		k++;
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		vector<int> v;
		int pos = 0, mn = 0, pw[20];
		
		for(int i=0;i<=18;i++){
			if(k <= 0) break;
			
			while(pos < n && a[pos] <= i){
				mn = max(mn, a[pos]);
				pos++;
			}
			
			pw[i] = pow(10ll, i-mn);
			ll need = min(9ll, (k+pw[i]-1)/pw[i]);

			k -= need*pw[i];
			
			for(int j=i-1;j>=0;j--){
				while(k < 0 && v[j] > 0 && k+pw[j] <= 0){
					v[j]--;
					k += pw[j];
				}
			}

			v.push_back(need);
		}
		
		for(int x=v.size()-1;x>=0;x--){
			cout << v[x];
		}
		cout << "\n";
	}
	
    return 0;
}

