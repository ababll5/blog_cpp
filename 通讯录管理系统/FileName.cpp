
/* 1ϵͳҪ��
ͨѶ¼ϵͳ��һ�����Լ�¼���ˡ�������Ϣ�Ĺ��ߡ�
����c++��ʵ��һ��ͨѶ¼����ϵͳ

ϵͳ����Ҫʵ�ֵĹ�������:
�����ϵ��:   ��ͨѶ¼��������ˣ���Ϣ����(�������Ա����䡢��ϵ�绰����ͥסַ)����¼1000��
��ʾ��ϵ�ˣ���ʾͨѶ¼��������ϵ����Ϣ
ɾ����ϵ�ˣ�������������ɾ��ָ����ϵ��
������ϵ�ˣ�������������ָ����ϵ����Ϣ
�޸���ϵ�ˣ��������������޸�ָ����ϵ��
�����ϵ�ˣ����ͨѶ¼��������Ϣ
�˳�ͨѶ¼���Ƴ���ǰʹ�õ�ͨѶ¼*/

#include"�˵�.h"
#include <iostream>
#include <string>
using namespace std;
#define max 1000 // ������������ά��


// ��ϵ�˽ṹ��
struct people
{
    // ����
    string Mname;

    // �Ա�  1�� 2Ů
    int Man;

    // ����
    int Mage;

    // �绰
    string Mphone;

    // סַ
    string Maddr;
};

// ͨѶ¼�ṹ��
struct addbooks
{
    // ������ϵ�˵�����
    struct people peopleArr[max];

    // ͨѶ¼�е�ǰ��¼��ϵ�˵��˵ĸ���
    int peosize;
};

void arrpeople(struct addbooks* dsb)
{
    // �ж�ͨѶ¼�Ƿ��������˾Ͳ���
    if (dsb->peosize == max)
    {
        cout << "ͨѶ¼����,�޷����!" << endl;
        return;
    }
    else
    {
        // ��Ӿ�����ϵ��

        // ����
        string name;
        cout << "����������" << endl;
        cin >> name;
        dsb->peopleArr[dsb->peosize].Mname = name;
    }

    // �Ա�
    while (true)
    {
        int a = 0; // �Ա�ѡ��
        cout << "�������Ա� 1���� 2��Ů" << endl;
        cin >> a;

        // ����1h��2,���򲻻��˳�ѭ��
        if (a == 1 || a == 2)
        {
            dsb->peopleArr[dsb->peosize].Man = a;
            break;
        }
        cout << "***** ���� *******" << endl;
        cout << "   ������1��2" << endl;
        cout << "*****************" << endl;
    }

    // ����
    while (true)
    {
        int age = 0;
        cout << "����������" << endl;
        cin >> age;
        if (age > 200)
        {
            cout << "�������" << age << "�갡����" << endl;
        }

        else if (age < 1)
        {
            cout << "��û�����صȴ���ټ�¼��������" << endl;
        }
        else
        {
            dsb->peopleArr[dsb->peosize].Mage = age; // ��ȷ��

            break;
        }
    }

    // �绰
    cout << "��������ϵ�绰��" << endl;
    string phone;
    cin >> phone;
    dsb->peopleArr[dsb->peosize].Mphone = phone;

    // ��ַ
    cout << "������סַ" << endl;
    string Msdarr;
    cin >> Msdarr;
    dsb->peopleArr[dsb->peosize].Maddr = Msdarr;

    // ����ͨѶ¼����
    dsb->peosize++;
    cout << "��ӳɹ�" << endl;
    cin.get(); // �����ַҲ��������������
    cout << "�����⽨����";
    cin.get();
    system("cls"); // ����
}



// ��ʾ��ϵ��
void printPeople(addbooks* dsb)
{
    // �ж������Ƿ�Ϊ0����Ϊ0���������û����ϵ��Ŷ����
    if (dsb->peosize == 0)
    {
        cout << "��û����ϵ��Ŷ��" << endl;
    }
    else
    {
        for (int i = 0; i < dsb->peosize; i++)
        {
            cout << "���� " << dsb->peopleArr[i].Mname << "\t"
                << "�Ա� " << (dsb->peopleArr[i].Man == 1 ? "��" : "Ů") << "\t"
                << "���� " << dsb->peopleArr[i].Mage << "\t"
                << "�绰 " << dsb->peopleArr[i].Mphone << "\t"
                << "סַ " << dsb->peopleArr[i].Maddr << endl;
        }
    }
    cout << "�����⽨����";
    cin.get();
    cin.get();
    system("cls"); // ����
}



// �����ϵ���Ƿ���ڣ�������ڣ�������ϵ����ͨѶ¼�е�λ�ã�������return-1
// ����1��ͨѶ¼�Ƿ�����  ����2���Ա�����
int isExist(addbooks* dsb, string name)
{
    for (int i = 0; i < dsb->peosize; i++)
    {
        //�ҵ��û����������
        if (dsb->peopleArr[i].Mname == name)
        {
            return i;
        }
    }

    return -1;  //û�ҵ�
}


//ɾ��ָ����ϵ��
void delpeople(addbooks* dsb)
{
    cout << "����Ҫɾ����ϵ��" << endl; 
    string name;
    cin >> name;

    //���ս��  res == -1 û��    res == �ҵ���
    int res = isExist(dsb, name);
    if(res != -1)   // ���res������-1
    {
       //�ҵ���Ҫ����ɾ����
        for (int i = res; i < dsb->peosize; i++)
        {
            //����ǰ��
            dsb->peopleArr[i] = dsb->peopleArr[i + 1];
            
        }
        dsb->peosize--; //��������
        cout << "ɾ���ɹ�" << endl;
    }
    else
    {
        cout << "���޴���" << endl;
       
    }

    system("pause");
    system("cls");
}

//������ϵ��
void chazhao(addbooks* dsb)
{
    cout << "������Ҫ���ҵ���ϵ��" << endl;
    string name;
    cin >> name;

    int rest = isExist(dsb, name);
    if (rest != -1)  // ���rest������-1
    {
        /*���и��򵥵�
   cout << "���� " << dsb->peopleArr[rest].Mname << "\t"
        << "�Ա� " << (dsb->peopleArr[rest].Man == 1 ? "��" : "Ů") << "\t"
        << "���� " << dsb->peopleArr[rest].Mage << "\t"
         << "�绰 " << dsb->peopleArr[rest].Mphone << "\t"
        << "סַ " << dsb->peopleArr[rest].Maddr << endl; */
       
        cout << "�ҵ���" << endl;
            for (int j = 0; j < dsb->peosize; j++)
            {
                //�ҵ��û����������
                if (dsb->peopleArr[j].Mname == name)
                {
                    cout << "���� " << dsb->peopleArr[j].Mname << "\t"
                        << "�Ա� " << (dsb->peopleArr[j].Man == 1 ? "��" : "Ů") << "\t"
                        << "���� " << dsb->peopleArr[j].Mage << "\t"
                        << "�绰 " << dsb->peopleArr[j].Mphone << "\t"
                        << "סַ " << dsb->peopleArr[j].Maddr << endl;
                    system("pause");
                    
                }
            }
            system("cls");
    }
    else
    {
        cout << "���޴���" << endl;
    }
}

//�޸���ϵ��
void xiugai(addbooks* dsb)
{
    cout << "������Ҫ�޸���ϵ�˵�����" << endl;
        string name;
    cin >> name;

    int rs = isExist(dsb,name);

    if (rs != -1)  // ���rs������-1
    {
        // �Ա�
        while (true)
        {
            int a = 0; // �Ա�ѡ��
            cout << "�������Ա� 1���� 2��Ů" << endl;
            cin >> a;

            // ����1h��2,���򲻻��˳�ѭ��
            if (a == 1 || a == 2)
            {
                dsb->peopleArr[rs].Man = a;
                break;
            }
            cout << "***** ���� *******" << endl;
            cout << "   ������1��2" << endl;
            cout << "*****************" << endl;
        }

        // ����
        while (true)
        {
            int age = 0;
            cout << "����������" << endl;
            cin >> age;
            if (age > 200)
            {
                cout << "�������" << age << "�갡����" << endl;
            }

            else if (age < 1)
            {
                cout << "��û�����صȴ���ټ�¼��������" << endl;
            }
            else
            {
                dsb->peopleArr[rs].Mage = age; // ��ȷ��

                break;
            }
        }

        // �绰
        cout << "��������ϵ�绰��" << endl;
        string phone;
        cin >> phone;
        dsb->peopleArr[rs].Mphone = phone;

        // ��ַ
        cout << "������סַ" << endl;
        string Msdarr;
        cin >> Msdarr;
        dsb->peopleArr[rs].Maddr = Msdarr;

    }
    else
    {
        cout << "���޴���" << endl;
    }
    system("pause");
    system("cls");
}

void cleanpeople(addbooks* dsb)
{
    dsb->peosize = 0;  //�����
    cout << "ͨѶ¼������" << endl;
    system("pause");
    system("cls");
}

int main(void)
{

    // ����ͨѶ¼�ṹ�����
    addbooks dsb;

    // ��ʼ��ͨѶ¼�е�ǰ����Ա����
    dsb.peosize = 0;

    int in = 0; // �����û�����ı���

    while (true)
    {
        // �˵��ĵ���
        showMenu();
        cin >> in; // �û�����

        switch (in)
        {
        case 1:              // �����ϵ��
            arrpeople(&dsb); // ���õ�ַ���ݣ���������ʵ��
            break;

        case 2: // ��ʾ��ϵ��
            printPeople(&dsb);
            break;

        case 3: // ɾ����ϵ��
            delpeople(&dsb);
            break;

        /*{      ���Խ׶�
            cout << "����Ҫɾ����ϵ��" << endl;
            string name;
            cin >> name;

            if (isExist(&dsb, name) == -1)
            {
                cout << "û�ҵ�" << endl;
            }
            else
            {
                cout << "�ҵ���" << endl;
            }
        }*/
            

        case 4: // ������ϵ��
            chazhao(&dsb);
            break;

        case 5: // �޸���ϵ��
            xiugai(&dsb);
            break;

        case 6: // �����ϵ��
            cleanpeople(&dsb);
            break;

        case 0: // �˳�ͨѶ¼
            cout << "good bye!" << endl;

            cin.get(); // �����⽨�˳�
            cout << "�������⽨����";
            cin.get(); // ��Ϊ������0Ҳ������������ǰ������ϵ���дһ��

            return 0; // ���������˳�
            break;

        default:
            cout<<"������0~6����"<<endl;
            system("cls");
            break;
        }
    }
}
