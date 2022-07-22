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

const int maxN = 200005;
ull data[maxN];
vector<int> edges[maxN];

ull getCitizens(int x){
	ull total = data[x];
	for(int i=0;i<edges[x].size();i++){
		total += getCitizens(edges[x][i]);
	}	
	return total;
}

void go(int start){
	int total = getCitizens(start);
//	cout << start << " -> " << total << "\n";
	if(edges[start].size() > 0) data[edges[start][0]] += ((total + edges[start].size() - 1)/edges[start].size()) - getCitizens(edges[start][0]);
	for(int i=1;i<edges[start].size();i++){
		int y = edges[start][i];
		data[y] += (total/edges[start].size()) - getCitizens(y);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	for(int x=1;x<n;x++){
		int tmp;
		cin >> tmp;
		
		edges[tmp-1].push_back(x);
	}
	
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	for(int x=0;x<n;x++){
		go(x);
	}
	
	ull ans = 0;
	for(int x=0;x<n;x++){
//		cout << data[x] << " ";
		ans = max(ans, data[x]);
	}
//	cout << "\n";
	cout << ans << "\n";
    return 0;
}

