#include <iostream>
#include <stdlib.h>

using namespace std;

class cash_machine
{
private:
    string name;
    string surname;
    string patronymic;
    int passcode;
    int passinput;
    int accnumber;
    int accnumberinput;
    int krsum;
    int period;
    int amount = 0;
    int tot = 0;

public:
    void setvalue()
    {
        cout << "Регистрация";

        cout << "Введите Ваше Имя: ";
        cin >> name;

        cout << "Введите Вашу фамилию: ";
        cin >> surname;

        cout << "Введите Ваше отчество: ";
        cin >> patronymic;

        cout << "Введите пин код:";
        cin >> passcode;

        cout << "Введите номер счета: ";
        cin >> accnumber;

        cout << "Введите Ваш баланс: ";
        cin >> tot;

    }
    void showdata()
    {
        cout << "Введите пин код:";
        cin >> passinput;

        if (passcode != passinput)
        {
            do
            {
                cout << "Неверный пин код!";
                cin >> passinput;
            } 
            while (passcode != passinput);
        }
        else if (passcode == passinput)
        {
            do 
            {
                cout << "Пароль верный. Добро пожаловать!\n";
                break;
            }
            while (passcode == passinput);
        }

        cout << "Имя: "
            << name << endl;
        cout << "Фамилия: "
            << surname << endl;
        cout << "Отчество: "
            << patronymic << endl;
        cout << "Номер счета: "
            << accnumber << endl;
        cout << "Ваш баланс: \n"
            << tot << endl;
    }
    void deposit()
    {
        cout << "Введите пин код:";
        cin >> passinput;

        if (passcode != passinput)
        {
            do
            {
                cout << "Неверный пин код!";
                cin >> passinput;
            } while (passcode != passinput);
        }
        else if (passcode == passinput)
        {
            do
            {
                cout << "Пароль верный. Добро пожаловать!\n";
                break;
            } while (passcode == passinput);
        }

        cout << "Какую сумму Вы хотите внести на счет: ";
        cin >> amount;

        if (amount % 10 != 0) 
        {
            do 
            {
                cout << "Банкомат не может внести введеную вами сумму! Введите сумму равную наминалу: ";
                cin >> amount;
            } 
            while (amount % 10 != 0);
        }
        
    }
    void showbal()
    {
        cout << "Введите пин код:";
        cin >> passinput;

        if (passcode != passinput)
        {
            do
            {
                cout << "Неверный пин код!";
                cin >> passinput;
            } while (passcode != passinput);
        }
        else if (passcode == passinput)
        {
            do
            {
                cout << "Пароль верный. Добро пожаловать!\n";
                break;
            } while (passcode == passinput);
        }

        tot = tot + amount;

        cout << "Теперь Ваш баланс"
            << tot;
    }
    void withdraw()
    {
        cout << "Введите пин код:";
        cin >> passinput;

        if (passcode != passinput)
        {
            do
            {
                cout << "Неверный пин код!";
                cin >> passinput;
            } while (passcode != passinput);
        }
        else if (passcode == passinput)
        {
            do
            {
                cout << "Пароль верный. Добро пожаловать!\n";
                break;
            } while (passcode == passinput);
        }

        int a, arai_balance;
        cout << "Ведите сумму для снятия: ";
        cin >> a;
        arai_balance = tot - a;

        if (a % 10 != 0)
        {
            do
            {
                cout << "Вы не можете снять введеную вами сумму! Введите сумму равную наминалу: ";
                cin >> a;
            }
            while (a % 10 != 0);
        }
        else if (a > 100000)
        {
            do
            {
                cout << "Вы можете снять до 100.000 руб. \n Введите сумму другую сумму или обратитесь в кассу!";
                cin >> a;
            } 
            while (a > 100000);
        }

        cout << "Ваш остаток: "
            << arai_balance;
    }
    void credit() 
    {
        int b;
        cout << "Введите номер счета";
        cin >> accnumberinput;
        if (accnumberinput != passinput)
        {
            do
            {
                cout << "Неверный номер счета: ";
                cin >> passinput;
            } 
            while (passcode != passinput);
        }
        else if (passcode == passinput)
        {
            do
            {
                break;
            } 
            while (passcode == passinput);
        }
        cout << "Введите сумму для кредита: ";
        cin >> krsum;
        if (krsum % 10 != 0)
        {
            do
            {
                cout << "Вы не можете получить введеную вами сумму! Введите сумму равную наминалу: ";
                cin >> krsum;
            } 
            while (krsum % 10 != 0);
        }
        else if (krsum > 100000)
        {
            do
            {
                cout << "Вы можете получить до 50.000 руб. \n Введите сумму другую сумму или обратитесь в кассу!";
                cin >> krsum;
            } 
            while (krsum > 100000);
        }
        cout << "Введите на сколько дней, вы хотите взять деньги: ";
        cin >> period;
        if (period > 30)
        {
            do
            {
                cout << "Вы не можете получить деньги на срок больше 30 дней!\n Введите количество дней равную до 30 дней: ";
                cin >> period;
            } 
            while (period % 10 != 0);
        }
        double percent;
        percent = krsum * 2;
        cout << "Вы должны вернуть в течение" << period << "дней, сумму взятую Вами и 50 процентов от взтой суммы. \nВаша сумма к возврату состовляет: " << percent;
    }
};
int main()
{
    setlocale(LC_ALL, "rus");
    cash_machine b;

    int choice;

    while (1)
    {
        cout << "Выберите услугу\n";
        cout << "1.Регистрация\n";
        cout << "2.Показать мой баланс\n";
        cout << "3.Пополнить баланс\n";
        cout << "4.Снять деньги\n";
        cout << "5.Показать общий баланс\n";
        cout << "6.Показать мой профиль\n";
        cout << "7.Кредит\n";
        cout << "8.Отменить\n";
        cin >> choice;

        switch (choice) {
        case 1:
            b.setvalue();
            break;
        case 2:
            b.showdata();
            break;
        case 3:
            b.deposit();
            break;
        case 4:
            b.withdraw();
            break;
        case 5:
            b.showbal();
            break;
        case 6:
            b.showdata();
            break;
        case 7:
            b.credit();
            break;
        case 8:
            exit(1);
            break;
        default:
            cout << " Неверный выбор ";
        }

    }
}