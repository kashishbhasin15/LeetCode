class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        
        int n=intervals.size();
        vector<pair<int,int>> starts;
        vector<int> ans(n,-1);

        for(int i=0;i<n;i++)
        {
            starts.push_back({intervals[i][0],i});
        }
        sort(starts.begin(),starts.end());

        for(int i=0;i<n;i++)
        {
            int target=intervals[i][1];
            int low=0;
            int high=n-1;
            int pos=-1;

            while(low<=high)
            {
                int mid=(low+high)/2;

                if(starts[mid].first >=target)
                {
                    pos=mid;
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            if(pos!=-1)
            {
                ans[i]=starts[pos].second;
            }
        }
 return ans;


    }
};