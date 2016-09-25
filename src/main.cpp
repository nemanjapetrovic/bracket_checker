#include <iostream>
#include <string>
#include "data_structures/stack.cpp"

using namespace std;

//Importing data from the user
string importData();
//Expression validation
bool expressionIsValid(string data,Stack<char> &stackData, int n);

int main()
{
    //User insert data
    string data = importData();
    int n = data.length();

    //Create stack
    Stack<char> stackData(n);

    //Expression validation
    bool ret;
    ret = expressionIsValid(data,stackData,n);
    cout<<ret<<endl;

    return 0;
}

string importData()
{
    cout<<"Please enter some math expression:"<<endl;
    string data;
    getline(cin,data);
    return data;
};

bool expressionIsValid(string data, Stack<char> &stackData,int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        if(data[i] == '{' || data[i] == '(' || data[i] == '[')
        {
            stackData.push(data[i]);
        }
        else if(data[i] == '}' || data[i] == ')' || data[i] == ']')
        {
            if(stackData.isEmpty())
            {
                return false;//Stack is empty, no opened brackets
            }
            char a = stackData.getTop();
            char b = data[i];
            if(stackData.getTop() == '(' && data[i] == ')')
            {
                stackData.pop();
            }
            else if(stackData.getTop() == '[' && data[i] == ']')
            {
                stackData.pop();
            }
            else if(stackData.getTop() == '{' && data[i] == '}')
            {
                stackData.pop();
            }
            else
            {
                return false;//Example [} or (] or etc.. in the stack
            }
        }
    }
    return stackData.isEmpty();
};