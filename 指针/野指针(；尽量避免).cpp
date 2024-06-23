#include<iostream>
using namespace std;

int main(void)
{
   //野指针
   //程序中，避免野指针
   int*p =(int *)0x1100;
   cout<<*p<<endl;

    return 0;
}