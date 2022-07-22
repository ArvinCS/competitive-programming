#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	pair<int, int> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
		p[x].first--; p[x].second--;
	}
	
	int d[n], parent[n];
	d[0] = 0;
	parent[0] = 0;
	
	vector<pair<int, int>> v;
	for(int x=0;x<n;x++){
		if(p[x].first != -2){
			d[p[x].first] = d[x]+1;
			parent[p[x].first] = x;
		} else {
			v.push_back({d[x]+1, x});
		}
		if(p[x].second != -2){
			d[p[x].second] = d[x]+1;
			parent[p[x].second] = x;
		} else {
			v.push_back({d[x]+1, x});
		}
	}

	sort(v.begin(), v.end());
	
	if(v.back().first - v[0].first > 1){
		cout << "-1\n";
		return 0;
	}
	if(v.back().first - v[0].first == 0){
		cout << "0\n";
		return 0;	
	}
	
	for(int x=1;x<v.size();x++){
		if(v[x].first == v[0].first){
			if(v[x].second != v[0].second){
				cout << "-1\n";
				return 0;
			}
		}
	}
	
	bool right = (p[v[0].second].second == -2);
	int node = v[0].second;
	while(parent[node] != 0){
		if(p[parent[node]].second != node){
			right = false;
		}
		
		node = parent[node];
	}

	if(node == 0 || p[0].second == node){
		cout << (right ? 0 : 1) << "\n";
	} else {
		cout << (right ? 1 : 2) << "\n";
	}
    return 0;
}

