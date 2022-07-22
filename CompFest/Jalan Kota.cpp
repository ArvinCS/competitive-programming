#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

struct Edge {
	ui x, y;
	ull w;	
};

bool customSort(Edge a, Edge b){
	return a.w < b.w;	
}

ui parrent[100001];

ui getRp(ui x){
	if(parrent[x] == x) return x;
	return getRp(parrent[x]);
}

void join(ui x, ui y){
	parrent[getRp(x)] = getRp(y);	
}

bool check(ui x, ui y){
	return getRp(x) == getRp(y);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ui n, m;
	cin >> n >> m;
	
	vector<Edge> edges;
	
	while(m--){
		Edge tmp;
		cin >> tmp.x >> tmp.y >> tmp.w;
		edges.push_back(tmp);
	}
	
	sort(edges.begin(), edges.end(), customSort);
	
	for(ui x=1;x<=n;x++){
		parrent[x] = x;	
	}
	
	vector<ui> picked;
	for(ui x=0;x<edges.size();x++){
		Edge e = edges[x];
		if(!check(e.x, e.y)){
			join(e.x, e.y);
			picked.push_back(x);
		}
	}
	
	ui ans = inf_int;
	for(ui x=0;x<picked.size();x++){
		ui cost = 0;
		ui removedIndex = picked[x];
		Edge removedEdge = edges[removedIndex];
		
		for(ui x=0;x<picked.size();x++){
			parrent[edges[parrent[x]].x] = edges[parrent[x]].x;
			parrent[edges[parrent[x]].y] = edges[parrent[x]].y;
		}
		for(ui x=0;x<edges.size();x++){
			if(x == removedIndex) continue;
			Edge e = edges[x];
			if(!check(e.x, e.y)){
				join(e.x, e.y);
				cost += e.w;
			}
			if(cost >= ans) break;
		}
		ans = min(cost, ans);
	}
	
	cout << ans << "\n";
    return 0;
}

