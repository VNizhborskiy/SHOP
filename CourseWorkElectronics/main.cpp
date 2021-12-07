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
int counts; // счетчик
int q_purchase = 0;//переменная для работы функции void buy_sell()
void start(); void blink(); void data_reg(); void t_chief(); void supply(); void data_read(); //Описание функций для работы с ними
void buy_sell(); void bookeep(); void salesman(); void customers(); void show_st_shop();
int c; // один раз при первом запуске buy_sell()

// 1-я семья классов:

class Human
{
public:
    vector <string> name_h = {"Валера","Вася","Игорь","Максим","Рома","Антон","Славик","Даня","Настя","Маша","Миша"};

}; Human Human;

class Buyer : public Human
{
public:
    vector <int> qua_purchase;
}; Buyer Buyer;

// 2-я семья классов:

class Seller
{
public:
    vector <string> name_s = {"Петрович", "Анатолич", "Иваныч"};
    vector <int> salary; // зарплата продавца от к-ства проданого товара
    vector <int> salary_profit; // зарплата зависит от дохода
    vector <int> salary_valuta; // зарплата

}; Seller Seller;

class Chief : public Seller
{
public:
    string num_reg = "+380";
    long long phone_num = 123456789;
    string email = "Шеф@gmail.com";
    int money;
    int money_day;
}; Chief Chief;

// Класс товаров:

class Item
{
public:
    int quantity;
    int quantity_day;//общее количество товаров за несколько поставок
    int qua_sell_day; // общее количество товаров продано
    int prc_supply;
    vector <int> prc_itsupply; // цена закупки  за 1 шт.
    vector <int> price = {5,6,4,10,10,5,
                                    5,10,30,10,8,9,
                                    15,7,6,20,14,
                                    8}; // цена продажи за 1 шт.
    char valuta = '$';
    string grivna = "грн";
    vector <int> qua_item;
    vector <int> qua_item_sell;
    vector <string> name_of_item = {"светодиоды","транзисторы","резисторы","катушки","конденсаторы","дроссели",
                                    "аккумуляторы","диоды","датчики","кварцевые генераторы","теристоры","динамики",
                                    "микросхемы","семисторы","переменные резисторы","трансформаторы","варикапы",
                                    "варисторы"};
    void supply()
    {
        int i_cc = 1; //счетчик для номера спереди
        prc_itsupply.resize(name_of_item.size());
        cout << "Цены на рынке (Элемент/цена за 1 шт.): \n";
        for(unsigned int i_0 = 0; i_0 < prc_itsupply.size(); i_0++)
        {
            prc_itsupply[i_0] = rand()% 3 + 1;
            cout << i_cc << ". " << name_of_item[i_0] << ": " << prc_itsupply[i_0] << valuta << endl;
            i_cc++;
        }
        qua_item.resize(name_of_item.size());//Присвоение каждому элементу вектора qua_item случайное значение
        for(unsigned int i_0 = 0; i_0 < qua_item.size(); i_0++)
        {
            qua_item.at(i_0) += rand()%200 + 15;//случайное значение от 15 до 214
        }

        for(unsigned int i_0 = 0; i_0 < qua_item.size(); i_0++)//Подсчет общего количества на складе
        {
            quantity += qua_item.at(i_0);
        }
        quantity_day = quantity;
        c_for_sls++;
    }
}; Item Item;

// Функции для работы магазина:

void hire()
{
    cout << "Вы хотите нанять нового работника или уволить старого?\n"
            "1. Нанять\n"
            "2. Уволить\n";
    cout << "Ваш выбор: \n";
    cin >> choice_str;
    switch(choice_str)
    {
        case 1: {cout << "Внесите в базу данных имя нового работника: \n";
                string nwwork;
                cout << "Имя: ";
                cin >> nwwork;
                cout << "Вы успешно наняли нового работника.\n";
                Seller.name_s.push_back(nwwork);
                cout << "Нажмите +, что бы продолжить.";
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
                    cout << "Сейчас в магазине остался 1 работник, наймите новых.\n";
                    t_chief();
                }
                cout << "Какого работника вы хотите уволить?\n";
                cout << "Список продавцов: \n";
                int i_f = 0;
                for(unsigned int i_0 = 0; i_0 < Seller.name_s.size(); i_0++)
                {
                    cout << i_f << ". " << "Имя: " << Seller.name_s.at(i_0) << endl;
                    i_f++;
                }
                cout << "Кого из них вы хотите уволить? Напишите цифру: \n"; int num_fr;
                cin >> num_fr;
                while(num_fr > Seller.name_s.size()-1)
                {
                    cout << "Выберите число из вышепредложенных.\n";
                    cin >> num_fr;
                }
                cout << "Вы уволили работника " << Seller.name_s[num_fr] << ".";
                Seller.name_s.erase(Seller.name_s.begin() + num_fr);
                cout << "Нажмите +, что бы продолжить.";
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
                cout << "Ошибка. Выберите 1 или 2. \n";
                start();
    }
}

void show_st_shop()
{
    cout << "1. Список товаров в наличии.\n"
            "2. Продано товаров.\n"
            "3. Выйти в меню.\n";
    cout << "Ваш выбор: \n";
    cin >> choice_str;
    switch(choice_str)
    {
         case 1:{
                if(c_for_sls < 1)
                {
                    cout << "Товар еще не закуплен.\n";
                    start();
                }
                cout << "Общее количество на складе: " << Item.quantity_day << endl;
                cout << "Данные о товаре (название/количество на складе): " << endl;
                int i_3 = 1;
                for(unsigned int i_0 = 0; i_0 < Item.name_of_item.size(); i_0++)
                {
                    cout << i_3 << ".  " << Item.name_of_item.at(i_0) << ": <--- " << Item.qua_item.at(i_0) << endl;
                    i_3++;
                }
                cout << "Нажмите +, что бы продолжить.";
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
                    cout << "Продавцы сегодня еще не работали.\n";
                    start();
                }
                for(unsigned int i_0 = 0; i_0 < Item.name_of_item.size(); i_0++)
                {
                    Item.qua_sell_day += Item.qua_item_sell.at(i_0);
                }
                cout << "Продано товаров: " << Item.qua_sell_day << endl;
                cout << "Данные о товаре (название/продано): " << endl;
                int i_3 = 1;
                for(unsigned int i_0 = 0; i_0 < Item.name_of_item.size(); i_0++)
                {
                    cout << i_3 << ".  " << Item.name_of_item.at(i_0) << ": ---> " << Item.qua_item_sell.at(i_0) << endl;
                    i_3++;
                }
                                cout << "Нажмите +, что бы продолжить.";
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
                cout << "Ошибка. Выберите 1 или 2. \n";
                start();}


    }
}

void customers()
{
    system("cls");
    cout << "Список покупателей: \n";
    int i_2 = 1;
    for(unsigned int i_0 = 0; i_0 < Buyer.name_h.size(); i_0++)
    {
        cout << i_2 << ". " << "Имя: " << Buyer.name_h.at(i_0) << " / Количество посещений магазина: " <<  Buyer.qua_purchase.at(i_0) << endl;
        i_2++;
    }
    cout << "Нажмите +, что бы продолжить.";
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
    cout << "Посмотреть информацию о продавцах: \n"
            "1. Посмотреть зарплату и список продавцов. \n"
            "2. Посмотреть достижения продавцов. \n"
            "3. Начислить зарплату работникам. \n";
    cout << "Ваш выбор: \n";
    cin >> choice_str;
    switch(choice_str)
    {
        case 1: {
                    cout << "Список продавцов: \n";
                    int i_2 = 1;
                    for(unsigned int i_0 = 0; i_0 < Seller.name_s.size(); i_0++)
                    {
                        cout << i_2 << ". " << "Имя: " << Seller.name_s.at(i_0) << " / продано товара: " << Seller.salary.at(i_0);
                        cout << " / зарплата: " << Seller.salary_valuta.at(i_0) << Item.grivna << endl;
                        i_2++;
                    }
                    cout << "Нажмите +, что бы продолжить.";
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
                        cout << "Продавцы сегодня еще не работали.\n";
                        start();
                    }
                    cout << "Достижения продавцов: \n";
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
                    cout << "Пока что лучший работник: " << max_s << "." << "\nСамая большая прибыль: " << max_p << Item.valuta << ", продал: " << max_i;
                    cout << "\nНачислить ему премию: \n"
                            "1.Да\n"
                            "2.Нет\n";
                    cin >> choice_str;
                    switch(choice_str)
                    {
                        case 1:  if(Chief.money_day < 100)
                                 {
                                    cout << "Сейчас в бухгалтерии слишком мало денег. Попробуйте позже.\n";
                                    start();
                                 }
                                 cout << "Какую премию вы хотите начислить " << max_s << "?(премия в $)\n";
                                 cin >> premia;
                                 while(premia > Chief.money_day)
                                 {
                                     cout << "Не хватает денег. Попробуйте меньшую сумму:\n";
                                     cin >> premia;
                                 }
                                 cout << "Вы начислили премию продавцу "<< max_s <<" в размере "<< premia << Item.valuta <<  "!\n";
                                 Chief.money_day -= premia;
                                 cout << "Остаток денег: " << Chief.money_day << endl;
                                 break;
                        case 2:  cout << "А жаль. Хороший работник...\n";
                                 start();
                                 break;
                    }
                    start();
                }
                break;
        case 3: {
                     if(Chief.money_day < 1000)
                     {
                        cout << "Сейчас в бухгалтерии слишком мало денег. Попробуйте позже.\n";
                        start();
                     }
                     system("cls");
                     cout << "Нажмите 1, что бы начислить зарплату работникам.\n"
                             "Нажмите 2, что бы отказаться платить зарплату.\n";
                     cout << "Ваш выбор: \n";
                     cin >> choice_str;
                     switch(choice_str)
                     {
                         case 1: for(unsigned int i_ss = 0; i_ss < Seller.name_s.size(); i_ss++)
                                 {
                                     Chief.money_day -= Seller.salary_valuta.at(i_ss)/26; //Перевод гривен в долары (курс 26)
                                 }
                                 cout << "Вы успешно начислили зарплату работникам !";
                                 cout << "Текущий бюджет: " << Chief.money_day << Item.valuta << endl;
                                 start();
                                 break;
                         case 2: cout << "Работники на тебя обиделись! Прибыль уменшилась!";
                                 start();
                                 break;
                         default:system("cls");
                                 cout << "Ошибка. Выберите 1 или 2. \n";
                                 start();

                     }
                }
                break;
        default:{
                    system("cls");
                    cout << "Ошибка. Выберите 1 или 2. \n";
                    start();
                }
                break;
    }
}

void bookeep()
{
    cout << "Что вас интересует?\n"
            "1. Посмотреть выручку за день.\n";
    cout << "Ваш выбор: \n";
    cin >> choice_str;
    switch(choice_str)
    {
        case 1: if(Chief.money_day  < 0)
                {
                    cout << "Пока-что мы в минусе: "  << Chief.money_day << Item.valuta << endl;
                    start();
                }
                cout << "Выручка за день: " << Chief.money_day << " " << Item.valuta << endl;
                start();
                break;
        default:system("cls");
                cout << "Ошибка. Выберите 1 или 2. \n";
                start();
    }
    start();
}

void start()
{
    system("COLOR F1");
    cout << "                                 Магазин Электроники C++             \n";
    cout << "                           _____________        _____________        \n";
    cout << "                           |           |  МЕНЮ  |           |        \n"
            "                        ---|           |---||---|           |---     \n"
            "                           |___________|   ||   |___________|        \n"
            "                   ========================||========================\n"
            "                   ========================||========================\n"
            "                   ~~~~~~~~~I=U/R~~~~~~~~~ || ~~~~~~~~~I=U/R~~~~~~~~~\n\n";
    cout << "                   Нажмите 1, что бы промоделировать процесс продажи/покупки.\n";
    cout << "                   Нажмите 2, что бы открыть функии директора магазина.\n";
    cout << "                   Нажмите 3, что бы записать/посмотреть бинарный файл.\n";
    cout << "                   Нажмите 4, что бы увидеть состояние магазина.\n";
    cout << "                   Нажмите 5, что бы закрыть программу.\n";
    cout << "Ваш выбор: \n";
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
                cout << "1. Записать базу даных в бинарный файл. \n";
                cout << "2. Прочитать базу даных с бинарного файла. \n"
                        "3. Выйти в меню. \n";
                cout << "Ваш выбор: \n";
                cin >> choice_str;
                switch(choice_str)
                {
                    case 1: if(Item.quantity_day < 1)
                            {
                                cout << "Сначала сделайте поставку товара, потом записывайте данные.\n";
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
                            cout << "Ошибка. Выберите 1 или 2. \n";
                            start();
                }
                break;
        case  4:{system("cls");
                show_st_shop();}
                break;
        case  5:{system("cls");
                cout << "\n\nПрограмма успешно завершилась. Нажмите Enter, что бы выйти из программы.\n";
                exit(0);}
                break;
        default:{system("cls");
                cout << "Ошибка. Выберите 1,2,3,4 или 5. \n";
                start();}
    }
}

void blink()
{
    for(int i_0 = 0; i_0 < 3; i_0++)
    {
        for(int i_0 = 0; i_0 < 41; i_0++)
        {
            cout << "                  "; // Сдвиг в сторону
        }
        cout << " Вас приветствует магазин Электроники C++      \n";
        for(int i_0 = 0; i_0 < 10; i_0++)
        {
            cout << endl; // Сдвиг ввверх
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

void t_chief()
{

    cout << "Выберите функцию директора: \n1. Оформить поставку товара.\n"
            "2. Информация о работниках магазина. \n"
            "3. Информация о покупателях. \n"
            "4. Открыть бухгалтерию.\n"
            "5. Нанять/уволить работника.\n"
            "6. Выйти в меню.\n";
    cout << "Ваш выбор: \n";
    cin >> choice_str;
    switch(choice_str)
    {
        case 1: if(Item.quantity_day > 300)
                {
                    cout << "В магазине сейчас достаточное количество товара. Вы уверены что хотите еще закупить?\n"
                            "1. Да\n"
                            "2. Нет\n";
                    cout << "Ваш выбор: \n";
                    cin >> choice_str;
                    switch(choice_str)
                    {
                        case 1: cout << "Хорошо, успешной Вам закупки.\n";
                                break;
                        case 2: start();
                                break;
                        default:system("cls");
                                cout << "Ошибка. Выберите 1 или 2. \n";
                                start();
                    }
                }
                Item.supply();
                cout << "Вы успешно закупили товар !\n";
                cout << "Количество приобретённого товара: " << Item.quantity_day << endl;
                Item.quantity = 0; // обнуление счетчика товаров
                for(unsigned int i_0 = 0; i_0 < Item.prc_itsupply.size(); i_0++)
                {
                    Item.prc_supply += Item.qua_item[i_0]*Item.prc_itsupply[i_0];//Умножение количества каждого элемента на цену
                }
                cout << "Деньги потраченные на закупку: " << Item.prc_supply << Item.valuta << endl;
                Chief.money_day -= Item.prc_supply;
                cout << "Нажмите +, что бы продолжить.";
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
                    cout << "В магазине еще ничего не было продано. \n";
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
                cout << "Ошибка. Выберите 1,2,3,4,5 или 6. \n";
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
        cout << "Перед открытием магазина огласите какая будет зарплата у продавца\n";
        cout << "от ОДНОГО проданого товара (в гривнах):\n";
        cin >> wage_F_workers;
        while(wage_F_workers > 9 || wage_F_workers < 1)
        {
            cout << "Выберите зарплату в диапазоне от 1 до 9.\n";
            cin >> wage_F_workers;
        }
        cout << "Каждый продавец от ОДНОГО проданого товара будет получать " << wage_F_workers << " " << Item.grivna << "." << endl;
        c++;
    }
    if(Item.quantity_day < 300 && Item.quantity_day > 1)
    {
        cout << "Товара на складе меньше 300 ! Нужно оформить поставку товара!\n"
                "1. Оформить поставку товара.\n"
                "2. Отказаться.\n";
        cin >> choice_str;
        switch(choice_str)
        {
            case 1: system("cls");
                    t_chief();
                    break;
            case 2: start();
                    break;
            default:cout << "Выберите 1 или 2.\n";
                    cin >> choice_str;
                    start();
        }
    }
    cout << "С какой скоростью вы хотите промоделировать работу магазина?\n"
            "1. Обычный режим.\n"
            "2. Ускоренный режим.\n"
            "3. Выйти в меню.\n";
    cin >> choice_str;
    switch(choice_str)
    {
        case 1: {system("COLOR E9");
                system("cls");
                if(Item.quantity_day < 1)
                {
                    cout << "На складе пусто, магазин не работает. Вам нужно оформить поставку товара.\n\n";
                    t_chief();
                }
                int choice_cnt;
                int i_s;//Счетчик для продавцов
                int i_b;//Счетчик для покупателей
                int i_i;//Счетчик для товара
                int ch_q;//Запрос покупателя
                do
                {
                     i_s = rand()%Seller.name_s.size();
                     i_b = rand()%Buyer.name_h.size();
                     i_i = rand()%Item.name_of_item.size();//Склад товару та обсяг обороту
                     ch_q = rand()%100 + 1;
                     cout << " (Продавец)" << "   - Здравствуйте. Меня зовут " << Seller.name_s[i_s] << ".\n "
                     "               Чем я могу Вам помочь?\n";
                     Sleep(3000);
                     cout << " (Покупатель)" << " - Здравствуйте. Меня зовут " << Buyer.name_h[i_b] << ".\n "
                     "               Мне нужны " << Item.name_of_item[i_i] << ".\n";
                     Sleep(3000);
                     cout << " (Продавец)" << "   - У нас есть в наличии " << Item.qua_item[i_i] << ".\n"
                     "                По цене " << Item.price[i_i] << Item.valuta << " за штуку" << ".\n ";
                     Sleep(3000);
                     cout << "               Сколько вам нужно?\n";
                     Sleep(3000);
                     cout << " (Покупатель)" << " - Мне надо " << ch_q << ".\n";
                     Sleep(3000);
                     if(ch_q > Item.qua_item[i_i])
                     {
                         cout << " (Продавец)" <<"   - Извините, у нас нету такого количества.\n";
                         Sleep(3000);
                         cout << " (Покупатель)" << " - Пойду в другой магазин. До свидания. \n\n";
                         Sleep(3000);
                         cout << "1. Продолжить.\n2. Выйти из магазина\n";
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
                                    cout << "Ошибка. Выберите 1 или 2. \n";
                                    start();
                         }
                     }
                     Chief.money = Item.price[i_i] * ch_q;
                     Buyer.qua_purchase.resize(Buyer.name_h.size());
                     if(ch_q > 50)//Для оптовых покупателей
                     {
                         system("COLOR E4");
                         cout << " (Продавец)" <<"   - Для оптовых покупателей у нас скидка 10%!\n"
                         "                Вместо " << Chief.money << Item.valuta << " Вам нужно заплатить всего лишь ";
                         Chief.money -= (Chief.money*10)/100;
                         cout << Chief.money << Item.valuta << "\n";

                         Sleep(3000);
                         system("COLOR E9");
                     }

                     else if(Buyer.qua_purchase[i_b] > 40)// Для постоянных покупателей
                     {
                         system("COLOR E4");
                         cout << " (Продавец)" << "   - Вы наш постоянный покупатель! " << "\n ";
                         cout << "               Вам скидка 15% !\n";
                         cout << "                Вместо " << Chief.money << Item.valuta << " Вам нужно заплатить всего лишь ";
                         Chief.money -= (Chief.money*15)/100;
                         cout << Chief.money << Item.valuta << "\n";
                         Sleep(3000);
                         system("COLOR E9");
                     }
                     Chief.money_day += Chief.money;
                     cout << " (Продавец)" << "   - Ваша покупка оформлена! С вас " << Chief.money << Item.valuta << "\n";
                     Sleep(3000);
                     cout << " (Покупатель)" << " - Ага, вот деньги. Спасибо, до свидания!\n";
                     Sleep(3000);
                     cout << " (Продавец)" << "   - Спасибо за покупку, приходите еще!\n\n";
                     Sleep(3000);
                     Item.qua_item_sell[i_i] += ch_q ; //К_ство проданных товаров
                     Item.qua_item[i_i] -= ch_q;
                     Item.quantity_day -= ch_q;
                     q_purchase++;
                     Buyer.qua_purchase[i_b] = q_purchase; //Сохранение информациии о покупателе
                     Seller.salary[i_s] += ch_q; //Зарплата продавца
                     Seller.salary_profit[i_s] += Chief.money;
                     counts++; //для функции salesman() case 2
                     Seller.salary_valuta.at(i_s) = wage_F_workers * Seller.salary.at(i_s);
                     cout << "1. Продолжить.\n2. Выйти из магазина\n";
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
                                 cout << "Ошибка. Выберите 1 или 2. \n";
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
                    cout << "На складе пусто, магазин не работает. Вам нужно оформить поставку товара.\n\n";
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
                     cout << " (Продавец)" << "   - Здравствуйте. Меня зовут " << Seller.name_s[i_s] << ".\n "
                     "               Чем я могу Вам помочь?\n";
                     //Sleep(5000);
                     cout << " (Покупатель)" << " - Здравствуйте. Меня зовут " << Buyer.name_h[i_b] << ".\n "
                     "               Мне нужны " << Item.name_of_item[i_i] << ".\n";
                     //Sleep(5000);
                     cout << " (Продавец)" << "   - У нас есть в наличии " << Item.qua_item[i_i] << ".\n"
                     "                По цене " << Item.price[i_i] << Item.valuta << " за штуку" << ".\n "
                     "               Сколько вам нужно?\n";
                     //Sleep(5000);
                     cout << " (Покупатель)" << " - Мне надо " << ch_q << ".\n";
                     //Sleep(5000);
                     if(ch_q > Item.qua_item[i_i])
                     {
                         cout << " (Продавец)" <<"   - Извините, у нас нету такого количества.\n";
                         //Sleep(5000);
                         cout << " (Покупатель)" << " - Пойду в другой магазин. Досвиданье. \n\n";
                         //Sleep(5000);
                         i_0++;
                         system("cls");
                         continue;
                     }
                     //Sleep(5000);
                     Chief.money = Item.price[i_i] * ch_q;
                     Buyer.qua_purchase.resize(Buyer.name_h.size());
                     if(i_0 > 10 && Item.qua_item[i_i] > 100)//обесценивается со временем
                     {
                         system("COLOR E4");
                         cout << " (Продавец)" << "   - Этот товар сейчас обесценивается..Скидка на него 50% !! " << "\n ";
                         cout << "               Вам скидка 50% !\n";
                         cout << "                Вместо " << Chief.money << Item.valuta << " Вам нужно заплатить всего лишь ";
                         Chief.money -= (Chief.money*50)/100;
                         cout << Chief.money << Item.valuta << "\n";


                     }
                     else if(ch_q > 50)//Для оптовых покупателей
                     {
                         system("COLOR E4");
                         cout << " (Продавец)" <<"   - Для оптовых покупателей у нас скидка 10%!\n"
                         "                Вместо " << Chief.money << Item.valuta << " Вам нужно заплатить всего лишь ";
                         Chief.money -= (Chief.money*10)/100;
                         cout << Chief.money << Item.valuta << "\n";

                     }

                     else if(Buyer.qua_purchase[i_b] > 40)//Для постоянных покупателей
                     {
                         system("COLOR E4");
                         cout << " (Продавец)" << "   - Вы наш постоянный покупатель! " << "\n ";
                         cout << "               Вам скидка 15% !\n";
                         cout << "                Вместо " << Chief.money << Item.valuta << " Вам нужно заплатить всего лишь ";
                         Chief.money -= (Chief.money*15)/100;
                         cout << Chief.money << Item.valuta << "\n";



                     }
                     Chief.money_day += Chief.money;
                     cout << " (Продавец)" << "   - Ваша покупка оформлена! С вас " << Chief.money << Item.valuta << "\n";
                     //Sleep(5000);
                     cout << " (Покупатель)" << " - Ага, вот деньги. Спасибо, досвиданье!\n";
                     //Sleep(5000);
                     cout << " (Продавец)" << "   - Спасибо за покупку, приходите еще!\n\n";
                     Sleep(1500);
                     Item.qua_item_sell[i_i] += ch_q ; //К_ство проданных товаров
                     Item.qua_item[i_i] -= ch_q;
                     Item.quantity_day -= ch_q;
                     q_purchase++;
                     Buyer.qua_purchase[i_b] = q_purchase; //Сохранение информациии о покупателе
                     Seller.salary[i_s] += ch_q; //Зависимость зарплаты продавца
                     Seller.salary_profit[i_s] += Chief.money;
                     counts++;//для функции salesman() case 2
                     Seller.salary_valuta.at(i_s) = wage_F_workers * Seller.salary.at(i_s);
                     system("cls");
                     i_0++;
                     continue;
                 }
                 cout << "Промоделировано 20 ситуаций продажи/покупки.\n";
                 cout << "1. Продолжить.\n2. Выйти из магазина\n";
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
                            cout << "Ошибка. Выберите 1 или 2. \n";
                            start();
                 }
                 }
                 break;
        case 3:{start();}
                break;
        default:{system("cls");
                cout << "Ошибка. Выберите 1,2 или 3. \n";
                start();}
                break;
    }

}

void data_reg()
{
    work_database working;
    int i_1 = 1; int i_2 = 1; int i_3 = 1;// счетчики

    // Запись информации о работниках:

    ofstream work;
    work.open("test.txt",ios_base::binary | ios_base::app);
    work << "====================================\n";
    work << "Данные о продавцах: " << endl;
    for(unsigned int i_0 = 0; i_0 < Seller.name_s.size(); i_0++)
    {
         work << i_2 << ". " << Seller.name_s.at(i_0) << endl;
        i_2++;
    }
    work << "====================================\n";
    work << "Контактные данные руководителя магазина: " << endl;
    Chief.name_s = {"Иванов Иван Иваныч"};
    work << "Имя директора: " <<  Chief.name_s[0] << endl;
    work << "Номер телефона:" << Chief.num_reg  << Chief.phone_num << endl;
    work << "Email: " << Chief.email << endl;
    work << "====================================\n";
    work.close();
    working.filled("output.WorkersDB");

    //Запись информации о покупателях:

    work.open("test.txt",ios_base::binary | ios_base::app);
    work << "====================================\n";
    work << "Данные о покупателях: " << endl;
    for(unsigned int i_0 = 0; i_0 < Buyer.name_h.size(); i_0++)
    {
        work << i_1 << ". " << Buyer.name_h.at(i_0) << endl;
        i_1++;
    }
    work << "====================================\n";
    work.close();
    working.filled("output.SalesmansDB");

    //Запись информации о товаре:

    work.open("test.txt",ios_base::binary | ios_base::app);
    work << "====================================\n";
    work << "Данные о товаре (название/количество на складе): \n";
    for(unsigned int i_0 = 0; i_0 < Item.name_of_item.size(); i_0++)
    {
        work << i_3 << ".  " << Item.name_of_item.at(i_0) << ": ---> " << Item.qua_item.at(i_0) << "\n";
        i_3++;
    }
    work << "Всего товара:" << " ---> " << Item.quantity_day << "\n";
    work << "====================================\n";
    work.close();
    working.filled("output.GoodsDB");

    cout << "Вы успешно записали данные в бинарный файл !\n\n"; counts++;//для функции
    start();
}

void data_read()
{
    if(counts < 1)
    {
        cout << "Сначала запишите данные в бинарный файл.\n";
        start();
    }
    cout << "\nКакой бинарный файл Вы хотите прочитать?\n"
            "1. Информация о работниках магазина.\n"
            "2. Информация о покупателях.\n"
            "3. Информация о товаре\n";
    cout << "Ваш выбор: \n";
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
                cout << "Нажмите +, что бы продолжить.";
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
                cout << "Нажмите +, что бы продолжить.";
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
                cout << "Нажмите +, что бы продолжить.";
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
                cout << "Ошибка. Выберите 1,2 или 3. \n";
                start();
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("COLOR F1");
    srand(time(NULL));
    blink();
    system("COLOR F1");
    start();

    return 0;
}
