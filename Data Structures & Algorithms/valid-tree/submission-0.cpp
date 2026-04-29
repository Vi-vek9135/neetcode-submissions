class Solution {
public:

    bool dfs(int nd, int pt, vector<vector<int>>& gr, vector<bool>& vi){
        vi[nd] = true;
        for(int n : gr[nd]){
            if(!vi[n]){
                if(!dfs(n,nd,gr,vi))
                    return false;
            }else if(n!=pt)
             return false;
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
        vector<vector<int>> gr(n);
        for(auto &it : edges){
            gr[it[0]].push_back(it[1]);
            gr[it[1]].push_back(it[0]);
        }
        vector<bool> vi(n,false);
        if(!dfs(0,-1,gr,vi))
            return false;
        for(bool v : vi)
            if(!v) return false;
        return true;
    }
};
