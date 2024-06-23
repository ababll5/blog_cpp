#include<iostream>
#include<string>    
using namespace std;

//1 创建学生数据内型：学生包括（姓名，年龄，分数）
//自定义数据内型，一些内型集合组成的一个内型
//语法 struct 内型名称 {成员列表}
struct sb//student
{
  //成员列表

  //姓名
   string name;
  //年龄
   int year;
  //分数
  int test;
}s3; //顺便定义


//2 通过学生内型创建具体学生



int main(void)
{
    //2.1 struct student s1
    //下面的struct关键字可以不写
    struct sb s1;
    //给s1赋值
    s1.name = "张三";
    s1.year = 18;
    s1.test = 100;

cout<<"姓名: "<<s1.name<<" 年龄: "<<s1.year<<" 成绩: "<<s1.test<<endl;

//2.2 struct student s2 = {……}
struct sb s2 = {"小红",17,89};
cout<<"姓名: "<<s2.name<<" 年龄: "<<s2.year<<" 成绩: "<<s2.test<<endl;

//2.3 在定义结构体时顺便创建结构体变量 （不建议用）
 //看main函数上面的struct
s3.name = "张四";
    s3.year = 18;
    s3.test = 100;

    return 0;
}