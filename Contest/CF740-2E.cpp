#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

void reverse(int n, int a[], int pos[]){
	for(int x=0;x<=(n/2);x++){
		swap(a[x], a[n-x]);
		swap(pos[a[x]], pos[a[n-x]]);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int a[n], pos[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
			a[x]--;
			pos[a[x]] = x;
		}
		
		bool possible = true;
		for(int x=0;x<n;x++){
			if(a[x] % 2 != x % 2){
				possible = false;
				break;
			}
		}
		
		if(!possible){
			cout << "-1\n";
			continue;
		}
		
		vector<int> ans;
		for(int x=n-1;x>0;x-=2){
			if(pos[x] == x && pos[x-1] == x-1) continue;
			
			ans.push_back(pos[x]);
			reverse(pos[x], a, pos);
			
			ans.push_back(pos[x-1]-1);
			reverse(pos[x-1]-1, a, pos);
			
			ans.push_back(pos[x-1]+1);
			reverse(pos[x-1]+1, a, pos);
			
			ans.push_back(2);
			reverse(2, a, pos);
			
			ans.push_back(x);
			reverse(x, a, pos);
		}
		
		cout << ans.size() << "\n";
		for(int x=0;x<ans.size();x++){
			if(x > 0) cout << " ";
			cout << ans[x]+1;
		}
		cout << "\n";
	}

    return 0;
}

