#include <iostream>
using namespace std;
// Stop console
void stopConsole()
{
    string *stop = [];
    getline(cin,stop);

}
// A Node's data structure
struct Node
{
    int info;
    Node *link;
};
Node *first;
// Init first Node
void init()
{
    first = NULL;
}
// Print menu to console
int menu()
{
    system("clear");
    cout<< "Is stack empty ?\n";
    cout << "Is stack full ?\n";
    cout << "Insert an element\n";
    cout << "Delete an element\n";
    cout << "Convert a decimal number to binary base\n";
    cout << "Convert a decimal number to X base\n";
    cout << "Quit\n";
    cout << "Choose: ";
    int choose = 0;
    switch (choose)
    {
    case 1:
        isFull();
        break;
    
    case 2:
        isEmpty()
        break;
    
    case 3:
        insertEle();
        break;
    
    case 4:
        deleteEle();
        break;
    
    case 5:
        dec2Bin();
        break;
    
    case 6:
        dec2XBase();
        break;
    
    case 7:
    default:
        return 0;
        break;
    }
    return 1;
}
int main()
{
    while (menu()!=0)
    {
    }
    
    
    return 0;
}