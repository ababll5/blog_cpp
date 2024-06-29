
/* 1系统要求
通讯录系统是一个可以记录亲人、好友性息的工具。
利用c++来实现一个通讯录管理系统

系统中需要实现的功能如下:
添加联系人:   向通讯录中添加新人，性息包括(姓名、性别、年龄、联系电话、家庭住址)最多记录1000人
显示联系人：显示通讯录中所有联系人信息
删除联系人：按照姓名进行删除指定联系人
查找联系人：按照姓名查找指定联系人信息
修改联系人：按照姓名重新修改指定联系人
清空联系人：清空通讯录中所有性息
退出通讯录：推出当前使用的通讯录*/

#include"菜单.h"
#include <iostream>
#include <string>
using namespace std;
#define max 1000 // 常量人数方便维护


// 联系人结构体
struct people
{
    // 姓名
    string Mname;

    // 性别  1男 2女
    int Man;

    // 年龄
    int Mage;

    // 电话
    string Mphone;

    // 住址
    string Maddr;
};

// 通讯录结构体
struct addbooks
{
    // 保存联系人的数组
    struct people peopleArr[max];

    // 通讯录中当前记录联系人的人的个数
    int peosize;
};

void arrpeople(struct addbooks* dsb)
{
    // 判断通讯录是否满，满了就不加
    if (dsb->peosize == max)
    {
        cout << "通讯录已满,无法添加!" << endl;
        return;
    }
    else
    {
        // 添加具体联系人

        // 姓名
        string name;
        cout << "请输入姓名" << endl;
        cin >> name;
        dsb->peopleArr[dsb->peosize].Mname = name;
    }

    // 性别
    while (true)
    {
        int a = 0; // 性别选择
        cout << "请输入性别 1、男 2、女" << endl;
        cin >> a;

        // 输入1h或2,否则不会退出循环
        if (a == 1 || a == 2)
        {
            dsb->peopleArr[dsb->peosize].Man = a;
            break;
        }
        cout << "***** 错误 *******" << endl;
        cout << "   请输入1或2" << endl;
        cout << "*****************" << endl;
    }

    // 年龄
    while (true)
    {
        int age = 0;
        cout << "请输入年龄" << endl;
        cin >> age;
        if (age > 200)
        {
            cout << "你家老人" << age << "岁啊！？" << endl;
        }

        else if (age < 1)
        {
            cout << "还没出生呢等大点再记录，不急哈" << endl;
        }
        else
        {
            dsb->peopleArr[dsb->peosize].Mage = age; // 正确的

            break;
        }
    }

    // 电话
    cout << "请输入联系电话：" << endl;
    string phone;
    cin >> phone;
    dsb->peopleArr[dsb->peosize].Mphone = phone;

    // 地址
    cout << "请输入住址" << endl;
    string Msdarr;
    cin >> Msdarr;
    dsb->peopleArr[dsb->peosize].Maddr = Msdarr;

    // 更新通讯录人数
    dsb->peosize++;
    cout << "添加成功" << endl;
    cin.get(); // 输入地址也是输入所以作废
    cout << "按任意建继续";
    cin.get();
    system("cls"); // 清屏
}



// 显示联系人
void printPeople(addbooks* dsb)
{
    // 判断人数是否为0，如为0则输出“还没有联系人哦～“
    if (dsb->peosize == 0)
    {
        cout << "还没有联系人哦～" << endl;
    }
    else
    {
        for (int i = 0; i < dsb->peosize; i++)
        {
            cout << "姓名 " << dsb->peopleArr[i].Mname << "\t"
                << "性别 " << (dsb->peopleArr[i].Man == 1 ? "男" : "女") << "\t"
                << "年龄 " << dsb->peopleArr[i].Mage << "\t"
                << "电话 " << dsb->peopleArr[i].Mphone << "\t"
                << "住址 " << dsb->peopleArr[i].Maddr << endl;
        }
    }
    cout << "按任意建继续";
    cin.get();
    cin.get();
    system("cls"); // 清屏
}



// 检测联系人是否存在，如果存在，返回联系人在通讯录中的位置，不存在return-1
// 参数1：通讯录是否有人  参数2：对比姓名
int isExist(addbooks* dsb, string name)
{
    for (int i = 0; i < dsb->peosize; i++)
    {
        //找到用户输入得姓名
        if (dsb->peopleArr[i].Mname == name)
        {
            return i;
        }
    }

    return -1;  //没找到
}


//删除指定联系人
void delpeople(addbooks* dsb)
{
    cout << "输入要删得联系人" << endl; 
    string name;
    cin >> name;

    //接收结果  res == -1 没有    res == 找到了
    int res = isExist(dsb, name);
    if(res != -1)   // 如果res不等于-1
    {
       //找到了要进行删除了
        for (int i = res; i < dsb->peosize; i++)
        {
            //数据前移
            dsb->peopleArr[i] = dsb->peopleArr[i + 1];
            
        }
        dsb->peosize--; //更新人数
        cout << "删除成功" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
       
    }

    system("pause");
    system("cls");
}

//查找联系人
void chazhao(addbooks* dsb)
{
    cout << "请输入要查找得联系人" << endl;
    string name;
    cin >> name;

    int rest = isExist(dsb, name);
    if (rest != -1)  // 如果rest不等于-1
    {
        /*还有更简单的
   cout << "姓名 " << dsb->peopleArr[rest].Mname << "\t"
        << "性别 " << (dsb->peopleArr[rest].Man == 1 ? "男" : "女") << "\t"
        << "年龄 " << dsb->peopleArr[rest].Mage << "\t"
         << "电话 " << dsb->peopleArr[rest].Mphone << "\t"
        << "住址 " << dsb->peopleArr[rest].Maddr << endl; */
       
        cout << "找到了" << endl;
            for (int j = 0; j < dsb->peosize; j++)
            {
                //找到用户输入得姓名
                if (dsb->peopleArr[j].Mname == name)
                {
                    cout << "姓名 " << dsb->peopleArr[j].Mname << "\t"
                        << "性别 " << (dsb->peopleArr[j].Man == 1 ? "男" : "女") << "\t"
                        << "年龄 " << dsb->peopleArr[j].Mage << "\t"
                        << "电话 " << dsb->peopleArr[j].Mphone << "\t"
                        << "住址 " << dsb->peopleArr[j].Maddr << endl;
                    system("pause");
                    
                }
            }
            system("cls");
    }
    else
    {
        cout << "查无此人" << endl;
    }
}

//修改联系人
void xiugai(addbooks* dsb)
{
    cout << "请输入要修改联系人的姓名" << endl;
        string name;
    cin >> name;

    int rs = isExist(dsb,name);

    if (rs != -1)  // 如果rs不等于-1
    {
        // 性别
        while (true)
        {
            int a = 0; // 性别选择
            cout << "请输入性别 1、男 2、女" << endl;
            cin >> a;

            // 输入1h或2,否则不会退出循环
            if (a == 1 || a == 2)
            {
                dsb->peopleArr[rs].Man = a;
                break;
            }
            cout << "***** 错误 *******" << endl;
            cout << "   请输入1或2" << endl;
            cout << "*****************" << endl;
        }

        // 年龄
        while (true)
        {
            int age = 0;
            cout << "请输入年龄" << endl;
            cin >> age;
            if (age > 200)
            {
                cout << "你家老人" << age << "岁啊！？" << endl;
            }

            else if (age < 1)
            {
                cout << "还没出生呢等大点再记录，不急哈" << endl;
            }
            else
            {
                dsb->peopleArr[rs].Mage = age; // 正确的

                break;
            }
        }

        // 电话
        cout << "请输入联系电话：" << endl;
        string phone;
        cin >> phone;
        dsb->peopleArr[rs].Mphone = phone;

        // 地址
        cout << "请输入住址" << endl;
        string Msdarr;
        cin >> Msdarr;
        dsb->peopleArr[rs].Maddr = Msdarr;

    }
    else
    {
        cout << "查无此人" << endl;
    }
    system("pause");
    system("cls");
}

void cleanpeople(addbooks* dsb)
{
    dsb->peosize = 0;  //假清空
    cout << "通讯录清空完毕" << endl;
    system("pause");
    system("cls");
}

int main(void)
{

    // 创建通讯录结构体变量
    addbooks dsb;

    // 初始化通讯录中当前的人员个数
    dsb.peosize = 0;

    int in = 0; // 创建用户输入的变量

    while (true)
    {
        // 菜单的调用
        showMenu();
        cin >> in; // 用户输入

        switch (in)
        {
        case 1:              // 添加联系人
            arrpeople(&dsb); // 利用地址传递，可以修饰实参
            break;

        case 2: // 显示联系人
            printPeople(&dsb);
            break;

        case 3: // 删除联系人
            delpeople(&dsb);
            break;

        /*{      测试阶段
            cout << "输入要删得联系人" << endl;
            string name;
            cin >> name;

            if (isExist(&dsb, name) == -1)
            {
                cout << "没找到" << endl;
            }
            else
            {
                cout << "找到了" << endl;
            }
        }*/
            

        case 4: // 查找联系人
            chazhao(&dsb);
            break;

        case 5: // 修改联系人
            xiugai(&dsb);
            break;

        case 6: // 清空联系人
            cleanpeople(&dsb);
            break;

        case 0: // 退出通讯录
            cout << "good bye!" << endl;

            cin.get(); // 按任意建退出
            cout << "按人任意建继续";
            cin.get(); // 因为输入了0也算是输入所以前面的作废得再写一次

            return 0; // 程序正常退出
            break;

        default:
            cout<<"请输入0~6的数"<<endl;
            system("cls");
            break;
        }
    }
}
