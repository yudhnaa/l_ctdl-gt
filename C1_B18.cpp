#include <iostream>
using namespace std;
#define MAX 100
char stack[MAX];
int n;
// Init stack
void init();
// Stop console
void stopConsole();
// Process stack
int popStack();
// Is stack full
bool isFull();
// Is stack empty
bool isNotEmpty();
// Insert an element
int insertEle(char x);
// Is current char operation ?
bool isOperat(char x);
// Check precious of operation
int preci(char x);
// main() function
int main()
{
    init();
    string expression;
    cout << "Nhap vao bieu thuc: ";
    getline(cin, expression);
    string postfix = "";
    char current = ' ';
    for (int i = 0; i < expression.length(); i++)
    {
        current = expression[i];
        if (!isOperat(current)) // This is not operator then push to queue
        {
            postfix += current;
        }
        else if (preci(current) == 0)
        {
            if (current == '(')
            {
                insertEle(current);
            }
            else
            {
                while (n >= 0 && stack[n] != '(') // This is ")" then pop all operator after "(" to queue
                {
                    postfix += popStack();
                }
                popStack(); // remove "(" from stack
            }
        }
        else
        {
            if (preci(current) <= preci(stack[n]) && current != stack[n]) // if precious(current) <= precious(stack[n]) && not the same
            {
                while (preci(current) <= preci(stack[n]) && current != stack[n]) // then pop all them to queue
                {
                    postfix += popStack();
                    insertEle(current);
                }
            }
            else
            {
                insertEle(current);
            }
        }
    }
    while (n != -1) // pop all remain operator to queue
    {
        postfix += popStack();
    }
    cout << postfix << "\n";
}

/* others function */

// Init stack
void init()
{
    n = -1;
}
// Stop console
void stopConsole()
{
    cout << "\nPress Enter To Continue...";
    cin.ignore();
    cin.get();
}
// A Node's data structure
int popStack()
{
    return stack[n--];
}
// Is stack full
bool isFull()
{
    if (n == 100 - 1)
    {
        return true;
    }
    return false;
}
// Is stack empty
bool isNotEmpty()
{
    return !isFull();
}
// Insert an element
int insertEle(char x)
{
    if (!isFull())
    {
        stack[++n] = x;
        return 1;
    }
    return 0;
}
// Is current char operation ?
bool isOperat(char x)
{
    switch (x)
    {
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
        return true;
        break;
    default:
        return false;
        break;
    }
}
// Check precious of operation
int preci(char x)
{
    switch (x)
    {
    case '(':
    case ')':
        return 0;
        break;
    case '+':
    case '-':
        return 1;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case '^':
        return 3;
        break;
    default:
        return -1;
        break;
    }
}