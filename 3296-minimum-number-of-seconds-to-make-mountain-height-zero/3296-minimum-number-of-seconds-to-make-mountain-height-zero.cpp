typedef long long ll;

class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ll max_e = 0;
        for(ll mh : workerTimes)max_e = max(max_e , mh);

        ll right = max_e*mountainHeight*(mountainHeight+1)/2 , left = 0;
        ll ans = INT_MAX;
        cout<<right;
        
        function<bool(ll)> check = [&](ll mid)->bool{
            ll h = 0;

            for(int &t : workerTimes) {
                h += (ll)(sqrt(2.0 * mid/t + 0.25) - 0.5);

                if(h >= mountainHeight) {
                    return true;
                }
            }
            return h >= mountainHeight;
        };

        while(left <= right){
            ll mid = left + (right - left)/2;

            if(check(mid)){
                ans = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return ans;
    }
};