#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		us n;
		cin >> n;
		
		us data[n];
		for(ui x=0;x<n;x++) cin >> data[x];
				
		unordered_set<us> specials;
		for(us x=0;x<n-1;x++){
			us sum = data[x];
			for(ui y=x+1;y<n;y++){
				sum += data[y];
				if(sum > n) break;
				specials.insert(sum);
			}
		}
		
		us ans = 0;
		for(us x=0;x<n;x++){
			if(specials.count(data[x])){
				ans++;
//				cout << data[x] << " of index " << x << " is special\n";
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

