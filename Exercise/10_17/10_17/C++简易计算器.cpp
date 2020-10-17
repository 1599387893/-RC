#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int IN = 0;    // ��������
const int OUT = 1;    // ��������
stack<char> opt;    // ������ջ
stack<double> val;    // ������ջ
char opt_set[10] = "+-*/()=";


bool in_set(char theChar){
    for(int i = 0; i < 7; i++){
        if(theChar == opt_set[i])
            return true;
    }
    return false;
}
int level(char theOpt){
    for(int i = 0; i < 7; i++){
        if(theOpt == opt_set[i])
            return i;
    }
    return -1;
}
bool del_space(string &theString){
    string res;
    for(int i = 0; i < theString.length(); i++){
        if(in_set(theString[i]) || isdigit(theString[i])){
            res += theString[i];
        }
        else if(theString[i] == ' ')
            ;
        else{
            cout << "���ʽ���д����ַ������������롣" << endl;
            return false;
        }
    }
    theString = res;
    return true;
}
/* ����׺���ʽת���ɺ�׺���ʽ */
bool change(string &from, string &to){
    int theInt = 0;        // �ݴ�����
    int state = OUT;     // ��ʼ״̬����������
    char c;
    /*
    if(from[from.length() - 1] != '='){
        cout << "���ں��﷨����" << endl;
        return false;
    }
    */
    for(int i = 0; i < from.length(); i++){
        c = from[i];
        if(isdigit(c)){
            theInt *= 10;
            theInt += c - '0';
            state = IN;    // ״̬����������
        }
        else{
            if(state == IN){        // �ոմ���������
                to += to_string(theInt) + ' ';
                theInt = 0;
            }
            if(c == '='){
                /*
                if(i != from.length() - 1){
                    cout << "���ں��﷨����" << endl;
                    return false;                    
                }
                */
                break;
            }
            else if(c == '(')
                opt.push(c);
            else if(c == ')'){
                while(!opt.empty() && opt.top() != '('){
                    to += opt.top();
                    to += ' ';
                    opt.pop();
                }
                /*
                if(opt.empty()){
                    cout << "����ƥ������" << endl;
                    return false;
                }
                else
                */
                    opt.pop();
            }
            else{
                while(true){
                    if(opt.empty() || opt.top() == '(')
                        opt.push(c);
                    else if(level(c) > level(opt.top()))
                        opt.push(c);
                    else{
                        to += opt.top();
                        to += ' ';
                        opt.pop();
                        continue;
                    }
                    break;
                }
            }
            state = OUT;    // ״̬����������
        }
    }
    while(!opt.empty()){
        /*
        if(opt.top() == '('){
            cout << "����ƥ������" << endl;
            return false;
        }
        */
        to += opt.top();
        to += ' ';
        opt.pop();
    }
    return true;
} 
bool compute(string &theExp){
    int theInt = 0;        // �ݴ�����
    int state = OUT;     // ��ʼ״̬����������
    char c;
    for(int i = 0; i < theExp.length(); i++){
        c = theExp[i];
        if(isdigit(c)){
            theInt *= 10;
            theInt += c - '0';
            state = IN;    // ״̬����������
        }
        else{
            if(state == IN){        // �ոմ���������
                val.push(theInt);
                theInt = 0;
            }
            double x, y;
            if(c != ' '){
                /*
                if(val.empty()){
                    cout << "�������﷨����" << endl;
                    return false;
                }
                */
                x = val.top();
                val.pop();
                /*
                if(val.empty()){
                    cout << "�������﷨����" << endl;
                    return false;
                }
                */
                y = val.top();
                val.pop();
                switch(c){
                    case '+':
                        val.push(x + y);
                        break;
                    case '-':
                        val.push(y - x);
                        break;
                    case '*':
                        val.push(x * y);
                        break;
                    case '/':
                        val.push(y / x);
                        break;
                    default:
                        cout << "δ֪�Ĵ���" << endl;
                }
            }
            state = OUT;
        }
    }
    /*
    if(val.size() != 1){
        cout << "ȱ�ٲ�������" << endl;
        return false;
    }
    */
    return true;
}
int main()
{
    cout << "�뱣֤���еĲ�������Ϊ���������Ҳ�Ҫ����(+x)����ʽ��" << endl;
    cout << "����ΪС�����밴����������Ĺ�����С�������λ��" << endl;
    while(true){
        // �����
        cin.clear();
        cin.sync();
        // ��ʼ���������������ջ
        while(!opt.empty()){
            opt.pop();
        }
        while(!val.empty()){
            val.pop();
        }
        
        // ������ʽ
        string init_exp;
        cout << "��������'='��β�ı��ʽ��������\"exit\"�˳���";
        getline(cin, init_exp);
        
        if(init_exp == string("exit")){
            break;
        }
        
        // ȥ���ո񲢼���Ƿ��зǷ��ַ�
        if(!del_space(init_exp))
            continue;
        
        // ת��Ϊ��׺���ʽ
        string cng_exp;
        cng_exp.clear();
        if(!change(init_exp, cng_exp))
            continue;
        cout << "�˱��ʽת��Ϊ��׺���ʽΪ��" << cng_exp << endl;
        
        // �����׺���ʽ
        if(!compute(cng_exp))
            continue;
        
        double stdans = val.top();
        cout << "�˱��ʽ��������Ϊ��" << stdans << endl;
    }
    return 0;
} 