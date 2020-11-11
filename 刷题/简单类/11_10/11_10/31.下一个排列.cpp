//ʹ�ÿ⺯��
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		next_permutation(nums.begin(), nums.end());
	}
};

//�ǿ⺯��
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		//����ͨ�������ҵ��ǽ����Ԫ�ضԵ�λ��
		int pos = nums.size() - 2;
		while (pos >= 0 && nums[pos] >= nums[pos + 1])
			pos--;

		//�ж��Ƿ�Ϊ���彵������ǣ������з�תΪ��������
		if (pos < 0)
		{
			reverse(nums.begin(), nums.end());
			return;
		}

		//��posΪ��㣬�Ӻ���ǰ�ҵ�һ����nums[pos]���Ԫ�ؽ��н�����������ɺ󣬽�pos֮�������Ԫ�ؽ��з�ת(��Ϊ����pos��nums.end������о��ǽӽ������)
		for (int i = nums.size() - 1; i > pos; --i)
		{
			if (nums[i] > nums[pos])
			{
				swap(nums[i], nums[pos]);
				reverse(nums.begin() + pos + 1, nums.end());
				return;
			}
		}
	}
};




class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		//����ͨ�������ҵ��ǽ����Ԫ�ضԵ�λ��
		int i = nums.size() - 2;
		while (i >= 0 && nums[i] >= nums[i + 1])
			i--;

		if (i >= 0)
		{
			int j = nums.size() - 1;
			while (j > i && nums[j] <= nums[i])
				j--;
			swap(nums[i], nums[j]);
		}
		reverse(nums.begin() + i + 1, nums.end());
	}
};