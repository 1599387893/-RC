#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int IN = 0;    // 在数字中
const int OUT = 1;    // 在数字外
stack<char> opt;    // 操作符栈
stack<double> val;    // 操作数栈
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
            cout << "表达式含有错误字符，请重新输入。" << endl;
            return false;
        }
    }
    theString = res;
    return true;
}
/* 将中缀表达式转换成后缀表达式 */
bool change(string &from, string &to){
    int theInt = 0;        // 暂存数字
    int state = OUT;     // 初始状态：在数字外
    char c;
    /*
    if(from[from.length() - 1] != '='){
        cout << "等于号语法有误！" << endl;
        return false;
    }
    */
    for(int i = 0; i < from.length(); i++){
        c = from[i];
        if(isdigit(c)){
            theInt *= 10;
            theInt += c - '0';
            state = IN;    // 状态：在数字内
        }
        else{
            if(state == IN){        // 刚刚处理了数字
                to += to_string(theInt) + ' ';
                theInt = 0;
            }
            if(c == '='){
                /*
                if(i != from.length() - 1){
                    cout << "等于号语法有误！" << endl;
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
                    cout << "括号匹配有误！" << endl;
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
            state = OUT;    // 状态：在数字外
        }
    }
    while(!opt.empty()){
        /*
        if(opt.top() == '('){
            cout << "括号匹配有误！" << endl;
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
    int theInt = 0;        // 暂存数字
    int state = OUT;     // 初始状态：在数字外
    char c;
    for(int i = 0; i < theExp.length(); i++){
        c = theExp[i];
        if(isdigit(c)){
            theInt *= 10;
            theInt += c - '0';
            state = IN;    // 状态：在数字内
        }
        else{
            if(state == IN){        // 刚刚处理了数字
                val.push(theInt);
                theInt = 0;
            }
            double x, y;
            if(c != ' '){
                /*
                if(val.empty()){
                    cout << "操作数语法错误！" << endl;
                    return false;
                }
                */
                x = val.top();
                val.pop();
                /*
                if(val.empty()){
                    cout << "操作数语法错误！" << endl;
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
                        cout << "未知的错误！" << endl;
                }
            }
            state = OUT;
        }
    }
    /*
    if(val.size() != 1){
        cout << "缺少操作符！" << endl;
        return false;
    }
    */
    return true;
}
int main()
{
    cout << "请保证所有的操作数均为正整数，且不要输入(+x)的形式。" << endl;
    cout << "若答案为小数，请按照四舍五入的规则保留小数点后三位。" << endl;
    while(true){
        // 清空流
        cin.clear();
        cin.sync();
        // 初始化操作：清空两个栈
        while(!opt.empty()){
            opt.pop();
        }
        while(!val.empty()){
            val.pop();
        }
        
        // 输入表达式
        string init_exp;
        cout << "请输入以'='结尾的表达式，或输入\"exit\"退出：";
        getline(cin, init_exp);
        
        if(init_exp == string("exit")){
            break;
        }
        
        // 去除空格并检查是否有非法字符
        if(!del_space(init_exp))
            continue;
        
        // 转换为后缀表达式
        string cng_exp;
        cng_exp.clear();
        if(!change(init_exp, cng_exp))
            continue;
        cout << "此表达式转换为后缀表达式为：" << cng_exp << endl;
        
        // 计算后缀表达式
        if(!compute(cng_exp))
            continue;
        
        double stdans = val.top();
        cout << "此表达式的运算结果为：" << stdans << endl;
    }
    return 0;
} 