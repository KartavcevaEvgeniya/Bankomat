#include <iostream>
#include <string>
using namespace std;

class Bankomat
{
private:
    int id;
    int money100, money200, money500, money1000;
    int minSum, maxSum;

public:
    void Init(int number, int min, int max)
    {
        id = number;
        minSum = min;
        maxSum = max;

        money100 = 0;
        money200 = 0;
        money500 = 0;
        money1000 = 0;
    }

    void AddMoney(int a, int b, int c, int d)
    {
        if (a < 0 || b < 0 || c < 0 || d < 0)
        {
            cout << "Invalid number of banknotes!" << endl;
            return;
        }

        money100 += a;
        money200 += b;
        money500 += c;
        money1000 += d;
    }

    int GetSum()
    {
        return money100 * 100 + money200 * 200 + money500 * 500 + money1000 * 1000;
    }

    void Withdraw(int sum)
    {
        if (sum < minSum || sum > maxSum)
        {
            cout << "Invalid amount!" << endl;
            return;
        }

        if (sum > GetSum())
        {
            cout << "Not enough money!" << endl;
            return;
        }

        int a = money1000;
        int b = money500;
        int c = money200;
        int d = money100;

        int rest = sum;

        int n1000 = min(rest / 1000, a);
        rest -= n1000 * 1000;

        int n500 = min(rest / 500, b);
        rest -= n500 * 500;

        int n200 = min(rest / 200, c);
        rest -= n200 * 200;

        int n100 = min(rest / 100, d);
        rest -= n100 * 100;

        if (rest != 0)
        {
            cout << "Cannot give this amount!" << endl;
            return;
        }

        money1000 -= n1000;
        money500 -= n500;
        money200 -= n200;
        money100 -= n100;

        cout << "Money withdrawn: " << sum << endl;
    }

    string toString()
    {
        return "ATM balance: " + to_string(GetSum()) + " UAH";
    }
};

int main()
{
    Bankomat atm;
    atm.Init(101, 100, 10000);
    atm.AddMoney(10, 10, 10, 10);
    cout << atm.toString() << endl;
    atm.Withdraw(2500);
    cout << atm.toString() << endl;

    return 0;
}