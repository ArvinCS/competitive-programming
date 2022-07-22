#include <iostream>
#include <fstream>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

us n, m;
ui k, data[2000][2000];

struct Sector {
	us x1, y1, x2, y2;
};

Sector trash;
pair<ull, Sector> ans;

ull cntSum(us x1, us y1, us x2, us y2){
	ull cost = 0;
	for(us a=x1;a<=x2;a++){
		for(us b=y1;b<=y2;b++){
			cost += data[a][b];
		}
	}	
	return cost;
}

ull cntTruck(ull cnt){
	return ((cnt + k - 1) / k);
}

pair<ull, Sector> customMin(pair<ull, Sector> a, pair<ull, Sector> b){
	return a.first < b.first ? a : b;
}

pair<ull, Sector> find(us x1, us y1, us x2, us y2){
	ull sum = cntSum(x1,y1,x2,y2);
	ull truck = cntTruck(sum);
	if(x2 >= n || y2 >= m || truck >= ans.first) return {inf_ll, trash};
	if(truck > 1){
		Sector tmp;
		tmp.x1 = x1;
		tmp.y1 = y1;
		tmp.x2 = x2;
		tmp.y2 = y2;
		return {truck, tmp};
	} else {
		return customMin(find(x1,y1,x2+1,y2), find(x1,y1,x2,y2+1));
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ifstream myfile;
	myfile.open("input.in");
	if(!myfile) cout << "ERROR\n";
	myfile >> n >> m >> k;

	for(ui x=0;x<n;x++){
		for(ui y=0;y<m;y++) myfile >> data[x][y];
	}
	
	ans.first = inf_ll;
	ans.second = trash;
	
	us tmp2, tmp3;
	ui tmp = inf_int;
	for(us x=0;x<n;x++){
		for(us y=0;y<m;y++){
			if(data[x][y] >= k){
				if(tmp > data[x][y]){
					tmp = min(tmp, data[x][y]);
					tmp2 = x;
					tmp3 = y;
				}
			}
		}
	}
	
	
	cout << tmp << " " << tmp2 << "-" << tmp3 << "\n";
	for(us x=tmp2-1;x<=tmp2+1;x++){
		for(us y=tmp3-1;y<=tmp3+1;y++){
			cout << data[x][y] << " ";
		}
		cout << "\n";
	}
//	cout << ans.first << "\n";
//	cout << ans.second.x1 + 1 << " " << ans.second.y1 + 1 << " " << ans.second.x2 + 1 << " " << ans.second.y2 + 1 << "\n";
    return 0;
}

