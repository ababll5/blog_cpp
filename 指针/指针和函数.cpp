#include <iostream>
using namespace std;

// 两数交换
void sb(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

void sb2(int *p, int *p2)
{
    int temp = *p;
    *p = *p2;
    *p2 = temp;
    cout << endl;
    cout << "a = " << *p << endl;
    cout << "b = " << *p2 << endl;
}

int main(void)
{
    // 指针和函数
    // 1 值传递
    int a = 10;
    int b = 20;
    sb(a, b);

    // 2 地址传递

    sb2(&a, &b);
    cout << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}