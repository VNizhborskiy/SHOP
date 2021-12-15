#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <vector>
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <fstream>
#include "work_database.h"
using namespace std;
int choice_str; int wage_F_workers; int c_for_sls; char countin;
int counts; // �������
int q_purchase = 0;//���������� ��� ������ ������� void buy_sell()
void start(); void blink(); void data_reg(); void t_chief(); void supply(); void data_read(); //�������� ������� ��� ������ � ����
void buy_sell(); void bookeep(); void salesman(); void customers(); void show_st_shop();
int c; // ���� ��� ��� ������ ������� buy_sell()

// 1-� ����� �������:

class Human
{
public:
    vector <string> name_h = {"������","����","�����","������","����","�����","������","����","�����","����","����"};

}; Human Human;

class Buyer : public Human
{
public:
    vector <int> qua_purchase;
}; Buyer Buyer;

// 2-� ����� �������:

class Seller
{
public:
    vector <string> name_s = {"��������", "��������", "������"};
    vector <int> salary; // �������� �������� �� �-���� ��������� ������
    vector <int> salary_profit; // �������� ������� �� ������
    vector <int> salary_valuta; // ��������

}; Seller Seller;

class Chief : public Seller
{
public:
    string num_reg = "+380";
    long long phone_num = 123456789;
    string email = "���@gmail.com";
    int money;
    int money_day;
}; Chief Chief;

// ����� �������:

class Item
{
public:
    int quantity;
    int quantity_day;//����� ���������� ������� �� ��������� ��������
    int qua_sell_day; // ����� ���������� ������� �������
    int prc_supply;
    vector <int> prc_itsupply; // ���� �������  �� 1 ��.
    vector <int> price = {5,6,4,10,10,5,
                                    5,10,30,10,8,9,
                                    15,7,6,20,14,
                                    8}; // ���� ������� �� 1 ��.
    char valuta = '$';
    string grivna = "���";
    vector <int> qua_item;
    vector <int> qua_item_sell;
    vector <string> name_of_item = {"����������","�����������","���������","�������","������������","��������",
                                    "������������","�����","�������","��������� ����������","���������","��������",
                                    "����������","���������","���������� ���������","��������������","��������",
                                    "���������"};
    void supply()
    {
        int i_cc = 1; //������� ��� ������ �������
        prc_itsupply.resize(name_of_item.size());
        cout << "���� �� ����� (�������/���� �� 1 ��.): \n";
        for(unsigned int i_0 = 0; i_0 < prc_itsupply.size(); i_0++)
        {
            prc_itsupply[i_0] = rand()% 3 + 1;
            cout << i_cc << ". " << name_of_item[i_0] << ": " << prc_itsupply[i_0] << valuta << endl;
            i_cc++;
        }
        qua_item.resize(name_of_item.size());//���������� ������� �������� ������� qua_item ��������� ��������
        for(unsigned int i_0 = 0; i_0 < qua_item.size(); i_0++)
        {
            qua_item.at(i_0) += rand()%200 + 15;//��������� �������� �� 15 �� 214
        }

        for(unsigned int i_0 = 0; i_0 < qua_item.size(); i_0++)//������� ������ ���������� �� ������
        {
            quantity += qua_item.at(i_0);
        }
        quantity_day = quantity;
        c_for_sls++;
    }
}; Item Item;

// ������� ��� ������ ��������:

void hire()
{
    cout << "�� ������ ������ ������ ��������� ��� ������� �������?\n"
            "1. ������\n"
            "2. �������\n";
    cout << "��� �����: \n";
    cin >> choice_str;
    switch(choice_str)
    {
        case 1: {cout << "������� � ���� ������ ��� ������ ���������: \n";
                string nwwork;
                cout << "���: ";
                cin >> nwwork;
                cout << "�� ������� ������ ������ ���������.\n";
                Seller.name_s.push_back(nwwork);
                cout << "������� +, ��� �� ����������.";
                cin >> countin;
                switch(countin)
                {
                    case 1: start();
                            break;
                    default:start();
                            break;
                }
                }
                break;
        case 2: {
                if(Seller.name_s.size() == 1)
                {
                    cout << "������ � �������� ������� 1 ��������, ������� �����.\n";
                    t_chief();
                }
                cout << "������ ��������� �� ������ �������?\n";
                cout << "������ ���������: \n";
                int i_f = 0;
                for(unsigned int i_0 = 0; i_0 < Seller.name_s.size(); i_0++)
                {
                    cout << i_f << ". " << "���: " << Seller.name_s.at(i_0) << endl;
                    i_f++;
                }
                cout << "���� �� ��� �� ������ �������? �������� �����: \n"; int num_fr;
                cin >> num_fr;
                while(num_fr > Seller.name_s.size()-1)
                {
                    cout << "�������� ����� �� ����������������.\n";
                    cin >> num_fr;
                }
                cout << "�� ������� ��������� " << Seller.name_s[num_fr] << ".";
                Seller.name_s.erase(Seller.name_s.begin() + num_fr);
                cout << "������� +, ��� �� ����������.";
                cin >> countin;
                switch(countin)
                {
                    case 1: start();
                            break;
                    default:start();
                            break;
                }
                }
                break;
        default:system("cls");
                cout << "������. �������� 1 ��� 2. \n";
                start();
    }
}

void show_st_shop()
{
    cout << "1. ������ ������� � �������.\n"
            "2. ������� �������.\n"
            "3. ����� � ����.\n";
    cout << "��� �����: \n";
    cin >> choice_str;
    switch(choice_str)
    {
         case 1:{
                if(c_for_sls < 1)
                {
                    cout << "����� ��� �� ��������.\n";
                    start();
                }
                cout << "����� ���������� �� ������: " << Item.quantity_day << endl;
                cout << "������ � ������ (��������/���������� �� ������): " << endl;
                int i_3 = 1;
                for(unsigned int i_0 = 0; i_0 < Item.name_of_item.size(); i_0++)
                {
                    cout << i_3 << ".  " << Item.name_of_item.at(i_0) << ": <--- " << Item.qua_item.at(i_0) << endl;
                    i_3++;
                }
                cout << "������� +, ��� �� ����������.";
                cin >> countin;
                switch(countin)
                {
                    case 1: start();
                            break;
                    default:start();
                            break;
                }
                }
                break;
         case 2:{if(counts < 1)
                {
                    cout << "�������� ������� ��� �� ��������.\n";
                    start();
                }
                for(unsigned int i_0 = 0; i_0 < Item.name_of_item.size(); i_0++)
                {
                    Item.qua_sell_day += Item.qua_item_sell.at(i_0);
                }
                cout << "������� �������: " << Item.qua_sell_day << endl;
                cout << "������ � ������ (��������/�������): " << endl;
                int i_3 = 1;
                for(unsigned int i_0 = 0; i_0 < Item.name_of_item.size(); i_0++)
                {
                    cout << i_3 << ".  " << Item.name_of_item.at(i_0) << ": ---> " << Item.qua_item_sell.at(i_0) << endl;
                    i_3++;
                }
                                cout << "������� +, ��� �� ����������.";
                cin >> countin;
                switch(countin)
                {
                    case 1: start();
                            break;
                    default:start();
                            break;
                }
                }
                break;
        case 3: system("cls");
                start();
                break;
        default:{system("cls");
                cout << "������. �������� 1 ��� 2. \n";
                start();}


    }
}

void customers()
{
    system("cls");
    cout << "������ �����������: \n";
    int i_2 = 1;
    for(unsigned int i_0 = 0; i_0 < Buyer.name_h.size(); i_0++)
    {
        cout << i_2 << ". " << "���: " << Buyer.name_h.at(i_0) << " / ���������� ��������� ��������: " <<  Buyer.qua_purchase.at(i_0) << endl;
        i_2++;
    }
    cout << "������� +, ��� �� ����������.";
    cin >> countin;
    switch(countin)
    {
        case 1: start();
        break;
        default:start();
        break;
    }
}

void salesman()
{
    Seller.salary.resize(Seller.name_s.size());
    Seller.salary_profit.resize(Seller.name_s.size());
    Seller.salary_valuta.resize(Seller.name_s.size());
    system("cls");
    cout << "���������� ���������� � ���������: \n"
            "1. ���������� �������� � ������ ���������. \n"
            "2. ���������� ���������� ���������. \n"
            "3. ��������� �������� ����������. \n";
    cout << "��� �����: \n";
    cin >> choice_str;
    switch(choice_str)
    {
        case 1: {
                    cout << "������ ���������: \n";
                    int i_2 = 1;
                    for(unsigned int i_0 = 0; i_0 < Seller.name_s.size(); i_0++)
                    {
                        cout << i_2 << ". " << "���: " << Seller.name_s.at(i_0) << " / ������� ������: " << Seller.salary.at(i_0);
                        cout << " / ��������: " << Seller.salary_valuta.at(i_0) << Item.grivna << endl;
                        i_2++;
                    }
                    cout << "������� +, ��� �� ����������.";
                    cin >> countin;
                    switch(countin)
                    {
                        case 1: start();
                                break;
                        default:start();
                                break;
                    }
                }
                break;
        case 2: {
                    system("cls");
                    if(counts < 1)
                    {
                        cout << "�������� ������� ��� �� ��������.\n";
                        start();
                    }
                    cout << "���������� ���������: \n";
                    int max_p;
                    int max_i;
                    string max_s;
                    max_p = Seller.salary_profit[0];
                    max_s = Seller.name_s[0];
                    max_i = Seller.salary[0];
                    for(unsigned int i = 0; i < Seller.salary_profit.size(); i++)
                    {
                        if(Seller.salary_profit[i] > max_p)
                        {
                            max_p = Seller.salary_profit[i];
                            max_s = Seller.name_s[i];
                            max_i = Seller.salary[i];
                        }
                    }
                    int premia;
                    cout << "���� ��� ������ ��������: " << max_s << "." << "\n����� ������� �������: " << max_p << Item.valuta << ", ������: " << max_i;
                    cout << "\n��������� ��� ������: \n"
                            "1.��\n"
                            "2.���\n";
                    cin >> choice_str;
                    switch(choice_str)
                    {
                        case 1:  if(Chief.money_day < 100)
                                 {
                                    cout << "������ � ����������� ������� ���� �����. ���������� �����.\n";
                                    start();
                                 }
                                 cout << "����� ������ �� ������ ��������� " << max_s << "?(������ � $)\n";
                                 cin >> premia;
                                 while(premia > Chief.money_day)
                                 {
                                     cout << "�� ������� �����. ���������� ������� �����:\n";
                                     cin >> premia;
                                 }
                                 cout << "�� ��������� ������ �������� "<< max_s <<" � ������� "<< premia << Item.valuta <<  "!\n";
                                 Chief.money_day -= premia;
                                 cout << "������� �����: " << Chief.money_day << endl;
                                 break;
                        case 2:  cout << "� ����. ������� ��������...\n";
                                 start();
                                 break;
                    }
                    start();
                }
                break;
        case 3: {
                     if(Chief.money_day < 1000)
                     {
                        cout << "������ � ����������� ������� ���� �����. ���������� �����.\n";
                        start();
                     }
                     system("cls");
                     cout << "������� 1, ��� �� ��������� �������� ����������.\n"
                             "������� 2, ��� �� ���������� ������� ��������.\n";
                     cout << "��� �����: \n";
                     cin >> choice_str;
                     switch(choice_str)
                     {
                         case 1: for(unsigned int i_ss = 0; i_ss < Seller.name_s.size(); i_ss++)
                                 {
                                     Chief.money_day -= Seller.salary_valuta.at(i_ss)/26; //������� ������ � ������ (���� 26)
                                 }
                                 cout << "�� ������� ��������� �������� ���������� !";
                                 cout << "������� ������: " << Chief.money_day << Item.valuta << endl;
                                 start();
                                 break;
                         case 2: cout << "��������� �� ���� ���������! ������� ����������!";
                                 start();
                                 break;
                         default:system("cls");
                                 cout << "������. �������� 1 ��� 2. \n";
                                 start();

                     }
                }
                break;
        default:{
                    system("cls");
                    cout << "������. �������� 1 ��� 2. \n";
                    start();
                }
                break;
    }
}

void bookeep()
{
    cout << "��� ��� ����������?\n"
            "1. ���������� ������� �� ����.\n";
    cout << "��� �����: \n";
    cin >> choice_str;
    switch(choice_str)
    {
        case 1: if(Chief.money_day  < 0)
                {
                    cout << "����-��� �� � ������: "  << Chief.money_day << Item.valuta << endl;
                    start();
                }
                cout << "������� �� ����: " << Chief.money_day << " " << Item.valuta << endl;
                start();
                break;
        default:system("cls");
                cout << "������. �������� 1 ��� 2. \n";
                start();
    }
    start();
}

void start()
{
    system("COLOR F1");
    cout << "                                 ������� ����������� C++             \n";
    cout << "                           _____________        _____________        \n";
    cout << "                           |           |  ����  |           |        \n"
            "                        ---|           |---||---|           |---     \n"
            "                           |___________|   ||   |___________|        \n"
            "                   ========================||========================\n"
            "                   ========================||========================\n"
            "                   ~~~~~~~~~I=U/R~~~~~~~~~ || ~~~~~~~~~I=U/R~~~~~~~~~\n\n";
    cout << "                   ������� 1, ��� �� ��������������� ������� �������/�������.\n";
    cout << "                   ������� 2, ��� �� ������� ������ ��������� ��������.\n";
    cout << "                   ������� 3, ��� �� ��������/���������� �������� ����.\n";
    cout << "                   ������� 4, ��� �� ������� ��������� ��������.\n";
    cout << "                   ������� 5, ��� �� ������� ���������.\n";
    cout << "��� �����: \n";
    cin >> choice_str;
    switch(choice_str)
    {
        case  1:system("cls");
                buy_sell();
                break;
        case 2: system("cls");
                t_chief();
                break;
        case  3:system("cls");
                cout << "1. �������� ���� ����� � �������� ����. \n";
                cout << "2. ��������� ���� ����� � ��������� �����. \n"
                        "3. ����� � ����. \n";
                cout << "��� �����: \n";
                cin >> choice_str;
                switch(choice_str)
                {
                    case 1: if(Item.quantity_day < 1)
                            {
                                cout << "������� �������� �������� ������, ����� ����������� ������.\n";
                                start();
                            }
                            data_reg();
                            break;
                    case 2: data_read();
                            break;
                    case 3: system("cls");
                            start();
                            break;
                    default:system("cls");
                            cout << "������. �������� 1 ��� 2. \n";
                            start();
                }
                break;
        case  4:{system("cls");
                show_st_shop();}
                break;
        case  5:{system("cls");
                cout << "\n\n��������� ������� �����������. ������� Enter, ��� �� ����� �� ���������.\n";
                exit(0);}
                break;
        default:{system("cls");
                cout << "������. �������� 1,2,3,4 ��� 5. \n";
                start();}
    }
}

void blink()
{
    for(int i_0 = 0; i_0 < 3; i_0++)
    {
        for(int i_0 = 0; i_0 < 41; i_0++)
        {
            cout << "                  "; // ����� � �������
        }
        cout << " ��� ������������ ������� ����������� C++      \n";
        for(int i_0 = 0; i_0 < 10; i_0++)
        {
            cout << endl; // ����� ������
        }
        system("COLOR F1");
        system("COLOR E4");
        system("COLOR F1");
        system("COLOR E4");
        Sleep(900);
        system("cls");
        Sleep(900);
    }
}

void t_chief()
{

    cout << "�������� ������� ���������: \n1. �������� �������� ������.\n"
            "2. ���������� � ���������� ��������. \n"
            "3. ���������� � �����������. \n"
            "4. ������� �����������.\n"
            "5. ������/������� ���������.\n"
            "6. ����� � ����.\n";
    cout << "��� �����: \n";
    cin >> choice_str;
    switch(choice_str)
    {
        case 1: if(Item.quantity_day > 300)
                {
                    cout << "� �������� ������ ����������� ���������� ������. �� ������� ��� ������ ��� ��������?\n"
                            "1. ��\n"
                            "2. ���\n";
                    cout << "��� �����: \n";
                    cin >> choice_str;
                    switch(choice_str)
                    {
                        case 1: cout << "������, �������� ��� �������.\n";
                                break;
                        case 2: start();
                                break;
                        default:system("cls");
                                cout << "������. �������� 1 ��� 2. \n";
                                start();
                    }
                }
                Item.supply();
                cout << "�� ������� �������� ����� !\n";
                cout << "���������� ������������� ������: " << Item.quantity_day << endl;
                Item.quantity = 0; // ��������� �������� �������
                for(unsigned int i_0 = 0; i_0 < Item.prc_itsupply.size(); i_0++)
                {
                    Item.prc_supply += Item.qua_item[i_0]*Item.prc_itsupply[i_0];//��������� ���������� ������� �������� �� ����
                }
                cout << "������ ����������� �� �������: " << Item.prc_supply << Item.valuta << endl;
                Chief.money_day -= Item.prc_supply;
                cout << "������� +, ��� �� ����������.";
                cin >> countin;
                switch(countin)
                {
                    case 1: start();
                            break;
                    default:start();
                            break;
                }
                break;
        case 2: salesman();
                break;
        case 3: if(q_purchase == 0)
                {
                    cout << "� �������� ��� ������ �� ���� �������. \n";
                    start();
                }
                customers();
                break;
        case 4: system("cls");
                bookeep();
                break;
        case 5: system("cls");
                hire();
                break;
        case 6: system("cls");
                start();
                break;
        default:system("cls");
                cout << "������. �������� 1,2,3,4,5 ��� 6. \n";
                start();
    }
}

void buy_sell()
{
    Seller.salary.resize(Seller.name_s.size());
    Seller.salary_profit.resize(Seller.name_s.size());
    Seller.salary_valuta.resize(Seller.name_s.size());
    Item.qua_item_sell.resize(Item.name_of_item.size());
    Item.qua_item.resize(Item.name_of_item.size());
    while(c != 1)
    {
        cout << "����� ��������� �������� �������� ����� ����� �������� � ��������\n";
        cout << "�� ������ ��������� ������ (� �������):\n";
        cin >> wage_F_workers;
        while(wage_F_workers > 9 || wage_F_workers < 1)
        {
            cout << "�������� �������� � ��������� �� 1 �� 9.\n";
            cin >> wage_F_workers;
        }
        cout << "������ �������� �� ������ ��������� ������ ����� �������� " << wage_F_workers << " " << Item.grivna << "." << endl;
        c++;
    }
    if(Item.quantity_day < 300 && Item.quantity_day > 1)
    {
        cout << "������ �� ������ ������ 300 ! ����� �������� �������� ������!\n"
                "1. �������� �������� ������.\n"
                "2. ����������.\n";
        cin >> choice_str;
        switch(choice_str)
        {
            case 1: system("cls");
                    t_chief();
                    break;
            case 2: start();
                    break;
            default:cout << "�������� 1 ��� 2.\n";
                    cin >> choice_str;
                    start();
        }
    }
    cout << "� ����� ��������� �� ������ ��������������� ������ ��������?\n"
            "1. ������� �����.\n"
            "2. ���������� �����.\n"
            "3. ����� � ����.\n";
    cin >> choice_str;
    switch(choice_str)
    {
        case 1: {system("COLOR E9");
                system("cls");
                if(Item.quantity_day < 1)
                {
                    cout << "�� ������ �����, ������� �� ��������. ��� ����� �������� �������� ������.\n\n";
                    t_chief();
                }
                int choice_cnt;
                int i_s;//������� ��� ���������
                int i_b;//������� ��� �����������
                int i_i;//������� ��� ������
                int ch_q;//������ ����������
                do
                {
                     i_s = rand()%Seller.name_s.size();
                     i_b = rand()%Buyer.name_h.size();
                     i_i = rand()%Item.name_of_item.size();//����� ������ �� ����� �������
                     ch_q = rand()%100 + 1;
                     cout << " (��������)" << "   - ������������. ���� ����� " << Seller.name_s[i_s] << ".\n "
                     "               ��� � ���� ��� ������?\n";
                     Sleep(3000);
                     cout << " (����������)" << " - ������������. ���� ����� " << Buyer.name_h[i_b] << ".\n "
                     "               ��� ����� " << Item.name_of_item[i_i] << ".\n";
                     Sleep(3000);
                     cout << " (��������)" << "   - � ��� ���� � ������� " << Item.qua_item[i_i] << ".\n"
                     "                �� ���� " << Item.price[i_i] << Item.valuta << " �� �����" << ".\n ";
                     Sleep(3000);
                     cout << "               ������� ��� �����?\n";
                     Sleep(3000);
                     cout << " (����������)" << " - ��� ���� " << ch_q << ".\n";
                     Sleep(3000);
                     if(ch_q > Item.qua_item[i_i])
                     {
                         cout << " (��������)" <<"   - ��������, � ��� ���� ������ ����������.\n";
                         Sleep(3000);
                         cout << " (����������)" << " - ����� � ������ �������. �� ��������. \n\n";
                         Sleep(3000);
                         cout << "1. ����������.\n2. ����� �� ��������\n";
                         cin >> choice_cnt;
                         switch(choice_cnt)
                         {
                            case 1: system("cls");
                                    buy_sell();
                                    break;
                            case 2: system("cls");
                                    start();
                                    break;
                            default:system("cls");
                                    cout << "������. �������� 1 ��� 2. \n";
                                    start();
                         }
                     }
                     Chief.money = Item.price[i_i] * ch_q;
                     Buyer.qua_purchase.resize(Buyer.name_h.size());
                     if(ch_q > 50)//��� ������� �����������
                     {
                         system("COLOR E4");
                         cout << " (��������)" <<"   - ��� ������� ����������� � ��� ������ 10%!\n"
                         "                ������ " << Chief.money << Item.valuta << " ��� ����� ��������� ����� ���� ";
                         Chief.money -= (Chief.money*10)/100;
                         cout << Chief.money << Item.valuta << "\n";

                         Sleep(3000);
                         system("COLOR E9");
                     }

                     else if(Buyer.qua_purchase[i_b] > 40)// ��� ���������� �����������
                     {
                         system("COLOR E4");
                         cout << " (��������)" << "   - �� ��� ���������� ����������! " << "\n ";
                         cout << "               ��� ������ 15% !\n";
                         cout << "                ������ " << Chief.money << Item.valuta << " ��� ����� ��������� ����� ���� ";
                         Chief.money -= (Chief.money*15)/100;
                         cout << Chief.money << Item.valuta << "\n";
                         Sleep(3000);
                         system("COLOR E9");
                     }
                     Chief.money_day += Chief.money;
                     cout << " (��������)" << "   - ���� ������� ���������! � ��� " << Chief.money << Item.valuta << "\n";
                     Sleep(3000);
                     cout << " (����������)" << " - ���, ��� ������. �������, �� ��������!\n";
                     Sleep(3000);
                     cout << " (��������)" << "   - ������� �� �������, ��������� ���!\n\n";
                     Sleep(3000);
                     Item.qua_item_sell[i_i] += ch_q ; //�_���� ��������� �������
                     Item.qua_item[i_i] -= ch_q;
                     Item.quantity_day -= ch_q;
                     q_purchase++;
                     Buyer.qua_purchase[i_b] = q_purchase; //���������� ����������� � ����������
                     Seller.salary[i_s] += ch_q; //�������� ��������
                     Seller.salary_profit[i_s] += Chief.money;
                     counts++; //��� ������� salesman() case 2
                     Seller.salary_valuta.at(i_s) = wage_F_workers * Seller.salary.at(i_s);
                     cout << "1. ����������.\n2. ����� �� ��������\n";
                     cin >> choice_cnt;
                     switch(choice_cnt)
                     {
                         case 1: system("cls");
                                 buy_sell();
                                 break;
                         case 2: system("cls");
                                 start();
                                 break;
                         default:system("cls");
                                 cout << "������. �������� 1 ��� 2. \n";
                                 start();
                     }
                 }
                while(choice_cnt != 2);
                }
                break;
        case 2: {system("COLOR E9");
                system("cls");
                if(Item.quantity_day < 1)
                {
                    cout << "�� ������ �����, ������� �� ��������. ��� ����� �������� �������� ������.\n\n";
                    t_chief();
                }
                int i_0 = 0;
                int choice_cnt;
                while(i_0 < 21)
                {
                     int i_s = rand()%Seller.name_s.size();
                     int i_b = rand()%Buyer.name_h.size();
                     int i_i = rand()%Item.name_of_item.size();
                     int ch_q = rand()%100 + 1;
                     cout << " (��������)" << "   - ������������. ���� ����� " << Seller.name_s[i_s] << ".\n "
                     "               ��� � ���� ��� ������?\n";
                     //Sleep(5000);
                     cout << " (����������)" << " - ������������. ���� ����� " << Buyer.name_h[i_b] << ".\n "
                     "               ��� ����� " << Item.name_of_item[i_i] << ".\n";
                     //Sleep(5000);
                     cout << " (��������)" << "   - � ��� ���� � ������� " << Item.qua_item[i_i] << ".\n"
                     "                �� ���� " << Item.price[i_i] << Item.valuta << " �� �����" << ".\n "
                     "               ������� ��� �����?\n";
                     //Sleep(5000);
                     cout << " (����������)" << " - ��� ���� " << ch_q << ".\n";
                     //Sleep(5000);
                     if(ch_q > Item.qua_item[i_i])
                     {
                         cout << " (��������)" <<"   - ��������, � ��� ���� ������ ����������.\n";
                         //Sleep(5000);
                         cout << " (����������)" << " - ����� � ������ �������. ����������. \n\n";
                         //Sleep(5000);
                         i_0++;
                         system("cls");
                         continue;
                     }
                     //Sleep(5000);
                     Chief.money = Item.price[i_i] * ch_q;
                     Buyer.qua_purchase.resize(Buyer.name_h.size());
                     if(i_0 > 10 && Item.qua_item[i_i] > 100)//�������������� �� ��������
                     {
                         system("COLOR E4");
                         cout << " (��������)" << "   - ���� ����� ������ ��������������..������ �� ���� 50% !! " << "\n ";
                         cout << "               ��� ������ 50% !\n";
                         cout << "                ������ " << Chief.money << Item.valuta << " ��� ����� ��������� ����� ���� ";
                         Chief.money -= (Chief.money*50)/100;
                         cout << Chief.money << Item.valuta << "\n";


                     }
                     else if(ch_q > 50)//��� ������� �����������
                     {
                         system("COLOR E4");
                         cout << " (��������)" <<"   - ��� ������� ����������� � ��� ������ 10%!\n"
                         "                ������ " << Chief.money << Item.valuta << " ��� ����� ��������� ����� ���� ";
                         Chief.money -= (Chief.money*10)/100;
                         cout << Chief.money << Item.valuta << "\n";

                     }

                     else if(Buyer.qua_purchase[i_b] > 40)//��� ���������� �����������
                     {
                         system("COLOR E4");
                         cout << " (��������)" << "   - �� ��� ���������� ����������! " << "\n ";
                         cout << "               ��� ������ 15% !\n";
                         cout << "                ������ " << Chief.money << Item.valuta << " ��� ����� ��������� ����� ���� ";
                         Chief.money -= (Chief.money*15)/100;
                         cout << Chief.money << Item.valuta << "\n";



                     }
                     Chief.money_day += Chief.money;
                     cout << " (��������)" << "   - ���� ������� ���������! � ��� " << Chief.money << Item.valuta << "\n";
                     //Sleep(5000);
                     cout << " (����������)" << " - ���, ��� ������. �������, ����������!\n";
                     //Sleep(5000);
                     cout << " (��������)" << "   - ������� �� �������, ��������� ���!\n\n";
                     Sleep(1500);
                     Item.qua_item_sell[i_i] += ch_q ; //�_���� ��������� �������
                     Item.qua_item[i_i] -= ch_q;
                     Item.quantity_day -= ch_q;
                     q_purchase++;
                     Buyer.qua_purchase[i_b] = q_purchase; //���������� ����������� � ����������
                     Seller.salary[i_s] += ch_q; //����������� �������� ��������
                     Seller.salary_profit[i_s] += Chief.money;
                     counts++;//��� ������� salesman() case 2
                     Seller.salary_valuta.at(i_s) = wage_F_workers * Seller.salary.at(i_s);
                     system("cls");
                     i_0++;
                     continue;
                 }
                 cout << "��������������� 20 �������� �������/�������.\n";
                 cout << "1. ����������.\n2. ����� �� ��������\n";
                 cin >> choice_cnt;
                 switch(choice_cnt)
                 {
                    case 1: system("cls");
                            buy_sell();
                            break;
                    case 2: system("cls");
                            start();
                            break;
                    default:system("cls");
                            cout << "������. �������� 1 ��� 2. \n";
                            start();
                 }
                 }
                 break;
        case 3:{start();}
                break;
        default:{system("cls");
                cout << "������. �������� 1,2 ��� 3. \n";
                start();}
                break;
    }

}

void data_reg()
{
    work_database working;
    int i_1 = 1; int i_2 = 1; int i_3 = 1;// ��������

    // ������ ���������� � ����������:

    ofstream work;
    work.open("test.txt",ios_base::binary | ios_base::app);
    work << "====================================\n";
    work << "������ � ���������: " << endl;
    for(unsigned int i_0 = 0; i_0 < Seller.name_s.size(); i_0++)
    {
         work << i_2 << ". " << Seller.name_s.at(i_0) << endl;
        i_2++;
    }
    work << "====================================\n";
    work << "���������� ������ ������������ ��������: " << endl;
    Chief.name_s = {"������ ���� ������"};
    work << "��� ���������: " <<  Chief.name_s[0] << endl;
    work << "����� ��������:" << Chief.num_reg  << Chief.phone_num << endl;
    work << "Email: " << Chief.email << endl;
    work << "====================================\n";
    work.close();
    working.filled("output.WorkersDB");

    //������ ���������� � �����������:

    work.open("test.txt",ios_base::binary | ios_base::app);
    work << "====================================\n";
    work << "������ � �����������: " << endl;
    for(unsigned int i_0 = 0; i_0 < Buyer.name_h.size(); i_0++)
    {
        work << i_1 << ". " << Buyer.name_h.at(i_0) << endl;
        i_1++;
    }
    work << "====================================\n";
    work.close();
    working.filled("output.SalesmansDB");

    //������ ���������� � ������:

    work.open("test.txt",ios_base::binary | ios_base::app);
    work << "====================================\n";
    work << "������ � ������ (��������/���������� �� ������): \n";
    for(unsigned int i_0 = 0; i_0 < Item.name_of_item.size(); i_0++)
    {
        work << i_3 << ".  " << Item.name_of_item.at(i_0) << ": ---> " << Item.qua_item.at(i_0) << "\n";
        i_3++;
    }
    work << "����� ������:" << " ---> " << Item.quantity_day << "\n";
    work << "====================================\n";
    work.close();
    working.filled("output.GoodsDB");

    cout << "�� ������� �������� ������ � �������� ���� !\n\n"; counts++;//��� �������
    start();
}

void data_read()
{
    if(counts < 1)
    {
        cout << "������� �������� ������ � �������� ����.\n";
        start();
    }
    cout << "\n����� �������� ���� �� ������ ���������?\n"
            "1. ���������� � ���������� ��������.\n"
            "2. ���������� � �����������.\n"
            "3. ���������� � ������\n";
    cout << "��� �����: \n";
    cin >> choice_str;
    switch(choice_str)
    {
        case 1: {ifstream files;
                files.open("output.WorkersDB", ios_base::binary);
                string line;
                string copys;
                while (getline(files, line))
                {
                    copys += line;
                    copys.push_back('\n');
                }
                files.close();
                cout << copys;
                cout << "������� +, ��� �� ����������.";
                cin >> countin;
                switch(countin)
                {
                    case 1: start();
                            break;
                    default:start();
                            break;
                }
                }
                break;
        case 2: {ifstream files_b;
                files_b.open("output.SalesmansDB", ios_base::binary);
                string line_b;
                string copys_b;
                while (getline(files_b, line_b))
                {
                    copys_b += line_b;
                    copys_b.push_back('\n');
                }
                files_b.close();
                cout << copys_b;
                cout << "������� +, ��� �� ����������.";
                cin >> countin;
                switch(countin)
                {
                    case 1: start();
                            break;
                    default:start();
                            break;
                }
                }
                break;
        case 3: {ifstream files_i;
                files_i.open("output.GoodsDB", ios_base::binary);
                string line_i;
                string copys_i;
                while (getline(files_i, line_i))
                {
                    copys_i += line_i;
                    copys_i.push_back('\n');
                }
                files_i.close();
                cout << copys_i;
                cout << "������� +, ��� �� ����������.";
                cin >> countin;
                switch(countin)
                {
                    case 1: start();
                            break;
                    default:start();
                            break;
                }
                }
                break;
        default:system("cls");
                cout << "������. �������� 1,2 ��� 3. \n";
                start();
    }
}

class Shop
{
    public:
    void blink()
    {
        for(int i_0 = 0; i_0 < 3; i_0++)
        {
            for(int i_0 = 0; i_0 < 41; i_0++)
            {
                cout << "                  "; // ����� � �������
            }
            cout << " ��� ������������ ������� ����������� C++      \n";
            for(int i_0 = 0; i_0 < 10; i_0++)
            {
                cout << endl; // ����� ������
            }
            system("COLOR F1");
            system("COLOR E4");
            system("COLOR F1");
            system("COLOR E4");
            Sleep(800);
            system("cls");
            Sleep(800);
        }
    }
    void start()
    {
        system("COLOR F1");
        cout << "                                 ������� ����������� C++             \n";
        cout << "                           _____________        _____________        \n";
        cout << "                           |           |  ����  |           |        \n"
                "                        ---|           |---||---|           |---     \n"
                "                           |___________|   ||   |___________|        \n"
                "                   ========================||========================\n"
                "                   ========================||========================\n"
                "                   ~~~~~~~~~I=U/R~~~~~~~~~ || ~~~~~~~~~I=U/R~~~~~~~~~\n\n";
        cout << "                   ������� 1, ��� �� ��������������� ������� �������/�������.\n";
        cout << "                   ������� 2, ��� �� ������� ������ ��������� ��������.\n";
        cout << "                   ������� 3, ��� �� ��������/���������� �������� ����.\n";
        cout << "                   ������� 4, ��� �� ������� ��������� ��������.\n";
        cout << "                   ������� 5, ��� �� ������� ���������.\n";
        cout << "��� �����: \n";
        cin >> choice_str;
        switch(choice_str)
        {
            case  1:system("cls");
                    buy_sell();
                    break;
            case 2: system("cls");
                    t_chief();
                    break;
            case  3:system("cls");
                    cout << "1. �������� ���� ����� � �������� ����. \n";
                    cout << "2. ��������� ���� ����� � ��������� �����. \n"
                            "3. ����� � ����. \n";
                    cout << "��� �����: \n";
                    cin >> choice_str;
                    switch(choice_str)
                    {
                        case 1: if(Item.quantity_day < 1)
                                {
                                    cout << "������� �������� �������� ������, ����� ����������� ������.\n";
                                    start();
                                }
                                data_reg();
                                break;
                        case 2: data_read();
                                break;
                        case 3: system("cls");
                                start();
                                break;
                        default:system("cls");
                                cout << "������. �������� 1 ��� 2. \n";
                                start();
                    }
                    break;
            case  4:{system("cls");
                    show_st_shop();}
                    break;
            case  5:{system("cls");
                    cout << "\n\n��������� ������� �����������. ������� Enter, ��� �� ����� �� ���������.\n";
                    exit(0);}
                    break;
            default:{system("cls");
                    cout << "������. �������� 1,2,3,4 ��� 5. \n";
                    start();}
        }
    }
};Shop Shop;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("COLOR F1");
    srand(time(NULL));
    system("COLOR F1");
    Shop.blink();
    Shop.start();

    return 0;
}
