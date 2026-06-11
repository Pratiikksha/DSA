class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        if(n==1) return stones[0];
        priority_queue<int,vector<int>> pq;
        for(int i:stones){
           pq.push(i);
        }
        while(pq.size()>1){
            int k=pq.top();
            pq.pop();
            int l=pq.top();
            pq.pop();
            if(l==k) continue;
            int heavier=abs(l-k);
            pq.push(heavier);
        }
       if(pq.size()==0) return 0;
       return pq.top();
    }
};