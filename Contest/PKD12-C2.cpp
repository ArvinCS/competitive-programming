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

#define PI 3.14159265358979323846

bool isSame(double a, double b){
	if(abs(a-b) < 1e-9){
		return true;
	} else {
		return false;
	}
}

int n, idx[305];
pair<int, int> p[305];

bool customSort(tuple<double, int, int> a, tuple<double, int, int> b){
	return (!isSame(get<0>(a), get<0>(b)) && get<0>(a) < get<0>(b));
}

double calc(int x, int y, int z){
	return abs(p[x].first*(p[y].second-p[z].second) + p[y].first*(p[z].second-p[x].second) + p[z].first*(p[x].second-p[z].second))*1.0/2;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> n;
	
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
	}
	
	sort(p, p+n);
	
	vector<tuple<double, int, int>> v;
	for(int x=0;x<n;x++){
		idx[x] = x;
		
		for(int y=x+1;y<n;y++){
			double rad = atan2(p[x].second - p[y].second, p[x].first - p[y].first);			
			v.push_back(make_tuple(rad, x, y));
		}
	}
	
	sort(v.begin(), v.end(), customSort);
	
	int cnt = 0;
	double ans = inf_int;
	for(int x=0;x<v.size();x++){
		int idx1 = idx[get<1>(v[x])], idx2 = idx[get<2>(v[x])];
		if(idx1 > 0 && idx1-1 != idx2){
			double area = calc(idx1-1, idx1, idx2);
			
			cout << idx1-1 << " " << idx1 << " " << idx2 << "a\n";
			if(!isSame(area, 0.00)){
				if(isSame(ans, area)){
					cnt++;
				} else if(ans > area){
					ans = area;
					cnt = 1;
				}
			}
		}
		if(idx1 < n-1 && idx1+1 != idx2){
			double area = calc(idx1+1, idx1, idx2);
			
			cout << idx1+1 << " " << idx1 << " " << idx2 << "b\n";
			if(!isSame(area, 0.00)){
				if(isSame(ans, area)){
					cnt++;
				} else if(ans > area){
					ans = area;
					cnt = 1;
				}
			}
		}
		if(idx2 > 0 && idx2-1 != idx1){
			double area = calc(idx2-1, idx1, idx2);
			
			cout << idx2-1 << " " << idx1 << " " << idx2 << "c\n";
			if(!isSame(area, 0.00)){
				if(isSame(ans, area)){
					cnt++;
				} else if(ans > area){
					ans = area;
					cnt = 1;
				}
			}
		}
		if(idx2 < n-1 && idx2+1 != idx1){
			double area = calc(idx2+1, idx1, idx2);
			
			cout << idx2+1 << " " << idx1 << " " << idx2 << "d\n";
			if(!isSame(area, 0.00)){
				if(isSame(ans, area)){
					cnt++;
				} else if(ans > area){
					ans = area;
					cnt = 1;
				}
			}
		}
		
		swap(p[idx1], p[idx2]);
		swap(idx[get<1>(v[x])], idx[get<2>(v[x])]);
	}
	
	if(cnt == 0 || cnt > 1){
		cout << -1 << "\n";
		return 0;
	}
	
	cout << fixed << setprecision(2) << ans << "\n";
    return 0;
}

