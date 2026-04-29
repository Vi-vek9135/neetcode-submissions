class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char,vector<char>> gr;
        unordered_map<char,int> ind;
        for(auto &it : words){
            for(char c : it){
                gr[c];
                ind[c]=0;
            }
        }
        for(int i=0;i<words.size()-1;i++){
            string a=words[i];
            string b=words[i+1];
            if(a.size()>b.size() && a.substr(0,b.size())==b)
                return "";
            for(int j=0;j<min(a.size(),b.size());j++){
                if(a[j]!=b[j]){
                    gr[a[j]].push_back(b[j]);
                    ind[b[j]]++;
                    break;
                }
            }
        }
        queue<char> q;
        for(auto &p : ind){
            if(p.second==0){
                q.push(p.first);
            }
        }
        string res;
        while(!q.empty()){
            char c=q.front();
            q.pop();
            res+=c;
            for(char ne : gr[c]){
                if(--ind[ne]==0){
                    q.push(ne);
                }
            }
        }
        return res.size()==ind.size()?res:"";
    }
};
