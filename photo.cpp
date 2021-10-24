/*
Name: Jonathan Cheng
USACO: 10*
Time: 30 min
Difficulty: 6/10
Description: Took a lot of time to implement
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	ifstream fin("photo.in");
	ofstream fout("photo.out");
	fin>> N;

	int b[N-1];
	for(int i = 0; i < N-1; i++) {
		fin >> b[i];
	}

  //only first index matters, test 1 to b[0]
	for(int i = 1; i <= b[0]; i++) {
		int a[N];
    //memset to check for duplicate items
		unordered_set<int> mem(N);
		a[0] = i;
		bool flag = 0;
		for(int e = 1; e < N; e++) {

      //if               contains a duplicate item              or   is less than 1  or  is greater than N
			if(find(mem.begin(), mem.end(), b[e-1]-a[e-1])!=mem.end() || (b[e-1]-a[e-1])<1 || (b[e-1]-a[e-1]>N)) {
				//not a good permutation
        flag=1;
				break;
			}
				
      //construction
			a[e] = b[e-1]-a[e-1];
			mem.insert(b[e-1]-a[e-1]);
		}

    //if nothing went wrong
		if(!flag) {
      //print
			for(int e = 0; e < N; e++) {
				fout << a[e];
        
        //this line is to make sure we don't have a trailing space
				if(e!=N-1) fout << " ";
			}
			fout << "\n";
			return 0;
		}
	}
	return 0;
}
