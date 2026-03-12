class Solution {
public:

    struct DSU{
        vector<int> p,r;

        DSU(int n){
            p.resize(n);
            r.resize(n,0);
            for(int i=0;i<n;i++) p[i]=i;
        }

        int find(int x){
            if(p[x]==x) return x;
            return p[x]=find(p[x]);
        }

        bool unite(int a,int b){
            a=find(a);
            b=find(b);
            if(a==b) return false;

            if(r[a]<r[b]) swap(a,b);
            p[b]=a;
            if(r[a]==r[b]) r[a]++;

            return true;
        }
    };

    bool can(int n, vector<vector<int>>& edges, int k, long long x){

        DSU dsu(n);
        int used=0;

        vector<pair<int,int>> normal;
        vector<pair<int,int>> upgrade;

        for(auto &e:edges){
            int u=e[0],v=e[1],s=e[2],must=e[3];

            if(must){
                if(s<x) return false;
                if(!dsu.unite(u,v)) return false;
                used++;
            }
        }

        for(auto &e:edges){
            int u=e[0],v=e[1],s=e[2],must=e[3];

            if(must) continue;

            if(s>=x)
                normal.push_back({u,v});
            else if((long long)s*2>=x)
                upgrade.push_back({u,v});
        }

        for(auto &p:normal){
            if(dsu.unite(p.first,p.second))
                used++;
        }

        int up=0;

        for(auto &p:upgrade){
            if(up>=k) break;
            if(dsu.unite(p.first,p.second)){
                used++;
                up++;
            }
        }

        return used==n-1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {

        long long l=0,r=200000;
        int ans=-1;

        while(l<=r){
            long long mid=(l+r)/2;

            if(can(n,edges,k,mid)){
                ans=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }

        return ans;
    }
};