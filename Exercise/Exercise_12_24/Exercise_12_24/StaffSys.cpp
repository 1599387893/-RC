#include"StaffSys.h"
/*-------------------------------------日 期 类-------------------------------------*/
istream & Date::operator>>(istream &in)
{
	char ch;
	in>>year>>ch>>month>>ch>>day;		/*输入格式：'/'分隔*/
	//in >> year >> month >> day;				/*输入格式：空格分隔*/
	return in;
}
ostream & Date::operator<<(ostream &out) const
{
	//out<<year<<"/"<<month<<"/"<<day<<" ";			/*输出格式：'/'分隔*/
	out << year << " " << month << " " << day << " ";			/*输出格式：空格分隔*/
	return out;
}

int Date::GetAge() const
{
	time_t te;
	time(&te);
	tm * p = localtime(&te);

	return  p->tm_year + 1900 - year;
}

bool Date::Chack()
{
	time_t te = time(NULL);				/*这句返回的只是一个时间戳*/
	tm* t = localtime(&te);
	int year = t->tm_year + 1900;		/*最小年龄，当年出生，0岁*/
	if (this->GetAge() < 0)	return false;	/* 未出生 */
	if (this->year < (year - 100) || this->year > year)	return false;/*未出生或是已经出生但大于等于100岁(退休)*/
	switch (month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		if (day<1 || day>31)
		{
			return false;
		}
		break;
	case 4: case 6: case 9:case 11:
		if (day<1 || day>30)
		{
			return false;
		}
		break;
	case 2:
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)	/*是闰年*/
		{
			if (day<1 || day>29)
			{
				return false;		/*闰年二月最多29天*/
			}
			else if (day<1 || day>28)
			{
				return false;		/*平年二月最多28天*/
			}
		}
		break;
	default:
		return false;
		break;
	}

	return true;
}

istream & operator>>(istream &in, Date &date)
{
	date >> in;
	return in;
}

ostream & operator<<(ostream &out, const Date &date)
{
	date << out;
	return out;
}

/*------------------------教 师 类--------------------------------------*/
string Teacher::Name()const
{
	return this->name;
}

int Teacher::Number()const
{
	return this->number;
}

void Teacher::display()const
{
	cout << *this << this->birthtime.GetAge() << endl;
}

bool Teacher::CheckBirthData()
{
	return (this->birthtime).Chack();
}
bool Teacher::CheckWorkData()
{
	return (this->worktime).Chack();
}

int Teacher::Getage()const
{
	return this->birthtime.GetAge();
}

istream & Teacher::operator>>(istream &in)
{
	in >> number >> name >> sex >> salary >> birthtime >> post >> worktime >> position >> department;
	return in;
}
ostream & Teacher::operator<<(ostream &out) const
{
	cout.width(5);
	cout.fill(0);
	out << setw(5) << setfill('0') << number << "\t  " << name << "\t" << sex << "\t " << salary << "\t " << birthtime << "  "
		<< post << "     " << worktime << " \t" << position << " \t" << department << "\t";
	return out;
}

istream & operator>>(istream &in, Teacher &teacher)
{
	teacher >> in;
	return in;
}

ostream & operator<<(ostream &out, const Teacher &teacher)
{
	teacher << out;
	return out;
}

/*------------------------职 工 类--------------------------------------*/


string Worker::Name()const
{
	return this->name;
}

int Worker::Number()const
{
	return this->number;
}

void Worker::display()const
{
	cout << *this << birthtime.GetAge() << endl;
}

int Worker::Getage()const
{
	return this->birthtime.GetAge();
}

bool Worker::CheckBirthData()
{
	return (this->birthtime).Chack();
}
bool Worker::CheckWorkData()
{
	return (this->worktime).Chack();
}

istream & Worker::operator>>(istream &in)
{
	in >> number >> name >> sex >> salary >> birthtime >> post >> worktime >> Technical >> department;
	return in;
}
ostream & Worker::operator<<(ostream &out) const
{
	cout.width(5);
	cout.fill(0);
	out << setw(5) << setfill('0') << number << "\t " << name << "\t " << sex << "\t " << salary << "\t " << birthtime << " "
		<< post << "   " << worktime << "   " << Technical << "  " << department << "\t";
	return out;
}

istream & operator>>(istream &in, Worker &worker)
{
	worker >> in;
	return in;
}

ostream & operator<<(ostream &out, const Worker &worker)
{
	worker << out;
	return out;
}


/*------------------------管 理 类--------------------------------------*/

void Manage::SaveData() const
{
	g_num_t = Teachdata.size();
	g_num_w = Workdata.size();

	/**文件顺序**/
	ofstream wout("Worker.dat", ios::out);/* 读取职工文件 */
	if (!wout)
	{
		cout << "open file \"Worker.txt\" error " << endl;
		return;
	}
	wout << g_num_w << endl;
	vector<Worker*>::const_iterator it_w = Workdata.begin();
	for (; it_w != Workdata.end(); ++it_w)
	{
		wout << *(*it_w) << endl;
	}
	wout.close();

	ofstream tout("Teacher.dat", ios::out);/* 读取教师文件 */
	if (!tout)
	{
		cout << "open file \"Teacher.txt\" error " << endl;
		return;
	}
	tout << g_num_t << endl;
	vector<Teacher*>::const_iterator it_t = Teachdata.begin();
	for (; it_t != Teachdata.end(); ++it_t)
	{
		tout << *(*it_t) << endl;
	}
	tout.close();

}
void Manage::LoadData()
{
	/**文件顺序**/
	ifstream win("Worker.dat", ios::in);
	if (!win)
	{
		cout << "打开失败，没有找到Worker文件" << endl;
		return;
	}
	win >> g_num_w;
	for (int i = 0; i<g_num_w; ++i)
	{
		Worker  *worker = new Worker;
		win >> *worker;
		Workdata.push_back(worker);
		g_age_w += worker->Getage();
	}
	win.close();

	ifstream tin("Teacher.dat", ios::in);
	if (!tin)
	{
		cout << "打开失败，没有找到Teacher文件" << endl;
		return;
	}
	tin >> g_num_t;
	for (int i = 0; i<g_num_t; ++i)
	{
		Teacher *teacher = new Teacher;
		tin >> *teacher;
		Teachdata.push_back(teacher);
		g_age_t += teacher->Getage();
	}
	tin.close();


}

bool Manage::AddTeacher()
{
	cout << "请依次输入：\t\t\t\t\t\t\"按Q/q取消\"" << endl;
	Format_t();
	cout << endl;
	Teacher *te = new Teacher;
	cin >> *te;			//bug尚无法判断输入是否完整
	cout << endl;
	//清空缓冲区		防止输入错误进入死循环
	cin.clear();
	cin.sync();
	/*   检验输入信息是否合法，不合法添加失败   */
	if ((te->Number()) >= pow(10.0, SIZE) || (te->Number()) <= 0)
	{    /* 大于编号上限   或   编号输入错误，呈现负数 */
		cout << "\t取消输入或编号输入错误，\n\t\t退出添加..." << endl;
		return false;
	}
	if (FindTeacher_num(te->Number()))
	{
		cout << "\n警告：输入编号与已有人员重复，添加失败！！！\n";
		return false;
	}
	if (!(te->CheckBirthData()))
	{
		cout << "\n警告：输入出生日期有误，添加失败\n";
		return false;
	}
	if (!(te->CheckWorkData()))
	{
		cout << "\n警告：输入工作日期有误，添加失败\n";
		return false;
	}
	if (FindTeacher_name(te->Name()))
	{
		cout << "\n提醒：输入姓名与已有人员重复\n";
	}

	Teachdata.push_back(te);
	cout << "\t☆添加成功!!!☆" << endl;
	return true;
}
bool Manage::AddWorker()		//增加职工
{
	cout << "请依次输入：\t\t\t\t\t\t\"按Q/q取消\"" << endl;
	Format_w();
	cout << endl;
	Worker *tw = new Worker;
	cin >> *tw;					//bug尚无法判断输入是否完整
	cout << endl;
	//清空缓冲区				防止输入错误进入死循环
	cin.clear();
	cin.sync();
	/*   检验输入信息是否合法，不合法添加失败   */
	if ((tw->Number()) >= pow(10.0, SIZE) || (tw->Number()) <= 0)
	{    /* 大于编号上限   或   编号输入错误，呈现负数 */
		cout << "\t取消输入或编号输入错误，\n\t\t退出添加..." << endl;
		return false;
	}
	if (FindWorker_num(tw->Number()))
	{
		cout << "\n警告：输入编号与已有人员重复，添加失败！！！\n";
		return false;
	}
	if (!(tw->CheckBirthData()))
	{
		cout << "\n警告：输入出生日期有误，添加失败\n";
		return false;
	}
	if (!(tw->CheckWorkData()))
	{
		cout << "\n警告：输入工作日期有误，添加失败\n";
		return false;
	}
	if (FindWorker_name(tw->Name()))	/* 提醒重名，添加成功 */
	{
		cout << "\n提醒：输入姓名与已有人员重复\n";
	}
	Workdata.push_back(tw);
	cout << "\t☆添加成功!!!☆" << endl;
	return true;
}

void Manage::DelItemTeacher()			//删除数据
{
	cout << "请输入想要删除的姓名\n\t—>>";
	string _name;
	cin >> _name;
	vector<Teacher*>::const_iterator it_t = Teachdata.begin();
	while ((*it_t)->Name() != _name)
	{
		++it_t;
		if (it_t == Teachdata.end())
		{
			cout << "姓名输入错误，查无此人" << endl;
			return;
		}
	}

	Teachdata.erase(it_t);
	cout << "删除成功";
}
void Manage::DelItemWorker()
{
	cout << "请输入想要删除的姓名\n\t—>>";
	string _name;
	cin >> _name;
	vector<Worker*>::const_iterator it_w = Workdata.begin();
	while ((*it_w)->Name() != _name)
	{
		++it_w;
		if (it_w == Workdata.end())
		{
			cout << "姓名输入错误，查无此人" << endl;
			return;
		}
	}

	Workdata.erase(it_w);
	cout << "删除成功";
}

bool Manage::FindTeacher_name(string _name = "")		//查找教师
{
	bool flg = false;		//标记是只查找，还是被其他函数调用
	if (_name == "")
	{
		cout << "请输入想要查询的姓名\n\t—>>";
		cin >> _name;
		flg = true;			//只查找
	}
	vector<Teacher*>::const_iterator it_t ;
	if (Teachdata.size() != 0)
		it_t = Teachdata.begin();
	else
		return false;
	while ((*it_t)->Name() != _name)
	{
		++it_t;
		if (it_t == Teachdata.end())
		{
			cout << (flg == true ? "姓名输入错误，查无此人\n" : "");
			return false;
		}
	}

	Format_t();
	cout << "年龄" << endl;
	(*it_t)->display();

	return true;
}
bool Manage::FindWorker_name(string _name = "")		//查找职工
{
	bool flg = false;		//标记是只查找，还是被其他函数调用
	if (_name == "")
	{
		cout << "请输入想要查询的姓名\n\t—>>";
		cin >> _name;
		flg = true;			//只查找
	}
	vector<Worker*>::const_iterator it_w;
	if (Workdata.size() != 0)
		it_w = Workdata.begin();
	else
		return false;
	while ((*it_w)->Name() != _name)
	{
		++it_w;
		if (it_w == Workdata.end())
		{
			cout << (flg == true ? "姓名输入错误，查无此人\n" : "");
			return false;
		}
	}

	Format_w();
	cout << "年龄" << endl;
	(*it_w)->display();

	return true;
}

bool Manage::FindTeacher_num(int _num = 0)
{
	bool flg = false;	//标记调用函数时，调用的查找功能还是利用该函数判断数据
	if (_num == 0)		/*flg=true调用查找功能，需要输出查找结果*/
	{					/*flg=false 中判断真假，无需输出查找结果*/
		cout << "请输入想要查询的编号\n\t>>";
		cin >> _num;
		flg = true;
	}
	//清空缓冲区		防止输入错误进入死循环
	cin.clear();
	cin.sync();
	vector<Teacher*>::const_iterator it_t;
	if (Teachdata.size() != 0)
		it_t = Teachdata.begin();
	else
		return false;
	while ((*it_t)->Number() != _num)
	{
		++it_t;
		if (it_t == Teachdata.end())
		{
			cout << (flg == true ? "姓名输入错误，查无此人\n" : "");
			return false;
		}
	}

	if (flg)		//只查找
	{
		Format_t();
		cout << "年龄" << endl;
		(*it_t)->display();
	}

	return true;
}
bool Manage::FindWorker_num(int _num = 0)
{
	bool flg = false;		//标记调用函数时，调用的查找功能还是利用该函数判断数据
	if (_num == 0)			/*flg=true调用查找功能，需要输出查找结果*/
	{						/*flg=false 中判断真假，无需输出查找结果*/
		cout << "请输入想要查询的编号\n\t>>";
		cin >> _num;
		flg = true;
	}
	//清空缓冲区		防止输入错误进入死循环
	cin.clear();
	cin.sync();
	vector<Worker*>::const_iterator it_w ;
	if (Workdata.size() != 0)
		it_w = Workdata.begin();
	else
		return false;
	while ((*it_w)->Number() != _num)
	{
		++it_w;
		if (it_w == Workdata.end())
		{
			cout << (flg == true ? "姓名输入错误，查无此人\n" : "");
			return false;
		}
	}

	if (flg)		//只查找
	{
		Format_w();
		cout << "年龄" << endl;
		(*it_w)->display();
	}

	return true;
}

void Manage::UpdateTeacher()	//修改教师-按编号
{
	cout << "\t\t\t\t\t\t\"按'0'取消\"\n请输入想要修改的编号:\n\t—>>";
	char _number;
	cin >> _number;
	//清空缓冲区		防止输入错误(非数字)进入死循环
	cin.clear();
	cin.sync();
	/*  注：若输入了英文字符，会把该字符的ascall码写进_number中 */
	vector<Teacher*>::const_iterator it_t = Teachdata.begin();
	while ((*it_t)->Number() != _number)
	{
		++it_t;
		if (it_t == Teachdata.end())
		{
			cout << "编号输入错误，查无此人" << endl;
			return;
		}
	}

	cout << "找到一个结果>>\n" << *(*it_t) << "\n(修改)请输入——>" << endl;
	Format_t();
	cout << endl;
	cin >> *(*it_t);
	cout << "修改成功" << endl;
}
void Manage::UpdateWorker()	//修改职工
{
	cout << "\t\t\t\t\t\t\"按'0'取消\"\n请输入想要修改的编号:\n\t—>>";
	int _number = 0;
	cin >> _number;
	//清空缓冲区		防止输入错误(非数字)进入死循环
	cin.clear();
	cin.sync();
	/*  注：若输入了英文字符，会把该字符的ascall码写进_number中 */
	vector<Worker*>::const_iterator it_w = Workdata.begin();
	while ((*it_w)->Number() != _number)
	{
		++it_w;
		if (it_w == Workdata.end())
		{
			cout << "编号输入错误，查无此人" << endl;
			return;
		}
	}

	cout << "找到一个结果>>\n" << *(*it_w) << "\n(修改)请输入——>" << endl;
	Format_t();
	cout << endl;
	cin >> *(*it_w);
	cout << "修改成功" << endl;
}

void Manage::ShowDataTeacher()const	//输出数据
{
	cout << "\n教师>>>\t\t\t\t\t\t\t\t   [按创建时间排序]" << endl;
	Format_t();
	cout << "年龄" << endl;
	vector<Teacher*>::const_iterator it_t = Teachdata.begin();
	while (it_t != Teachdata.end())
	{
		(*it_t)->display();
		++it_t;
	}
}
void Manage::ShowDataWorker()const	//输出数据
{
	cout << "\n职工>>>\t\t\t\t\t\t\t\t   [按创建时间排序]" << endl;
	Format_w();
	cout << "年龄" << endl;
	vector<Worker*>::const_iterator it_w = Workdata.begin();
	while (it_w != Workdata.end())
	{
		(*it_w)->display();
		++it_w;
	}
}

void Manage::Aver_ageTeacher()
{
	cout << "\n教师>>>" << endl;
	cout << "\n教师平均年龄：" << g_age_t / g_num_t << endl;
	/*	增加功能：
	通过循环遍历或者定义全局变量的方式，可以实现对不同
	性别，不同职位的教师求平均年龄 */
}
void Manage::Aver_ageWorker()
{
	cout << "\n职工>>>" << endl;
	cout << "\n职工平均年龄：" << g_age_w / g_num_w << endl;
	/*	增加功能：
	通过循环遍历或者定义全局变量的方式，可以实现对不同
	性别，不同职位的教师求平均年龄 */
}

void Manage::FreeTeacher()
{
	vector<Teacher*>::const_iterator it_w = Teachdata.begin();
	while (it_w != Teachdata.end())
	{
		delete *it_w;
		++it_w;
	}
	Teachdata.clear();
}
void Manage::FreeWorker()
{
	vector<Worker*>::const_iterator it_w = Workdata.begin();
	while (it_w != Workdata.end())
	{
		delete *it_w;
		++it_w;
	}
	Workdata.clear();
}


void Manage::MainMenu()
{
	int tag = 0;
	do
	{
		cout << "----------欢迎进入教职工信息管理系统--------------------" << endl;
		cout << "        1---教师信息      2---职工信息" << endl;
		cout << "        3---浏览信息      4---姓名查找" << endl;
		cout << "        5---平均年龄      6---统计人数" << endl;
		cout << "        0---退出" << endl;
		cout << "---------------------------------------------------------" << endl;
		cout << "请输入您的选择--->";
		cin >> tag;
		//清空缓冲区		防止输入错误进入死循环
		cin.clear();
		cin.sync();
		system("cls");
		switch (tag)
		{
		case 0:
			cout << "\t\t感谢您的使用(＾０＾）\n\t\t退出系统中... 数据保存中......\n" << endl;	return;
			break;
		case 1:	MangeTeacher();
			break;
		case 2:	MangeWorker();
			break;
		case 3:
			ShowDataTeacher();
			ShowDataWorker();
			cout << endl;
			break;
		case 4:
		{
			cout << "请输入要查找的姓名—>>\n\t>>>";
			string _name;
			cin >> _name;
			if (!FindTeacher_name(_name))
			{
				if (!FindWorker_name(_name))
				{
					cout << "查无此人，查找失败" << endl;
				}
			}
			cout << endl;
		}
			break;
		case 5:
			Aver_ageTeacher();
			Aver_ageWorker();
			cout << endl;
			break;
		case 6:
			cout << "\n现任教师有>>" << g_num_t << "人\n"
				<< "\n现任职工有>>" << g_num_w << "人\n" << endl;
			/* 增加功能：统计不同年龄，性别，职位等 */
			break;
		default:
			break;
		}
	} while (tag != 0);
}

void Manage::MangeTeacher()
{
	int chose;
	while (1)
	{
		TeacherMenu();
		cin >> chose;
		//清空缓冲区		防止输入错误进入死循环
		cin.clear();
		cin.sync();
		system("cls");

		switch (chose)
		{
		case 1: AddTeacher();			break;	//添加功能 
		case 2: UpdateTeacher();		break;	//修改功能 
		case 3: ShowDataTeacher();   	break;	//显示功能 
		case 4: FindTeacher_name();		break;	//姓名查找功能 
		case 5: FindTeacher_num();		break;	//编号查找功能 
		case 6:	Aver_ageTeacher();		break;	//平均年龄
		case 7: DelItemTeacher();		break;	//删除功能
		default:								//退出功能
			system("cls");
			return;
			break;
		}
	}
	cout << "---------------------------------------------------------" << endl;
}

void Manage::MangeWorker()
{
	int chose;
	while (1)
	{
		WorkerMenu();
		cin >> chose;
		//清空缓冲区		防止输入错误进入死循环
		cin.clear();
		cin.sync();
		system("cls");

		switch (chose)
		{
		case 1: AddWorker();			break;	//添加功能 
		case 2: UpdateWorker();			break;	//修改功能 
		case 3: ShowDataWorker();   	break;	//显示功能 
		case 4: FindWorker_name();		break;	//姓名查找功能 
		case 5:	FindWorker_num();		break;	//编号查找功能
		case 6:	Aver_ageWorker();		break;	//平均年龄
		case 7: DelItemWorker();		break;	//删除功能
		default:								//退出功能
			system("cls");
			return;
			break;
		}
	}
	cout << "---------------------------------------------------------" << endl;
}


void TeacherMenu()		//教师菜单
{
	cout << "\n已进入：教师管理系统" << endl;
	cout << "----------★ ☆ ★ 教师信息管理 ★ ☆ ★ --------------" << endl;
	cout << "         1---添加成员      2---修改信息" << endl;
	cout << "         3---浏览信息      4---姓名查找" << endl;
	cout << "         5---编号查找      6---平均年龄" << endl;
	cout << "         7---删除信息      8---退出" << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << "请输入您的选择--->:";
}

void WorkerMenu()		//职工菜单
{
	cout << "\n已进入：职工管理系统" << endl;
	cout << "----------★ ☆ ★ 职工信息管理 ★ ☆ ★ --------------" << endl;
	cout << "         1---添加成员      2---修改信息" << endl;
	cout << "         3---浏览信息      4---姓名查找" << endl;
	cout << "         5---编号查找      6---平均年龄" << endl;
	cout << "         7---删除信息      8---退出" << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << "请输入您的选择--->:";
}


void Format_t()
{
	cout.width(6);;
	cout << "教师编号  姓名  性别     工资    出生日期   岗位  参加工作时间  职称  所在系  \t";
}
void Format_w()
{
	cout.width(6);;
	cout << "职工编号  姓名  性别     工资    出生日期   岗位  参加工作时间  技术级  部门  \t";
}




