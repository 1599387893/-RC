#if 0
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		for (int i = 0; i < nums.size(); ++i)
			if (nums[i] == val)
				nums.erase(nums.begin() + i--);
		return nums.size();
	}
};
#endif

#if 0
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int begin = 0, end = nums.size() - 1;
		while (begin <= end){
			if (nums[begin] == val && nums[end] != val){
				nums[begin] = nums[end];
				begin++;
				end--;
			}
			else if (nums[begin] != val && nums[end] == val){
				begin++;
				end--;
			}
			else if (nums[begin] == val && nums[end] == val){
				end--;
			}
			else{
				begin++;
			}
		}
		return begin;
	}
};

#endif