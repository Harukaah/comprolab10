#include<iostream>
#include<fstream>
#include<iomanip>
#include<cmath>
using namespace std;

int main (){
    ifstream file;
    file.open("score.txt");

    double sum = 0;
    double sumSquaredDiff = 0;
    double value;
    int count = 0;

    while (file >> value) {
        sum += value;
        sumSquaredDiff += value * value;
        count++;
    }

    file.close();

    if (count == 0) {
        cout << "No data in the file." << endl;
        return 1; 
    }

    double mean = sum / count;
    double variance = (sumSquaredDiff / count) - (mean * mean);
    double stdDeviation = sqrt(variance);

    cout << fixed << setprecision(3); 

    cout << "Number of data = " << count << endl;

    if (static_cast<int>(mean * 1000) % 10 == 0) {
        cout << "Mean = " << showpoint << setprecision(2) << mean << endl;
    } else {
        cout << "Mean = " << showpoint << mean << endl;
    }

    cout << "Standard deviation = " << fixed << setprecision(3) << stdDeviation << endl;

    return 0;
}
