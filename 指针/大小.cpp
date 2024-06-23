#include<iostream>
using namespace std;

int main(void)
{
//指针所占内存空间
int a=10;
//int * p;
//p = &a;
 int*p =&a;
 //32位(x86)4字节
 //64位(x64)8字节
 //所有
 cout<<"int * = "<<sizeof(int*)<<endl;
 cout<<"float * = "<<sizeof(float*)<<endl;
 cout<<"double * = "<<sizeof(double*)<<endl;
 cout<<"char * = "<<sizeof(char*)<<endl;


return 0;
}   