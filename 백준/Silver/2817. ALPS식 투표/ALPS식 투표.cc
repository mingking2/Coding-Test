#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct InputData
{
    char name;
    double chipCount;
    int price = 0;
};

vector<InputData> counts;
vector<InputData> compare;

bool compareChipCount(const InputData &a, const InputData &b)
{
    return a.chipCount > b.chipCount;
}

bool compareName(const InputData &a, const InputData &b) {
    return a.name < b.name;
}

int main()
{
    int x, n;

    cin >> x >> n;

    for (int i = 0; i < n; i++)
    {
        InputData inputData;
        cin >> inputData.name >> inputData.chipCount;
        if (inputData.chipCount / x * 100 >= 5)
        {
            counts.push_back(inputData);
        }
    }

    for (int i = 1; i <= 14; i++)
    {
        for (int j = 0; j < counts.size(); j++)
        {
            InputData input;
            input.name = counts[j].name;
            input.chipCount = counts[j].chipCount / i;
            compare.push_back(input);
        }
    }

    sort(compare.begin(), compare.end(), compareChipCount);

    for (int i = 0; i < counts.size(); i++)
    {
        for (int j = 0; j < 14; j++)
        {
            if (counts[i].name == compare[j].name)
            {
                counts[i].price += 1;
            }
        }
    }

    sort(counts.begin(), counts.end(), compareName);

    for (int i = 0; i < counts.size(); i++) {
        cout << counts[i].name << " " << counts[i].price << endl;
    }
}

    
