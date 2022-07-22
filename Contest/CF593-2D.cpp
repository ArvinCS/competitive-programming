#include <bits/stdc++.h>

using namespace std;

#define ll long long

int moveX[4] = {0, 0, 1, -1};
int moveY[4] = {1, -1, 0, 0};

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	
	pair<int, int> p[k];
	set<pair<int, int>> st;
	for(int x=0;x<k;x++){
		cin >> p[x].first >> p[x].second;
		p[x].first--; p[x].second--;
		st.insert(p[x]);
	}
	
	sort(p, p+k);
	
	vector<int> row[n], col[m];
	for(int x=0;x<max(n, m);x++){
		if(x < n) row[x].push_back(-1);
		if(x < m) col[x].push_back(-1);
	}
	for(int x=0;x<k;x++){
		row[p[x].first].push_back(p[x].second);
		col[p[x].second].push_back(p[x].first);
	}
	for(int x=0;x<max(n, m);x++){
		if(x < n) row[x].push_back(m);
		if(x < m) col[x].push_back(n);
	}
	
	bool possible = true;
	ll cnt = 1;
	int posX = 0, posY = 0, turn = 0;
	int mnX = 0, mxX = n-1, mnY = 0, mxY = m-1;
	while(true){
		if(turn == 0){
			int nxtY = (*lower_bound(row[posX].begin(), row[posX].end(), posY)) - 1;
			
			nxtY = max(min(nxtY, mxY), mnY);
			
			if(st.count({posX, nxtY})){
				break;
			}
			
			if((posX != 0 || posY != 0) && posY == nxtY) break;
			
			if(posX != 0 || posY != 0) mnY = max(mnY, posY+1);
			cnt += nxtY-posY;
			posY = nxtY;
		} else if(turn == 1){
			int nxtX = (*lower_bound(col[posY].begin(), col[posY].end(), posX)) - 1;
			
			nxtX = max(min(nxtX, mxX), mnX);
			
			if(st.count({nxtX, posY})){
				break;
			}
			
			if(posX == nxtX) break;
			
			mnX = max(mnX, posX+1);
			cnt += nxtX-posX;
			posX = nxtX;
		} else if(turn == 2){
			int nxtY = (*(upper_bound(row[posX].begin(), row[posX].end(), posY)-1)) + 1;
			
			nxtY = max(min(nxtY, mxY), mnY);
			
			if(st.count({posX, nxtY})){
				break;
			}
			
			if(posY == nxtY) break;
			
			mxY = min(mxY, posY-1);
			cnt += posY-nxtY;
			posY = nxtY;
		} else if(turn == 3){
			int nxtX = (*(upper_bound(col[posY].begin(), col[posY].end(), posX)-1)) + 1;
			
			nxtX = max(min(nxtX, mxX), mnX);
			
			if(st.count({nxtX, posY})){
				break;
			}

			if(posX == nxtX) break;
			
			mxX = min(mxX, posX-1);
			cnt += posX-nxtX;
			posX = nxtX;
		}
		
		turn++;
		if(turn >= 4) turn -= 4;
	}
	
	if(cnt != n*1ll*m-k){
		possible = false;
	}
	
	cout << (possible ? "Yes" : "No") << "\n";
	
    return 0;
}

