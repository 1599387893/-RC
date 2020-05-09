//�������������ʹ�ö�������log()��ָ������exp()
class Solution {
public:
	int mySqrt(int x) {
		if (x <= 1) return x;
		int res = exp(0.5*log(x));
		return (long long)(res + 1)*(res + 1) <= x ? res + 1 : res;
	}
};

//���ַ���
class Solution {
public:
	int mySqrt(int x) {
		if (x == 1) return 1;
		int EPSINON = 1;//ȷ������
		int low = 0;
		int high = x;
		int mid = (low + high) / 2;
		while ((high - low) > EPSINON){
			//ʹ��x/mid<mid�滻mid*mid>x��ֹ���
			if (x / mid<mid){
				high = mid;
			}
			else{
				low = mid;
			}
			mid = (high + low) / 2;
		}
		return mid;
	}
};


//ţ�ٵ�����
class Solution{
public:
	int mySqrt(int x)
	{
		if (x == 0) return 0;
		double C = x, x0 = x;
		while(true)
		{
			double xi = 0.5*(x0 + C / x0);
			if (fabs(x0 - xi) < 1e-7)
				break;
			x0 = xi;
		}
		return int(x0);
	}
};
