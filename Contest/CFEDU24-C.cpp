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

const int maxN = 1e5 + 5;

struct Sofa {
	int x1, x2, y1, y2;
};

int cntMin[maxN][2], cntMax[maxN][2]; // 0 X 1 Y

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int s, n, m;
	cin >> s >> n >> m;
	
	Sofa sofa[s];
	for(int x=0;x<s;x++){
		cin >> sofa[x].x1 >> sofa[x].y1 >> sofa[x].x2 >> sofa[x].y2;
	}
	
	int l, r, t, b;
	cin >> l >> r >> t >> b;
	
	fill(cntMin[0], cntMin[maxN], 0);
	fill(cntMax[0], cntMax[maxN], 0);
	
	for(int x=0;x<s;x++){
		// mn
		cntMin[min(sofa[x].x1, sofa[x].x2)][0]++;
		cntMin[min(sofa[x].y1, sofa[x].y2)][1]++;
		
		// mx
		cntMax[max(sofa[x].x1, sofa[x].x2)][0]++;
		cntMax[max(sofa[x].y1, sofa[x].y2)][1]++;
	}
	
	for(int x=2;x<maxN;x++){
		// mn
		cntMin[x][0] += cntMin[x-1][0];
		cntMin[x][1] += cntMin[x-1][1];
		
		// mx
		cntMax[x][0] += cntMax[x-1][0];
		cntMax[x][1] += cntMax[x-1][1];
	}
	
	for(int x=0;x<s;x++){
		bool diffX = (sofa[x].x1 != sofa[x].x2), diffY = (sofa[x].y1 != sofa[x].y2);
		
		int top = cntMin[max(sofa[x].y1, sofa[x].y2)-1][1] - (diffY ? 1 : 0);
		int left = cntMin[max(sofa[x].x1, sofa[x].x2)-1][0] - (diffX ? 1 : 0);
		
		int bottom = cntMax[maxN-1][1]-cntMax[min(sofa[x].y1, sofa[x].y2)][1] - (diffY ? 1 : 0);
		int right = cntMax[maxN-1][0]-cntMax[min(sofa[x].x1, sofa[x].x2)][0] - (diffX ? 1 : 0);
		
		if(top == t && left == l && right == r && bottom == b){
			cout << x+1 << "\n";
			return 0;
		}
	}
	
	cout << "-1\n";
    return 0;
}

