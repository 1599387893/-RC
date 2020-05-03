//�������
class Solution {
public:
	int countNegatives(vector<vector<int>>& grid) {
		int res = 0;
		for (int i = 0; i < grid.size(); ++i)
			for (int j = 0; j < grid[0].size(); ++j)
				if (grid[i][j]<0)
					res++;
		return res;
	}
};

//���ֲ���
class Solution {
public:
	int countNegatives(vector<vector<int>>& grid) {
		//�ȴ����½�Ԫ�ؿ�ʼ��
		//�����Ԫ���Ǹ����������һ�У�����һ�����һ��Ԫ�أ�
		//�����Ԫ�ز��Ǹ���������ƶ��Ҹ�ֵ��
		int res = 0;
		for (auto arr : grid)
		{
			if (arr[0]<0)
				res += arr.size();
			else
			{
				int pos = -1;
				//ʹ�ö��ֲ��ң��ҵ���һ������
				int l = 0, r = arr.size() - 1, mid = 0;
				while (l <= r)
				{
					mid = l + ((r - l) >> 1);
					if (arr[mid]<0)
					{
						pos = mid;
						r = mid - 1;
					}
					else
						l = mid + 1;
				}
				if (pos != -1)
					res += arr.size() - pos;
			}
		}
		return res;
	}
};
	