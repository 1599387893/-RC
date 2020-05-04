//���⣺����һ���Ǹ��������飬�����λ������ĵ�һ��λ�á������е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ����Ŀ����ʹ�����ٵ���Ծ����������������һ��λ�á�

//����һ��������ҳ���λ��
class Solution {
public:
	//������ң�̰���㷨
	int jump(vector<int>& nums) {
		if (nums.size() <= 1) return 0;
		if (count(nums.begin(), nums.end(), 1) == nums.size())
			return nums.size() - 1;
		int pos = nums.size() - 1; //���ÿ�ε����λ�ã���Ϊ�Ƿ����ң������ʼ�����һ��Ԫ�ص�λ��
		int steps = 0;
		while (pos > 0)
		{
			//���������ҿ��Ե�����һ����ŵ����Զλ�ã���֤������С������
			for (int i = 0; i < pos; ++i)
			{
				//����Ӹ�λ��(i)���Ե���(+nums[i])��һ������ŵ�(pos),�ͽ���λ����Ϊ�µ���ŵ���ǰ�ƶ���
				if (i + nums[i] >= pos)
				{
					pos = i;
					steps++;
					break;
				}
			}
		}
		return steps;
	}
};


//������ҿɴﵽ�����λ��
class Solution {
public:
	int jump(vector<int>& nums) {
		if (nums.size() <= 1) return 0;
		if (count(nums.begin(), nums.end(), 1) == nums.size()) return nums.size() - 1;
		int maxPos = 0, n = nums.size(), step = 0;
		int end = 0; //���������ÿһ���п��Ե������Զ���룬����ƶ���endλ�ã�˵���Ѿ�ȷ����һ��������Զ����end
		for (int i = 0; i < n - 1; ++i) {
			if (maxPos >= i) {
				maxPos = max(maxPos, i + nums[i]);
				if (i == end) {
					end = maxPos;
					++step;
				}
			}
		}
		return step;
	}
};