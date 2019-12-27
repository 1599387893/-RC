//1
//最近公共祖先(根节点下标为1，该二叉树为满二叉树)
//输入示例：
//			2 3
//输出示例：
//			1

#if 0
class LCA {
public:
	int getLCA(int a, int b) {
		if (a == b)
			return a;
		int minchild = 0;
		int grechild = 0;
		if (a<b)
		{
			minchild = a;
			grechild = b;
		}
		else
		{
			minchild = b;
			grechild = a;
		}
		int ca = minchild;
		while (ca != 1)
		{
			int gParent = (grechild / 2);
			while (ca < gParent)
				gParent /= 2;
			if (ca == gParent)
				break;
			ca /= 2;
		}
		return ca;
	}
};


class LCA {
public:
	int getLCA(int a, int b) {
		while (a != b)
		{
			if (a > b)
				a /= 2;
			else
				b /= 2;
		}
		return a;
	}
};
#endif