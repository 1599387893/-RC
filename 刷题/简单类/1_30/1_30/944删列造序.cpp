#if 0
class Solution {
public:
	int minDeletionSize(vector<string>& A) {
		int count = 0;
		if(A.size()<=1 || A[0].size()==0)
			return count;
		for(size_t i=0;i < A[0].size();++i)
		{
			for(size_t j = 0; j < A.size()-1;++j)
			{
				if(A[j][i]>A[j+1][i])
				{
					count++;
					break;
				}
			}
		}
		return count;
	}
};
#endif