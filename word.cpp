/*
Name: Jonathan Cheng
USACO: 10*
Difficulty: 2/10
Time: 19 min
Description: I spent 15 min realizing that i couldnt have trailing spaces after my output
*/
#include <bits/stdc++.h>

using namespace std;

int main() {

	ifstream fin("word.in");
	ofstream fout("word.out");

	int N, K;
	fin >> N >> K;

  //2 1d arrays, one for strings and coorisponding lengths
	string sarr[N];
	int larr[N];

	for(int i = 0; i < N; i++) {
		fin >> sarr[i];
		larr[i] = sarr[i].size();
	}

  //iterate over ptr
	int ptr = 0;
	while(ptr < N) {
		int a=K;
    //as long as ptr is inbounds and will not exceed K
		while(ptr<N && a-larr[ptr]>=0) {
      //handle trailing spaces
			if(a!=K) fout << " ";
      //print out the coorisponding string then decrement a
			fout << sarr[ptr];
			a-=larr[ptr];
			ptr++;
		}
		fout << "\n";
	}
	return 0;
}
