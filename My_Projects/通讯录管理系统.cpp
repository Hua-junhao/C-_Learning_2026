#include <iostream>  
using namespace std;
#define Max 1000
#include<string>
struct Person
{
    string Name;
    int Sex;
    int Age;
    string Phone;
    string Address;
};
struct Addressbooks
{
    struct Person personArray[Max];
    int size;
};

void showMenu()
{
    cout << "1.添加联系人" << endl;
    cout << "2.显示联系人" << endl;
    cout << "3.删除联系人" << endl;
    cout << "4.查找联系人" << endl;
    cout << "5.修改联系人" << endl;
    cout << "6.清空联系人" << endl;
    cout << "0.退出通讯录" << endl;
}
void addPerson(Addressbooks * abs)
{
    if (abs->size==Max)
    {
        cout<<"通讯录已满"<<endl;
        return;
    }
    else
    {
        string name;
        cout<<"请输入姓名："<<endl;
        cin>>name;
        abs->personArray[abs->size].Name=name;
        cout<<"请输入性别："<<endl;
        cout<<"1--男"<<endl;
        cout<<"2--女"<<endl;
        int sex=0;
        while(true)
        {
            cin>>sex;
            if (sex==1 || sex==2)
            {
                abs->personArray[abs->size].Sex=sex;
                break;
            }
            cout<<"输入有误，重新输入"<<endl;
        }
        cout<<"请输入年龄："<<endl;
        int age=0;
        cin>>age;
        abs->personArray[abs->size].Age=age;
        cout<<"请输入电话："<<endl;
        string phone;
        cin>>phone;
        abs->personArray[abs->size].Phone=phone;
        cout<<"请输入住址："<<endl;
        string address;
        cin>>address;
        abs->personArray[abs->size].Address=address;
        abs->size++;
        cout<<"添加成功"<<endl;
        cin.clear();
        cin.ignore(1000,'\n');
        system("pause");//按任意键继续
        

    }
}
void showPerson(Addressbooks * abs)
{
    if (abs->size==0)
    {
        cout<<"记录为空"<<endl;
    }
    else
    {
        for (int i=0;i<abs->size;i++)
        {
            cout<<"姓名："<<abs->personArray[i].Name<<endl;
            cout<<"性别："<<(abs->personArray[i].Sex==1 ?"男":"女")<<endl;
            cout<<"年龄："<<abs->personArray[i].Age<<endl;
            cout<<"电话："<<abs->personArray[i].Phone<<endl;
            cout<<"住址："<<abs->personArray[i].Address<<endl;
        }
    }
    system("pause");//按任意键继续
}    
int isExist(Addressbooks *abs,string name)
{
     for (int i=0;i<abs->size;i++)
     {
        if(abs->personArray[i].Name==name)
        {
            return i;
        }
        
     }
     return -1;
}
void deletePerson(Addressbooks *abs)
{
    cout<<"请输入您要删除的联系人"<<endl;
    string name;
    cin>>name;
    int ret=isExist(abs,name);
    if (ret!=-1)
    {
        for (int i=ret;i<abs->size;i++)
        {
            abs->personArray[i]=abs->personArray[i+1];
        }
        abs->size--;
        cout<<"删除成功"<<endl;
        system("pause");
    }
}
void findPerson(Addressbooks * abs)
{
    cout<<"请输入要查找的人"<<endl;
    string name;
    cin>>name;
    int ret=isExist(abs,name);
    if (ret!=-1)
    {
        cout<<"姓名："<<abs->personArray[ret].Name<<endl;
        cout<<"性别："<<(abs->personArray[ret].Sex==1 ?"男":"女")<<endl;
        cout<<"年龄："<<abs->personArray[ret].Age<<endl;
        cout<<"电话："<<abs->personArray[ret].Phone<<endl;
        cout<<"住址："<<abs->personArray[ret].Address<<endl;
    }
    else{
        cout<<"未找到"<<endl;
    }
    system("pause");
    system("cls");
}
void modifyPerson(Addressbooks * abs)
{
    cout<<"请输入要修改的联系人"<<endl;
    string name;
    cin>>name;
    int ret=isExist(abs,name);
    if (ret!=-1)
    {
        string name;
        cout<<"请输入姓名："<<endl;
        cin>>name;
        abs->personArray[ret].Name=name;
        cout<<"请输入性别："<<endl;
        cout<<"1--男"<<endl;
        cout<<"2--女"<<endl;
        int sex=0;
        while(true)
        {
            cin>>sex;
            if (sex==1 || sex==2)
            {
                abs->personArray[ret].Sex=sex;
                break;
            }
            cout<<"输入有误，重新输入"<<endl;
        }
        cout<<"请输入年龄："<<endl;
        int age=0;
        cin>>age;
        abs->personArray[ret].Age=age;
        cout<<"请输入电话："<<endl;
        string phone;
        cin>>phone;
        abs->personArray[ret].Phone=phone;
        cout<<"请输入住址："<<endl;
        string address;
        cin>>address;
        abs->personArray[ret].Address=address;
        cout<<"修改成功"<<endl; 
    }
    else
    {
        cout<<"查无此人"<<endl;
    }
}
void cleanPerson(Addressbooks * abs)
{
    abs->size=0;
    cout<<"清除成功"<<endl;
    system("pause");;
    system("cls");
}
int main()
{
    system("chcp 65001");
    Addressbooks abs;
    abs.size=0;
    int select=0;

    while (true)
    {
        showMenu();
        cin>>select;
        cin.clear();
        cin.ignore(1000,'\n');
        switch (select)
        {
            case 1: //1.添加联系人
                addPerson(&abs);
                break;
            case 2: 
                showPerson(&abs);//2.显示联系人
                break;
            case 3: //3.删除联系人
            {   
                cout<<"请输入删除联系人姓名： "<<endl;
                string name;
                cin>>name;
                // if (isExist(&abs,name)==-1)
                // {
                //     cout<<"查无此人"<<endl;
                // }
                // else 
                // {
                //     cout<<"找到了"<<endl;
                //   system("pause");
                // }
                deletePerson(&abs); 
                system("pause");
                break; 
            } 
            case 4: //4.查找联系人
                findPerson(&abs);
                break;
            case 5: //5.修改联系人
                modifyPerson(&abs);
                break;
            case 6: //6.清空联系人
                cleanPerson(&abs);
                break;
            case 0: //0.退出通讯录
                cout<<"欢迎下次使用"<<endl;
                system("pause");
                return 0;
            default:
                break; 
        }
    }
    system("pause");
    return 0;
}