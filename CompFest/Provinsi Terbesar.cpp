#include <iostream>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

ui parrent[100000];

ui getParrent(ui id){
	if(parrent[id] == id) return id;
	return parrent[id] = getParrent(parrent[id]);
}

void join(ui id1, ui id2){
	parrent[getParrent(id1)] = getParrent(id2);
}

bool check(ui id1, ui id2){
	return getParrent(id1) == getParrent(id2);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ui n, m;
	cin >> n >> m;
	
	for(ui x=0;x<n;x++) parrent[x] = x;
	while(m--){
		ui a, b;
		cin >> a >> b;
		
		join(a,b);
	}
	
	ui cntProv[n], ans = 0;
	fill(cntProv, cntProv+n, 0);
	for(ui x=0;x<n;x++){
		cntProv[getParrent(x)]++;
		ans = max(ans, cntProv[getParrent(x)]);
	}
//	
//	for(ui x=0;x<n;x++) cout << cntProv[x] << " ";
//	cout << "\n";
	cout << ans * 1ll * ans << "\n";
    return 0;
}

