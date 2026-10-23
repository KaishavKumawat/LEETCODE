class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n  = heights.size();
        stack<int> s ; 
        vector<int> right(n,0);
        vector<int> left(n,0);
        int currarea = 0  , maxarea = 0;
        for(int i = n - 1 ; i >= 0 ; i-- ){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            if(s.empty()) right[i] = n ;
            else right[i] = s.top();
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
        for(int i = 0 ; i < n ; i++ ){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            if(s.empty()) left[i] = -1 ;
            else left[i] = s.top();
            s.push(i);
        }
        for(int i = 0  ; i < n ; i++){
        currarea = (right[i] - left[i]  - 1 )*heights[i];
          maxarea = max(currarea , maxarea);
        }
     return maxarea;
    }
};