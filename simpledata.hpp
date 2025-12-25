#pragma once
#include <iostream>
using namespace std;
class myerror{
public:
    string error;
    myerror(string error):error(error){}
    void show_error(){
     cout<< error<<endl;
    };
    ~myerror(){};

};
class simpledata{
private:
    int day;
    int month;
    int year;
public:
    simpledata(){};
    ~simpledata(){};

    int getter_day()const{
        return day;
    }
    int getter_month()const{
        return month;
    }
    int getter_year()const{
        return year;
    }
    int setter_day(int i);
    int setter_month(int i);
    int setter_year(int i);
    void validdateday(int i);
    void validdatemonth(int i);
    void validdateyear(int i);
    string date_retrun();
    friend istream& operator>> (istream& in,simpledata& sim);
    friend ostream& operator<<(ostream& out,const simpledata& sim);
};

