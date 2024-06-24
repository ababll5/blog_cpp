#include <iostream>
#include <string.h>
#include<ctime>           //获取系统时间
using namespace std;
// 学生结构体
struct student
{
    // 姓名
    string s_name;

    // 成绩
    int test;
};

// 老师的结构体定义
struct teacher
{
    // 姓名
    string t_name;

    // 学生数组
    struct student sdrr[5];
};

// 定义一个给老师和学生赋值的函数
void td(struct teacher tArr[], int len)
{
    string nameT = "ABCDE";
    // 给老师开始赋值
    for (int i = 0; i < len; i++)
    {
        tArr[i].t_name = "Teacher_";
        tArr[i].t_name += nameT[i];

        // 老师的学生Segmentation fault
        for (int j = 0; j < 5; j++)
        {
            tArr[i].sdrr[j].s_name = "student_";
            tArr[i].sdrr[j].s_name += nameT[j];
            
            int ran = rand()%61+40;
            tArr[i].sdrr[j].test = ran;
        }
    }
}

// 自定义打印函数
void print(struct teacher tArr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << "老师的姓名: " << tArr[i].t_name << endl;
        for (int j = 0; j < 5; j++)
        {
            cout << "学生姓名:  " << tArr[i].sdrr[j].s_name
                 << "分数: " << tArr[i].sdrr[j].test << endl;
        }
    }
}

int main(void)
{
    //随机数种子
    srand((unsigned int)time(NULL));

    // 创建三名老师的数组
    struct teacher tArr[3];

    // 通过函数给3名老师的信息赋值，并给老师带的学生信息赋值
    int len = sizeof(tArr) / sizeof(tArr[0]); // 计算长度
    td(tArr, len);

    // 打印所有老师及代的学生的信息
    print( tArr, len);

    cin.get();
    return 0;
}
