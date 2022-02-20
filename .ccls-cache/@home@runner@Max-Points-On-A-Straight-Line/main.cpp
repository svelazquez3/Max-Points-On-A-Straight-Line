#include <iostream>
#include <vector> 

using namespace std; 

class Solution {
public:
	bool fitsLine(int x,int y,int i,int j,int m,int n){
		if((m-x)*(j-y)==(n-y)*(i-x)) return 1;
		return 0;
	}

	int maxPoints(vector<vector<int>>& points) {

		if(points.size() <= 2) return points.size();

		int max=2, sub=2;

		for(int i=0; i< points.size()-2; i++){
			for(int k=i+1; k<points.size(); k++){
				for(int j=k+1; j<points.size(); j++){
						 if(fitsLine(points[i][0], points[i][1], points[k][0], points[k][1], points[j][0], points[j][1])){
							 sub++; 
						 }
				}
				if(sub>max) max=sub;
				sub=2;
			}    
		}
		return max;
	}
};