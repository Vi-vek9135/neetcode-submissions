class Solution {
public:

    void dfs(int nd , vector<vector<int>>& gr , vector<bool>& vi){
        vi[nd] = true;
        for(int ne : gr[nd]){
            if(!vi[ne])
                dfs(ne,gr,vi);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> gr(n);
        for(auto &e : edges){
            gr[e[0]].push_back(e[1]);
            gr[e[1]].push_back(e[0]);
        }
        vector<bool> vi(n,false);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vi[i]){
                cnt++;
                dfs(i,gr,vi);
            }
        }
        return cnt;
    }
};
