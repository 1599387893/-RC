//���üӼ��˳����ӷ�
//����ʹ��+��-��*��/����������ţ�


//�ⷨһ
//�������
int add(int a, int b)
{
	_asm;
	{
		MOV EAX, a;
		MOV ECX, b;
		ADD EAX, ECX;
	}
}

//�ⷨ��
//λ����
//1.����������൱��ÿһλ��ӣ��������ǽ�λ��
//2.���������룬������һλ���൱����ý�λ��

class Solution {
public:
	int Add(int num1, int num2)
	{
		while (num2)
		{
			int sum = num1^num2;
			int carray = (num1 & num2) << 1;
			num1 = sum;
			num2 = carray;
		}
		return num1;
	}
};