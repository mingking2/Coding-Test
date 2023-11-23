#include <iostream>
#include <map>
using namespace std;


int main() {
    string str;
    long double sum=0;
    long double totalScore=0;

    for(int i =0; i<20;i++) {
        getline(cin, str);

        int foundFirstPos = str.find(' ');
        int foundSecondPos = str.find(' ', foundFirstPos+1);

        string score = str.substr(foundFirstPos+1, foundSecondPos-foundFirstPos-1);
        string grade = str.substr(foundSecondPos+1, str.size()-1);

        map<string, long double> gradeMap = {
            {"A+", 4.5},
            {"A0", 4.0},
            {"B+", 3.5},
            {"B0", 3.0},
            {"C+", 2.5},
            {"C0", 2.0},
            {"D+", 1.5},
            {"D0", 1.0},
            {"F", 0.0}
        };

        long double value = stod(score);
        auto it = gradeMap.find(grade);

        
        if(it != gradeMap.end()) {
            totalScore += value;
            sum += (value * it->second);
        } else {
            sum += 0;
        }

    }

    long double result = sum/totalScore;
    cout << result;
}