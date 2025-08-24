class Solution {
  public:
    vector<vector<int>> countFreq(vector<int>& arr) {
        // code here
        map<int,int> m;
        for(int i = 0 ; i < arr.size() ; i++){
            m[arr[i]]++;
        }
        
        vector<vector<int>> ans;
        for(auto i : m){
            ans.push_back({i.first, i.second});
        }
        return ans;
    }
}; 