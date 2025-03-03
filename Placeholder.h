#include <iostream>
#include <vector>
#include <memory>
using namespace std;

template <class T>
class winnings {
private:
    T money;
    T price;
    vector<T> grades;
public:
    winnings():
            money(0),
            price(0),
            grades(vector<T>())
    {
//        cout << "Creat";
    }
    winnings(T _money, T _price, vector<T> _grades):
            money(_money),
            price(_price),
            grades(_grades)
    {
//        cout << "Creat";
    }
    ~winnings()
    {
//        cout << "Deconstructor";
    }
    T calculateProfit() {
        T winnings;
        T medie;
        for (int i = 0; i < grades.size(); i++)
            medie += grades[i];
        medie /= grades.size();
        winnings = money + medie * price;
        return winnings;
    }
};
