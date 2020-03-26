class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        if(target == 0)
            return res;
        for(int i = 1;i <= target/2;++i) 
        {
            vector<int> temp;
            int sum=0;
            for(int j = i;j <= target/2+1 && sum<target ;++j)
            {
                temp.push_back(j);
                sum+=j;
            }
            if(sum==target)
                res.push_back(temp);
        }
        return res;
    }
};


//滑动窗口
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        int sum = 0;
        for(int l=1,r=1;l <= target/2;)
        {
            if(sum < target)
            {
                sum+=r;
                r++;
            }
            else if(sum > target)
            {
                sum-=l;
                l++;
            }
            else
            {
                vector<int> temp;
                for(int i = l;i < r;++i)
                    temp.push_back(i);
                res.push_back(temp);
                sum-=l;
                l++;

            }
        }
        return res;
    }
};