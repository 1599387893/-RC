//袖珍计算器法：使用对数函数log()和指数函数exp()
class Solution {
public:
	int mySqrt(int x) {
		if (x <= 1) return x;
		int res = exp(0.5*log(x));
		return (long long)(res + 1)*(res + 1) <= x ? res + 1 : res;
	}
};

//二分法：
class Solution {
public:
	int mySqrt(int x) {
		if (x == 1) return 1;
		int EPSINON = 1;//确定精度
		int low = 0;
		int high = x;
		int mid = (low + high) / 2;
		while ((high - low) > EPSINON){
			//使用x/mid<mid替换mid*mid>x防止溢出
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


//牛顿迭代法
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
