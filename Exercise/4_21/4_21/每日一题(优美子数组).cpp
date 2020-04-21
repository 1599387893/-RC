#if 0
//���ĳ��������������ǡ����K���������֣���ô��������Ϊ����������
//��������һ�����⣬���������k���������ֵ�����������ĸ�����
//��ô��������һ�ΰ���k���������ֵ������飬
//�������ż���ĸ����ֱ�Ϊm��n����ô���ڵ�������(m + 1)��(n + 1)����
//��Ϊ�������߷ֱ����ѡ��[0, m]��ż����[0, n]��ż����


class Solution {
public:
	int numberOfSubarrays(vector<int>& nums, int k) {
		vector<int> odd(nums.size() + 2);
		int cnt = 0, res = 0;
		for (int i = 0; i < nums.size(); ++i)
			if (nums[i] & 1)
				odd[++cnt] = i;
		odd[0] = -1;
		odd[++cnt] = nums.size();
		for (int i = 1; i + k <= cnt; ++i)
			res += (odd[i] - odd[i - 1]) * (odd[i + k] - odd[i + k - 1]);
		return res;
	}
};


class Solution {
public:
	int numberOfSubarrays(vector<int>& nums, int k) {
		int n = nums.size();
		vector<int>index;
		for (int i = 0; i < n; i++){
			//���������ֵ��±�
			if (nums[i] % 2)
				index.push_back(i);

		}
		if (index.size() < k) return 0;
		if (index.size() == k) return (index[0] + 1)*(n - index[k - 1]);
		int number = 0;
		for (int i = 0; i <= index.size() - k; i++){
			if (i == 0) number += (index[0] + 1)*(index[k] - index[k - 1]);
			else if (i == index.size() - k){
				number += (index[i] - index[i - 1])*(n - index[i + k - 1]);
			}
			else
				number += (index[i] - index[i - 1])*(index[i + k] - index[i + k - 1]);
		}
		return number;
	}
};

#endif