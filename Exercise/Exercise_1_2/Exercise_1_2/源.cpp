#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#if 0
void divisorNum(int& n, vector<int>& divNum)
{
	for (int i = 2; i <= sqrt(n); ++i)
	{
		if (n%i == 0)
		{
			divNum.push_back(i);
			divNum.push_back(n/i);
		}
	}
}
int Jump(int& n, int& m)
{
	vector<int> stepNum(m + 1, 0);
	stepNum[n] = 1;

	for (int i = n; i < m; ++i)
	{
		vector<int> divNum;
		if (stepNum[i] == 0)
			continue;
		divisorNum(i,divNum);
		for (int j = 0; j < divNum.size(); ++j)
		{
			if ((i + divNum[j] <= m) && (stepNum[divNum[j] + i] != 0))
				stepNum[divNum[j] + i] = min(stepNum[divNum[j] + i], stepNum[i] + 1);

			else if (divNum[j] + i <= m)
				stepNum[divNum[j] + i] = stepNum[i] + 1;
		}
	}
	if (stepNum[m] == 0)
		return -1;
	else
		return stepNum[m] - 1;
}
int main()
{
	int n, m;
	while (cin >> n >> m)
		cout<<Jump(n, m)<<endl;
	return 0;
}
#endif
int FindSubString(char* pch) 
{ 
	int count = 0; 
	char * p1 = pch; 
	while (*p1 != '\0') 
	{ 
		if (*p1 == p1[1] - 1) 
		{ 
			p1++; 
			count++; 
		} 
		else 
		{ 
			break; 
		} 
	}
	int count2 = count; 
	while (*p1 != '\0') 
	{ 
		if (*p1 == p1[1] + 1) 
		{ 
			p1++; count2--; 
		} 
		else 
		{ 
			break; 
		} 
	}
	if (count2 == 0) 
		return(count); 
	return(0); 
}
void ModifyString(char* pText)
{
	char* p1 = pText;
	char* p2 = p1;
	while (*p1 != '\0')
	{
		int count = FindSubString(p1); 
		if (count > 0) 
		{ 
			*p2++ = *p1; 
			sprintf(p2, "%i", count); 
			while (*p2 != '\0') 
			{ 
				p2++; 
			}
			p1 += count + count + 1; 
		}
		else 
		{ 
			*p2++ = *p1++; 
		}
	}

}
int main()
{
	char text[32] = "XYBCDCBABABA";
	ModifyString(text);
	return 0;

}