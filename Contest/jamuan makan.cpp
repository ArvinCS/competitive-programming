#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Perjamuan{
	int start, duration;
};

bool sortJadwal(Perjamuan a, Perjamuan b){
	int totalA = a.start + a.duration;
	int totalB = b.start + b.duration;
	if(totalA < totalB){
		return true;
	} else if(totalA == totalB){
		return a.start < b.start;
	} else {
		return false;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	Perjamuan jadwal[n];
	for(int x=0;x<n;x++){
		cin >> jadwal[x].start >> jadwal[x].duration;
	}
	
	sort(jadwal, jadwal+n, sortJadwal);
	
	int currentTime = 0;
	int counter = 0;
	for(int x=0;x<n;x++){
		Perjamuan perjamuan = jadwal[x];
		if(currentTime <= perjamuan.start && perjamuan.start + perjamuan.duration > currentTime){
			currentTime = perjamuan.start + perjamuan.duration;
			counter++;
		}
	}
	
	cout << counter << "\n";
	
    return 0;
}
