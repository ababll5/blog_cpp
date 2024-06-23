#include <iostream>
#include <string>
using namespace std;

// 结构体指针

// 定义学生结构体
struct sd // 学生的缩写
{
    string name; // 名字
    int yesr;    // 年龄
    int test;    // 分数
};

int main(void)
{
    // 1创建学生结构体变量
    sd s = {"张三", 18, 100};

    // 2通过指针指向结构体变量
    sd *p = &s;

    // 3通过执指针问结构体变量中的数据
    // 通过指针访问结构体变量用->
    cout << " name " << p->name
         << " yesr " << p->yesr
         << " test " << p->test << endl;

    return 0;
}