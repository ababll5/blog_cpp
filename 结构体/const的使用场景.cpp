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

void nout(struct sd *s)           //输出结构体变量信息的函数
{
 cout<<"姓名 "<<s->name<<endl
     <<" 年龄 "<<s->age<<endl
     <<" 分数 "<<s->test<<endl;

}

int main(void)
{
    //创建结构体变量
    struct sd s= {"张三",18,90};

    //通过函数打印结构体变量的信息
    nout(&s);

    return 0;
}