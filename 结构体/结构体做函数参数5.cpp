// 结构体做函数参数
// 传递方式
// 值传递
// 指针传递

#include <iostream>
#include <string>
using namespace std;

// 定义学生结构体
struct sd
{
    string name; // 名字
    int age;     // 年龄
    int test;    // 分数
};

// 输出学生基本信息函数

// 1‘值传递
void ncout(struct sd s)
{
    s.name = "我"; // 只改变这次自定义函数中的输出结果
    cout << "子函数中的值传递输出 " << endl
         << " 姓名: " << s.name
         << endl
         << " 年龄: " << s.age << endl
         << " 分数: " << s.test
         << endl;
}

// 地址传递(要用到指针)
void pncout(struct sd *s)
{
    s->name = "你"; // 全局修改
    cout << "子函数中的地址传递输出 " << endl
         << " 姓名: " << s->name
         << endl
         << " 年龄: " << s->age << endl
         << " 分数: " << s->test
         << endl;
}

int main(void)
{
    // 将学生传入一个参数中 并打印

    // 创建结构体变量
    struct sd s;
    s.name = "膝关节";
    s.age = 19;
    s.test = 98;

    // 自定义函数输出
    ncout(s); // 自定义函数，做到输出学生的基本信息
    cout << endl
         << endl;

    pncout(&s); // 自定义函数，做到输出学生的基本信息
    cout << endl
         << endl;

    // 正常的输出方式，不过我们今天要用的是自定义函数来输出这一穿
    cout << "main函数中打印" << endl
         << " 姓名： " << s.name
         << endl
         << "年龄" << s.age
         << endl
         << "分数" << s.test << endl;

    return 0;
}