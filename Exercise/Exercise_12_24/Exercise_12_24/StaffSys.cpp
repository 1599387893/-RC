#include"StaffSys.h"
/*-------------------------------------�� �� ��-------------------------------------*/
istream & Date::operator>>(istream &in)
{
	char ch;
	in>>year>>ch>>month>>ch>>day;		/*�����ʽ��'/'�ָ�*/
	//in >> year >> month >> day;				/*�����ʽ���ո�ָ�*/
	return in;
}
ostream & Date::operator<<(ostream &out) const
{
	//out<<year<<"/"<<month<<"/"<<day<<" ";			/*�����ʽ��'/'�ָ�*/
	out << year << " " << month << " " << day << " ";			/*�����ʽ���ո�ָ�*/
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
	time_t te = time(NULL);				/*��䷵�ص�ֻ��һ��ʱ���*/
	tm* t = localtime(&te);
	int year = t->tm_year + 1900;		/*��С���䣬���������0��*/
	if (this->GetAge() < 0)	return false;	/* δ���� */
	if (this->year < (year - 100) || this->year > year)	return false;/*δ���������Ѿ����������ڵ���100��(����)*/
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
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)	/*������*/
		{
			if (day<1 || day>29)
			{
				return false;		/*����������29��*/
			}
			else if (day<1 || day>28)
			{
				return false;		/*ƽ��������28��*/
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

/*------------------------�� ʦ ��--------------------------------------*/
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

/*------------------------ְ �� ��--------------------------------------*/


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


/*------------------------�� �� ��--------------------------------------*/

void Manage::SaveData() const
{
	g_num_t = Teachdata.size();
	g_num_w = Workdata.size();

	/**�ļ�˳��**/
	ofstream wout("Worker.dat", ios::out);/* ��ȡְ���ļ� */
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

	ofstream tout("Teacher.dat", ios::out);/* ��ȡ��ʦ�ļ� */
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
	/**�ļ�˳��**/
	ifstream win("Worker.dat", ios::in);
	if (!win)
	{
		cout << "��ʧ�ܣ�û���ҵ�Worker�ļ�" << endl;
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
		cout << "��ʧ�ܣ�û���ҵ�Teacher�ļ�" << endl;
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
	cout << "���������룺\t\t\t\t\t\t\"��Q/qȡ��\"" << endl;
	Format_t();
	cout << endl;
	Teacher *te = new Teacher;
	cin >> *te;			//bug���޷��ж������Ƿ�����
	cout << endl;
	//��ջ�����		��ֹ������������ѭ��
	cin.clear();
	cin.sync();
	/*   ����������Ϣ�Ƿ�Ϸ������Ϸ����ʧ��   */
	if ((te->Number()) >= pow(10.0, SIZE) || (te->Number()) <= 0)
	{    /* ���ڱ������   ��   ���������󣬳��ָ��� */
		cout << "\tȡ����������������\n\t\t�˳����..." << endl;
		return false;
	}
	if (FindTeacher_num(te->Number()))
	{
		cout << "\n���棺��������������Ա�ظ������ʧ�ܣ�����\n";
		return false;
	}
	if (!(te->CheckBirthData()))
	{
		cout << "\n���棺������������������ʧ��\n";
		return false;
	}
	if (!(te->CheckWorkData()))
	{
		cout << "\n���棺���빤�������������ʧ��\n";
		return false;
	}
	if (FindTeacher_name(te->Name()))
	{
		cout << "\n���ѣ�����������������Ա�ظ�\n";
	}

	Teachdata.push_back(te);
	cout << "\t����ӳɹ�!!!��" << endl;
	return true;
}
bool Manage::AddWorker()		//����ְ��
{
	cout << "���������룺\t\t\t\t\t\t\"��Q/qȡ��\"" << endl;
	Format_w();
	cout << endl;
	Worker *tw = new Worker;
	cin >> *tw;					//bug���޷��ж������Ƿ�����
	cout << endl;
	//��ջ�����				��ֹ������������ѭ��
	cin.clear();
	cin.sync();
	/*   ����������Ϣ�Ƿ�Ϸ������Ϸ����ʧ��   */
	if ((tw->Number()) >= pow(10.0, SIZE) || (tw->Number()) <= 0)
	{    /* ���ڱ������   ��   ���������󣬳��ָ��� */
		cout << "\tȡ����������������\n\t\t�˳����..." << endl;
		return false;
	}
	if (FindWorker_num(tw->Number()))
	{
		cout << "\n���棺��������������Ա�ظ������ʧ�ܣ�����\n";
		return false;
	}
	if (!(tw->CheckBirthData()))
	{
		cout << "\n���棺������������������ʧ��\n";
		return false;
	}
	if (!(tw->CheckWorkData()))
	{
		cout << "\n���棺���빤�������������ʧ��\n";
		return false;
	}
	if (FindWorker_name(tw->Name()))	/* ������������ӳɹ� */
	{
		cout << "\n���ѣ�����������������Ա�ظ�\n";
	}
	Workdata.push_back(tw);
	cout << "\t����ӳɹ�!!!��" << endl;
	return true;
}

void Manage::DelItemTeacher()			//ɾ������
{
	cout << "��������Ҫɾ��������\n\t��>>";
	string _name;
	cin >> _name;
	vector<Teacher*>::const_iterator it_t = Teachdata.begin();
	while ((*it_t)->Name() != _name)
	{
		++it_t;
		if (it_t == Teachdata.end())
		{
			cout << "����������󣬲��޴���" << endl;
			return;
		}
	}

	Teachdata.erase(it_t);
	cout << "ɾ���ɹ�";
}
void Manage::DelItemWorker()
{
	cout << "��������Ҫɾ��������\n\t��>>";
	string _name;
	cin >> _name;
	vector<Worker*>::const_iterator it_w = Workdata.begin();
	while ((*it_w)->Name() != _name)
	{
		++it_w;
		if (it_w == Workdata.end())
		{
			cout << "����������󣬲��޴���" << endl;
			return;
		}
	}

	Workdata.erase(it_w);
	cout << "ɾ���ɹ�";
}

bool Manage::FindTeacher_name(string _name = "")		//���ҽ�ʦ
{
	bool flg = false;		//�����ֻ���ң����Ǳ�������������
	if (_name == "")
	{
		cout << "��������Ҫ��ѯ������\n\t��>>";
		cin >> _name;
		flg = true;			//ֻ����
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
			cout << (flg == true ? "����������󣬲��޴���\n" : "");
			return false;
		}
	}

	Format_t();
	cout << "����" << endl;
	(*it_t)->display();

	return true;
}
bool Manage::FindWorker_name(string _name = "")		//����ְ��
{
	bool flg = false;		//�����ֻ���ң����Ǳ�������������
	if (_name == "")
	{
		cout << "��������Ҫ��ѯ������\n\t��>>";
		cin >> _name;
		flg = true;			//ֻ����
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
			cout << (flg == true ? "����������󣬲��޴���\n" : "");
			return false;
		}
	}

	Format_w();
	cout << "����" << endl;
	(*it_w)->display();

	return true;
}

bool Manage::FindTeacher_num(int _num = 0)
{
	bool flg = false;	//��ǵ��ú���ʱ�����õĲ��ҹ��ܻ������øú����ж�����
	if (_num == 0)		/*flg=true���ò��ҹ��ܣ���Ҫ������ҽ��*/
	{					/*flg=false ���ж���٣�����������ҽ��*/
		cout << "��������Ҫ��ѯ�ı��\n\t>>";
		cin >> _num;
		flg = true;
	}
	//��ջ�����		��ֹ������������ѭ��
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
			cout << (flg == true ? "����������󣬲��޴���\n" : "");
			return false;
		}
	}

	if (flg)		//ֻ����
	{
		Format_t();
		cout << "����" << endl;
		(*it_t)->display();
	}

	return true;
}
bool Manage::FindWorker_num(int _num = 0)
{
	bool flg = false;		//��ǵ��ú���ʱ�����õĲ��ҹ��ܻ������øú����ж�����
	if (_num == 0)			/*flg=true���ò��ҹ��ܣ���Ҫ������ҽ��*/
	{						/*flg=false ���ж���٣�����������ҽ��*/
		cout << "��������Ҫ��ѯ�ı��\n\t>>";
		cin >> _num;
		flg = true;
	}
	//��ջ�����		��ֹ������������ѭ��
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
			cout << (flg == true ? "����������󣬲��޴���\n" : "");
			return false;
		}
	}

	if (flg)		//ֻ����
	{
		Format_w();
		cout << "����" << endl;
		(*it_w)->display();
	}

	return true;
}

void Manage::UpdateTeacher()	//�޸Ľ�ʦ-�����
{
	cout << "\t\t\t\t\t\t\"��'0'ȡ��\"\n��������Ҫ�޸ĵı��:\n\t��>>";
	char _number;
	cin >> _number;
	//��ջ�����		��ֹ�������(������)������ѭ��
	cin.clear();
	cin.sync();
	/*  ע����������Ӣ���ַ�����Ѹ��ַ���ascall��д��_number�� */
	vector<Teacher*>::const_iterator it_t = Teachdata.begin();
	while ((*it_t)->Number() != _number)
	{
		++it_t;
		if (it_t == Teachdata.end())
		{
			cout << "���������󣬲��޴���" << endl;
			return;
		}
	}

	cout << "�ҵ�һ�����>>\n" << *(*it_t) << "\n(�޸�)�����롪��>" << endl;
	Format_t();
	cout << endl;
	cin >> *(*it_t);
	cout << "�޸ĳɹ�" << endl;
}
void Manage::UpdateWorker()	//�޸�ְ��
{
	cout << "\t\t\t\t\t\t\"��'0'ȡ��\"\n��������Ҫ�޸ĵı��:\n\t��>>";
	int _number = 0;
	cin >> _number;
	//��ջ�����		��ֹ�������(������)������ѭ��
	cin.clear();
	cin.sync();
	/*  ע����������Ӣ���ַ�����Ѹ��ַ���ascall��д��_number�� */
	vector<Worker*>::const_iterator it_w = Workdata.begin();
	while ((*it_w)->Number() != _number)
	{
		++it_w;
		if (it_w == Workdata.end())
		{
			cout << "���������󣬲��޴���" << endl;
			return;
		}
	}

	cout << "�ҵ�һ�����>>\n" << *(*it_w) << "\n(�޸�)�����롪��>" << endl;
	Format_t();
	cout << endl;
	cin >> *(*it_w);
	cout << "�޸ĳɹ�" << endl;
}

void Manage::ShowDataTeacher()const	//�������
{
	cout << "\n��ʦ>>>\t\t\t\t\t\t\t\t   [������ʱ������]" << endl;
	Format_t();
	cout << "����" << endl;
	vector<Teacher*>::const_iterator it_t = Teachdata.begin();
	while (it_t != Teachdata.end())
	{
		(*it_t)->display();
		++it_t;
	}
}
void Manage::ShowDataWorker()const	//�������
{
	cout << "\nְ��>>>\t\t\t\t\t\t\t\t   [������ʱ������]" << endl;
	Format_w();
	cout << "����" << endl;
	vector<Worker*>::const_iterator it_w = Workdata.begin();
	while (it_w != Workdata.end())
	{
		(*it_w)->display();
		++it_w;
	}
}

void Manage::Aver_ageTeacher()
{
	cout << "\n��ʦ>>>" << endl;
	cout << "\n��ʦƽ�����䣺" << g_age_t / g_num_t << endl;
	/*	���ӹ��ܣ�
	ͨ��ѭ���������߶���ȫ�ֱ����ķ�ʽ������ʵ�ֶԲ�ͬ
	�Ա𣬲�ְͬλ�Ľ�ʦ��ƽ������ */
}
void Manage::Aver_ageWorker()
{
	cout << "\nְ��>>>" << endl;
	cout << "\nְ��ƽ�����䣺" << g_age_w / g_num_w << endl;
	/*	���ӹ��ܣ�
	ͨ��ѭ���������߶���ȫ�ֱ����ķ�ʽ������ʵ�ֶԲ�ͬ
	�Ա𣬲�ְͬλ�Ľ�ʦ��ƽ������ */
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
		cout << "----------��ӭ�����ְ����Ϣ����ϵͳ--------------------" << endl;
		cout << "        1---��ʦ��Ϣ      2---ְ����Ϣ" << endl;
		cout << "        3---�����Ϣ      4---��������" << endl;
		cout << "        5---ƽ������      6---ͳ������" << endl;
		cout << "        0---�˳�" << endl;
		cout << "---------------------------------------------------------" << endl;
		cout << "����������ѡ��--->";
		cin >> tag;
		//��ջ�����		��ֹ������������ѭ��
		cin.clear();
		cin.sync();
		system("cls");
		switch (tag)
		{
		case 0:
			cout << "\t\t��л����ʹ��(�ޣ��ޣ�\n\t\t�˳�ϵͳ��... ���ݱ�����......\n" << endl;	return;
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
			cout << "������Ҫ���ҵ�������>>\n\t>>>";
			string _name;
			cin >> _name;
			if (!FindTeacher_name(_name))
			{
				if (!FindWorker_name(_name))
				{
					cout << "���޴��ˣ�����ʧ��" << endl;
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
			cout << "\n���ν�ʦ��>>" << g_num_t << "��\n"
				<< "\n����ְ����>>" << g_num_w << "��\n" << endl;
			/* ���ӹ��ܣ�ͳ�Ʋ�ͬ���䣬�Ա�ְλ�� */
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
		//��ջ�����		��ֹ������������ѭ��
		cin.clear();
		cin.sync();
		system("cls");

		switch (chose)
		{
		case 1: AddTeacher();			break;	//��ӹ��� 
		case 2: UpdateTeacher();		break;	//�޸Ĺ��� 
		case 3: ShowDataTeacher();   	break;	//��ʾ���� 
		case 4: FindTeacher_name();		break;	//�������ҹ��� 
		case 5: FindTeacher_num();		break;	//��Ų��ҹ��� 
		case 6:	Aver_ageTeacher();		break;	//ƽ������
		case 7: DelItemTeacher();		break;	//ɾ������
		default:								//�˳�����
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
		//��ջ�����		��ֹ������������ѭ��
		cin.clear();
		cin.sync();
		system("cls");

		switch (chose)
		{
		case 1: AddWorker();			break;	//��ӹ��� 
		case 2: UpdateWorker();			break;	//�޸Ĺ��� 
		case 3: ShowDataWorker();   	break;	//��ʾ���� 
		case 4: FindWorker_name();		break;	//�������ҹ��� 
		case 5:	FindWorker_num();		break;	//��Ų��ҹ���
		case 6:	Aver_ageWorker();		break;	//ƽ������
		case 7: DelItemWorker();		break;	//ɾ������
		default:								//�˳�����
			system("cls");
			return;
			break;
		}
	}
	cout << "---------------------------------------------------------" << endl;
}


void TeacherMenu()		//��ʦ�˵�
{
	cout << "\n�ѽ��룺��ʦ����ϵͳ" << endl;
	cout << "----------�� �� �� ��ʦ��Ϣ���� �� �� �� --------------" << endl;
	cout << "         1---��ӳ�Ա      2---�޸���Ϣ" << endl;
	cout << "         3---�����Ϣ      4---��������" << endl;
	cout << "         5---��Ų���      6---ƽ������" << endl;
	cout << "         7---ɾ����Ϣ      8---�˳�" << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << "����������ѡ��--->:";
}

void WorkerMenu()		//ְ���˵�
{
	cout << "\n�ѽ��룺ְ������ϵͳ" << endl;
	cout << "----------�� �� �� ְ����Ϣ���� �� �� �� --------------" << endl;
	cout << "         1---��ӳ�Ա      2---�޸���Ϣ" << endl;
	cout << "         3---�����Ϣ      4---��������" << endl;
	cout << "         5---��Ų���      6---ƽ������" << endl;
	cout << "         7---ɾ����Ϣ      8---�˳�" << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << "����������ѡ��--->:";
}


void Format_t()
{
	cout.width(6);;
	cout << "��ʦ���  ����  �Ա�     ����    ��������   ��λ  �μӹ���ʱ��  ְ��  ����ϵ  \t";
}
void Format_w()
{
	cout.width(6);;
	cout << "ְ�����  ����  �Ա�     ����    ��������   ��λ  �μӹ���ʱ��  ������  ����  \t";
}




