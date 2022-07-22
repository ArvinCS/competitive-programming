#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;

int arr[2*maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int m;
	cin >> m;
	
	tuple<int, int, int> t[m];
	for(int x=0;x<m;x++){
		int a;
		cin >> a;
		
		if(a == 1){
			int b;
			cin >> b;
			
			t[x] = make_tuple(a, b, -1);
		} else {
			int b, c;
			cin >> b >> c;
			
			t[x] = make_tuple(a, b, c);
		}
	}
	
	int q;
	cin >> q;
	
	int ans[q];
	ll p[q];
	for(int x=0;x<q;x++){
		cin >> p[x];
	}
	
	ll cnt = 0;
	ll idx = 0, pos = 0;
	for(int x=0;x<m;x++){
		int a = get<0>(t[x]), b = get<1>(t[x]), c = get<2>(t[x]);
		
		if(a == 1){ // ud(b)
			if(idx < maxN){
				arr[idx++] = b;
			}
			
			while(pos < q && cnt < p[pos] && p[pos] <= cnt+1){
				ans[pos++] = b;
			}
			
			cnt++;
		} else { // ud2(b, c)
			while(pos < q && cnt < p[pos] && p[pos] <= cnt+b*1ll*c){
				ans[pos] = arr[(p[pos]-cnt-1) % b];
				pos++;
			}
			
			for(ll x=0;x<c&&idx<maxN;x++){
				for(ll y=0;y<b;y++){
					arr[idx++] = arr[y];
				}
			}
			
			cnt += b*1ll*c;
		}
	}
	
	for(int x=0;x<q;x++){
		if(x > 0) cout << " ";
		cout << ans[x];
	}
	cout << "\n";
    return 0;
}

