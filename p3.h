

#include <iostream>
#include <ostream>
#include <fstream>

#include <vector>





bool isLeap(int y) {
    return y % 100 == 0 ? y % 400 == 0 : y % 4 == 0;
}

int calcDayOfYear(int month, int day, int year) {
    std::vector<int> daysIn;
    daysIn.push_back(31); // jan

    //daysIn.push_back(-99999); // feb

    daysIn.push_back(isLeap(year) ? 29 : 28); // feb

    daysIn.push_back(31); // march
    daysIn.push_back(30); // april
    daysIn.push_back(31); // may
    daysIn.push_back(30); // june
    daysIn.push_back(31); // july
    daysIn.push_back(31);  // aug
    daysIn.push_back(30); // sept
    daysIn.push_back(31); // oct
    daysIn.push_back(30); // nov
    daysIn.push_back(31); // dec

    int dayOfYear = 0;
    int m = 1;

    // add all previous months to daysInYear
    while (m != month) {
        dayOfYear += daysIn[m-1];
        m++;
    }
    dayOfYear += day;

    return dayOfYear;
}
/*
void createCSV() {

    std::fstream fout;
    fout.open("math214p3.csv", std::ios::out);

    std::fstream fin;
    fin.open("math214p3.txt", std::ios::in);

    int day, month, year;
    double temp;

    while (fin >> month >> day >> year >> temp) {
        fout << calcDayOfYear(month, day, year) << ", " << temp << "\n";
    } 
}
*/

void createCSV() {
    std::fstream foutUSAIN;
    std::fstream foutRICH;

    foutUSAIN.open("math214p3USAIN.csv", std::ios::out);
    foutRICH.open("math214p3RICH.csv", std::ios::out);

    std::fstream fin;
    fin.open("math214p3.txt", std::ios::in);

    double junk, time, uDist, rDist;

    while (fin >> time >> junk >> uDist >> junk >> rDist >> junk) {
        if (uDist >= 0) {
            foutUSAIN << time << ", " << uDist << "\n";
        }
        if (rDist >= 0) {
            foutRICH << time << ", " << rDist << "\n";
        }
    }
}