/*
// Definition for Employee.
class Employee {
public:
int id;
int importance;
vector<int> subordinates;
};
*/

class Solution {
public:
	set<int> isHandle; //记录已经处理过的员工，防止重复计算
	int getImportance(vector<Employee*> employees, int id) {
		int res = 0;
		Employee* cur;
		for (auto emp : employees)
			if (emp->id == id)
				cur = emp;
		res = cur->importance;
		for (auto sub : cur->subordinates)
			if (isHandle.find(sub) == isHandle.end())
				res += getImportance(employees, sub);
		return res;
	}
};