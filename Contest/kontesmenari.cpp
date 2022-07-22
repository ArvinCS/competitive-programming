#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

struct Tarian{
	int indah;
	char jenis;
};

int possibility[3628801] = { 0 };
int currentP = 0;
int n,r,y,j;

void getPossibility(int i, Tarian list[], Tarian possible[], bool checked[]){
	if(i >= r){
		int sum = 0;
		for(int x=0;x<r;x++){
			sum += possible[x].indah;
			//cout << possible[x].jenis << "|" << possible[x].indah << "|";
			if(x+1 < r){
				if(possible[x].jenis == 'P'){
					sum += possible[x+1].indah;
				} else if(possible[x].jenis == 'L'){
					sum -= ceil(possible[x+1].indah/2.0);
				} else if(possible[x].jenis == 'Y'){
					sum += y * (r-x-1);
				}
			}
		}	
		possibility[currentP] = sum;
		currentP++;
		return;
	}
	
	for(int x=0;x<n;x++){
		if(!checked[x]){
			checked[x] = true;
			possible[i] = list[x];
			getPossibility(i+1, list, possible, checked);
			checked[x] = false;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	string subsoal;
	int subnomor;
	cin >> subsoal >> subnomor;
	cin >> n >> r >> y >> j;
	
	Tarian list[n];
	for(int x=0;x<n;x++){
		Tarian temp;
		cin >> temp.indah >> temp.jenis;
		list[x] = temp;
	}
	
	bool checked[n] = { false };
	Tarian temp[r];
	getPossibility(0,list,temp,checked);
	sort(possibility, possibility+currentP);
	int lastSyarat = 0, lastPos = 0, jump = currentP / 10;
	for(int x=0;x<j;x++){
		int syarat;
		cin >> syarat;
		int total = 0;
		bool bigger = syarat >= lastSyarat;
		for(int i=(bigger ? lastPos : 0);i<currentP;i++){
			if(possibility[i] > syarat){
				total = currentP-i;
				if(bigger){
					lastSyarat = max(syarat, lastSyarat);
					lastPos = max(lastPos, i);
				}
				break;
				//cout << possibility[i] << "\n";
			}
			if(i+jump < currentP && possibility[i+jump] <= syarat) i+= jump;
		}
		cout << total << "\n";
	}
	
    return 0;
}
