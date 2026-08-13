class DSU {
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            size[i] = 1;
            parent[i] = i;
        }
    }
    int findParent(int u) {
        if (parent[u] == u)
            return u;
        else {
            parent[u] = findParent(parent[u]);
            return parent[u];
        }
    }
    void UnionBySize(int u, int v) {
        int pv = findParent(v);
        int pu = findParent(u);
        if (size[pv] > size[pu]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU d(26);
        for(auto i:equations){
            string st=i.substr(1,2);
            if(st=="==" && d.findParent(i[0]-'a')!=d.findParent(i[3]-'a')){
                d.UnionBySize(i[0]-'a',i[3]-'a');
            }
            else if(st=="!=") {
                if(d.findParent(i[0]-'a')==d.findParent(i[3]-'a')){
                    return false;
                }
            }
        }
         for(auto i:equations){
            string st=i.substr(1,2);
             if(st=="!=") {
                if(d.findParent(i[0]-'a')==d.findParent(i[3]-'a')){
                    return false;
                }
            }
        }
        return true;
    }
};