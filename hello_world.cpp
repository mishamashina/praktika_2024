#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << "Hello!" << endl ;
    vector<int> user;
    int user_numb;
    int i = 0;
    int index = 0;
    int sum = 0;
    int max = 0;
    int max_index = 0;

    while (i < 10)
    {
        cout << "Введите число" << endl;
        cin >> user_numb;
        user.push_back(user_numb);
        i++;
    }

    cout << "Элементы массива" << endl;

    for (auto it = user.cbegin(); it != user.cend(); ++it)
    {
        sum += *it;
        if (max < *it)
        {
            max = *it;
            max_index = index;
        }
        cout << ' ' << *it << endl;
        index++;
    }

    cout << "Сумма элементов = " << sum << " " << "Максимальный элемент = " << max << " " << "Его индекс = " << max_index << endl;

    return 0;
}