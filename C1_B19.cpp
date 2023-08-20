#include <iostream>
#include <fstream>
using namespace std;
// A student info
struct Student
{
    string ID;
    string Name;
    int Birth;
    string Address;
    bool Sex; // male is true and female is false
};
// A node
struct Node
{
    Student info;
    Node *next;
    Node *previous;
};
// Initialize
Node *first, *last;
void init()
{
    first = NULL;
    last = NULL;
}
void stopConsole()
{
    cin.ignore();
    cin.get();
}
// insert
int insert(Student x)
{
    Node *q = new Node;
    q->info = x;
    q->next = NULL;
    q->previous = last;
    if (last != NULL)
    {
        last->next = q;
    }
    else
        first = q;
    last = q;
    return 1;
}
// input from file
void inputFromFile(ifstream &inputFile)
{
    string temp;
    Student student;
    while (!inputFile.eof())
    {
        string temp;
        getline(inputFile, student.ID);
        getline(inputFile, student.Name);
        getline(inputFile, temp);
        student.Birth = stoi(temp);
        getline(inputFile, student.Address);
        getline(inputFile, temp);
        student.Sex = temp == "true" ? true : false;
        insert(student);
    }
    cout << "Nhap thanh cong.";
    stopConsole();
}
// input from keyboard
Student inputFromKey(int n, string x)
{

    Student student;
    string temp;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap hoc sinh thu " << i << ".";
        cout << "Nhap ID: ";
        cin >> student.ID;
        cout << "Nhap ten: ";
        cin >> student.Name;
        cout << "Nhap Nam sinh: ";
        cin >> student.Birth;
        cout << "Nhap Dia chi: ";
        cin >> student.Address;
        cout << "Nhap gioi tinh (Nam/Nu): ";
        cin >> temp;
        student.Sex = temp == "Nam" ? true : false;
        if (x == "menu")
            insert(student);
    }
    return student;
}
// xuat danh sach
int output2Console()
{
    Node *p = first;
    if (first == NULL)
    {
        cout << "Danh sach trong";
        stopConsole();
        return 0;
    }
    else
    {
        int n = 0;
        while (p != NULL)
        {
            cout << ++n << ".\n";
            cout << "ID: " << p->info.ID << "\n";
            cout << "Ten: " << p->info.Name << "\n";
            cout << "Nam sinh: " << p->info.Birth << "\n";
            cout << "Dia chi: " << p->info.Address << "\n";
            string sex = p->info.Sex == true ? "Nam" : "Nu";
            cout << "Gioi tinh: " << sex << "\n";
            p = p->next;
        }
        stopConsole();
        return 1;
    }
}
// filter
int filter(string str)
{
    Node *p = first;
    int i = 0;
    while (p != NULL)
    {
        if (p->info.ID == str || p->info.Name == str || p->info.Address == str)
        {
            cout << ++i << ".\n";
            cout << "ID: " << p->info.ID << "\n";
            cout << "Ten: " << p->info.Name << "\n";
            cout << "Nam sinh: " << p->info.Birth << "\n";
            cout << "Dia chi: " << p->info.Address << "\n";
            string sex = p->info.Sex == true ? "Nam" : "Nu";
            cout << "Gioi tinh: " << sex << "\n";
        }
        p = p->next;
    }
    return i;
}
int filter(int x)
{
    Node *p = first;
    int i = 0;
    while (p != NULL)
    {
        if (p->info.Birth == x)
        {
            cout << ++i << ".\n";
            cout << "ID: " << p->info.ID << "\n";
            cout << "Ten: " << p->info.Name << "\n";
            cout << "Nam sinh: " << p->info.Birth << "\n";
            cout << "Dia chi: " << p->info.Address << "\n";
            string sex = p->info.Sex == true ? "Nam" : "Nu";
            cout << "Gioi tinh: " << sex << "\n";
        }
        p = p->next;
    }
    return i;
}
int filter(bool x)
{
    Node *p = first;
    int i = 0;
    while (p != NULL)
    {
        if (p->info.Sex == x)
        {
            cout << ++i << ".\n";
            cout << "ID: " << p->info.ID << "\n";
            cout << "Ten: " << p->info.Name << "\n";
            cout << "Nam sinh: " << p->info.Birth << "\n";
            cout << "Dia chi: " << p->info.Address << "\n";
            string sex = p->info.Sex == true ? "Nam" : "Nu";
            cout << "Gioi tinh: " << sex << "\n";
        }
        p = p->next;
    }
    return i;
}
// filter student by property
int filterByPro()
{
    Node *p = first;
    if (first == NULL)
    {
        cout << "Danh sach trong";
        stopConsole();
        return 0;
    }
    else
    {
        // system("clear");
        Student student;
        int check = -1;
        cout << "1. Loc theo ID\n";
        cout << "2. Loc theo ten\n";
        cout << "3. Loc theo nam sinh\n";
        cout << "4. Loc theo dia chi\n";
        cout << "5. Loc theo gioi tinh\n";
        cout << "Chon dieu kien loc: ";
        int choose = 0;
        cout << "Nhap gia tri: ";
        switch (choose)
        {
        case 1:
            cin >> student.ID;
            check = filter(student.ID);
            break;
        case 2:
            cin >> student.Name;
            check = filter(student.Name);
            break;
        case 3:
            cin >> student.Birth;
            check = filter(student.Birth);
            break;
        case 4:
            cin >> student.Address;
            check = filter(student.Address);
            break;
        case 5:
            cin >> student.Sex;
            check = filter(student.Sex);
            break;
        default:
            cout << "Vui long chon tu 1 den 5";
            stopConsole();
            return 0;
            break;
        }
        if (check == 0)
        {
            cout << "Khong co hoc sinh khop voi dieu kien";
            stopConsole();
            return 0;
        }
        return 1;
    }
}
// insert
int insertAtAny()
{
    cout << "Nhap vi tri muon them vao: ";
    int i = 0;
    cin >> i;
    int count = 0;
    Node *p = first;
    while (count != i && p != NULL)
    {
        count++;
        p = p->next;
    }
    if (count < i && p == NULL)
    {
        cout << "Vi tri khong hop le";
        stopConsole();
        return 0;
    }
    else
    {
        Node *q = new Node;
        q->info = inputFromKey(1, "insertAtAny");
        if (i == 1)
        {
            insert(q->info);
        }
        else if (p->next == NULL)
        {
            q->next = NULL;
            q->previous = last;
            if (last != NULL)
            {
                last->next = q;
            }
            else
                first = q;
            last = q;
        }
        else
        {
            q->previous = p;
            q->next = p->next;
            p->next = q;
        }
    }
    return 1;
}
// delete
int deleteAny()
{
    Node *p = first;
    if (first == NULL)
    {
        cout << "Danh sach trong";
        stopConsole();
        return 0;
    }
    else
    {
        cout << "Danh sach cac sinh vien: \n";
        output2Console();
        cout << "Nhap vi tri sinh vien muon xoa: ";
        int i = -1;
        cin >> i;
        int count = 1;
        while (count != i && p != NULL)
        {
            p = p->next;
            count++;
        }
        if (p == NULL)
        {
            cout << "Vui long nhap so hop le!";
            stopConsole();
            return 0;
        }
        else
        {
            if (i == 1) // delete first
            {
                if ((p->next == NULL) && (p->previous == NULL)) // only 1
                {
                    first = NULL;
                }
                else
                {
                    first = p->next;
                    first->previous = NULL;
                }
                delete p;
            }
            else
            {
                Node *q = p->previous;
                if (p->next == NULL) // delete last
                {
                    q->next = NULL;
                }
                else // delete any
                {
                    q->next = p->next;
                    p->next->previous = q;
                }
                delete p;
            }
            return 1;
        }
    }
}
// swap2ele
void swap2Ele(Node *p, Node *q)
{
    Student student;
    student = p->info;
    p->info = q->info;
    q->info = student;
}
//
int ident(string x)
{
    return (x == "ID" ? 1 : (x == "Name" ? 2 : (x == "Birth" ? 3 : (x == "Address" ? 4 : 5))));
}
// sort
int sort(string pro)
{
    Node *p = first;
    int iden = ident(pro);
    if (iden == 1)
    {
        for (Node *p = first; p != NULL; p = p->next)
        {
            for (Node *q = p->next; q != NULL; q = q->next)
            {
                if (stoi(p->info.ID) > stoi(q->info.ID))
                {
                    swap2Ele(p, q);
                }
            }
        }
    }
    else if (iden == 2)
    {
        for (Node *p = first; p != NULL; p = p->next)
        {
            for (Node *q = p->next; q != NULL; q = q->next)
            {
                int result = strcmp(p->info.Name.c_str(), q->info.Name.c_str());
                if (result > 0)
                {
                    swap2Ele(p, q);
                }
            }
        }
    }
    else if (iden == 3)
    {
        for (Node *p = first; p != NULL; p = p->next)
        {
            for (Node *q = p->next; q != NULL; q = q->next)
            {
                if (p->info.Birth > q->info.Birth)
                {
                    swap2Ele(p, q);
                }
            }
        }
    }
    else if (iden == 4)
    {
        for (Node *p = first; p != NULL; p = p->next)
        {
            for (Node *q = p->next; q != NULL; q = q->next)
            {
                int result = strcmp(p->info.Address.c_str(), q->info.Address.c_str());
                if (result)
                {
                    swap2Ele(p, q);
                }
            }
        }
    }
    else
    {
        for (Node *p = first; p != NULL; p = p->next)
        {
            for (Node *q = p->next; q != NULL; q = q->next)
            {
                int qS = q->info.Sex == true ? 1 : 2;
                int pS = p->info.Sex == true ? 1 : 2;
                if (pS > qS)
                {
                    swap2Ele(p, q);
                }
            }
        }
    }
    return 1;
}
// sort by pro
int sortByPro()
{
    Node *p = first;
    if (first == NULL)
    {
        cout << "Danh sach trong";
        stopConsole();
        return 0;
    }
    else
    {
        // system("clear");
        int check = -1;
        cout << "1. Sort theo ID\n";
        cout << "2. Sort theo ten\n";
        cout << "3. Sort theo nam sinh\n";
        cout << "4. Sort theo dia chi\n";
        cout << "5. Sort theo gioi tinh\n";
        cout << "Chon dieu kien sort: ";
        int choose = 0;
        cin >> choose;
        switch (choose)
        {
        case 1:
            check = sort("ID");
            break;
        case 2:
            check = sort("Name");
            break;
        case 3:
            check = sort("Birth");
            break;
        case 4:
            check = sort("Address");
            break;
        case 5:
            check = sort("Sex");
            break;
        default:
            cout << "Vui long chon tu 1 den 5";
            stopConsole();
            return 0;
            break;
        }
        return 1;
    }
}
// writeFile
void write(Student student, ofstream &outputFile)
{
    outputFile << student.ID << endl;
    outputFile << student.Name << endl;
    outputFile << student.Birth << endl;
    outputFile << student.Address << endl;
    outputFile << (student.Sex == true ? "Nam" : "Nu") << endl;
}
// write to file
int write2File(ofstream &outputFile)
{
    Node *p = first;
    if (first == NULL)
    {
        cout << "Danh sach trong";
        stopConsole();
        return 0;
    }
    else
    {
        for (; p != NULL; p = p->next)
        {
            write(p->info, outputFile);
        }
        cout << "Xuat ra file thanh cong, vui long kiem tra file output.txt";
        stopConsole();
        return 1;
    }
}
// show menu
int menu(ifstream &inputFile, ofstream &outputFile)
{
    system("clear");
    cout << "1. Nhap danh sach sinh vien tu ban phim\n";
    cout << "2. Nhap danh sach sinh vien tu file txt\n";
    cout << "3. Xuat danh sach sinh vien\n";
    cout << "4. Loc danh sach sinh vien theo thanh phan\n";
    cout << "5. Them 1 sinh vien vao vi tri bat ki\n";
    cout << "6. Xoa 1 sinh vien bat ky trong danh sach\n";
    cout << "7. Sap xep danh sach sinh vien theo thanh phan\n";
    cout << "8. Ghi danh sach thoa dieu kien ra tap tin txt\n";
    cout << "9. Thoat\n";
    cout << "Chon: ";
    int choose = 0;
    cin >> choose;
    switch (choose)
    {
    case 1:
    {
        cout << "Nhap so sinh vien: ";
        int n = 0;
        cin >> n;
        inputFromKey(n, "menu");
        break;
    }
    case 2:
        inputFromFile(inputFile);
        break;
    case 3:
        output2Console();
        break;
    case 4:
        filterByPro();
        break;
    case 5:
        insertAtAny();
        break;
    case 6:
        deleteAny();
        break;
    case 7:
        sortByPro();
        break;
    case 8:
        write2File(outputFile);
        break;
    case 9:
    case 0:
    default:
        return 0;
        break;
    }
    return 1;
}
int main()
{
    init();
    ifstream inputFile;
    inputFile.open("/Users/yudhna_/CTDL_GT/input.txt");
    ofstream outputFile;
    outputFile.open("/Users/yudhna_/CTDL_GT/output.txt");
    if (inputFile.is_open() && outputFile.is_open())
    {
        while (menu(inputFile, outputFile) != 0)
        {
        }
    }
    else
    {
        cout << "Vui long kiem tra tap tin input.txt va output.txt";
        stopConsole();
    }

    return 0;
}