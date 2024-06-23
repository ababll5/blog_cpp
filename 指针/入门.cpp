#include<iostream>
using namespace std;

int main(void)
{
// 1定义指针
int a=10;
//指针定义语法:数据内型*指针变量名；
int*p;
//让指针记录变量a的地址
p = &a;
cout<<"a的地址"<<&a<<endl<<endl;
cout<<"指针p："<<p<<endl<<endl;
//2使用指针
//可以通过解引用找到指针指向的内存
//指针前加*代表解引用，找到指针指向的内存数据
*p = 1000;   //找到a并修改他    
cout<<"a ="<<a<<endl;
cout<<"*p ="<<*p<<endl;
    return 0;
}