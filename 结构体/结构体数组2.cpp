#include<iostream>
#include<string>
using namespace std;
//结构体数组
//1、定义结构体
struct sd       //学生缩写
{
   string name;  //姓名
   int  yesr;    //年龄
   int  test;
};     //记得加;


int main(void)
{
//2、创建结构体数组
  struct sd sdArr[2] = 
  {
    {"张三",18,96},
    {"李四",19,97}
  }; 

     
 
//3、给结构体数组中的元素赋值
    sdArr[1].yesr = 17 ;          //把李四的年龄改为17
 
 //输出
for(int i = 0;i<2;i++)
{
cout<<"姓名: "<<sdArr[i].name
    <<" 年龄: "<<sdArr[i].yesr
    <<" 分数: "<<sdArr[i].test
    <<endl;
}

    return 0;
}