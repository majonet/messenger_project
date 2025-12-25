#include <iostream>
using namespace std;
#include "simpledata.hpp"
void simpledata::validdateday(int i){
    if (i>31 || i<1){
       throw myerror("invalid day");}

};
void simpledata::validdatemonth(int i){
    if (i>12 || i<1){
       throw myerror("invalid month");
    }
};
void simpledata::validdateyear(int i){
    if (i>2100 || i<1900){
       throw myerror("invalid year");
    }
};
int simpledata::setter_day(int i){
    validdateday(i);
    day=i;
    return day;
};
int simpledata::setter_month(int i){
    validdatemonth(i);
    month=i;
    return month;
};
int simpledata::setter_year(int i){
    validdateyear(i);
    year=i;
    return year;
};
istream& operator>> (istream& in,simpledata& sim){
    // cout << "enter simple_data: ";
    // in >> sim.temp;
    // te.valid_datatemp(te.temp);
    // return in;
    int y, m, d;
    char sep1, sep2; 
    cout << "enter birth_date (y/m/d): ";
    in >> y >> sep1 >> m >> sep2 >> d;
    if (sep1 != '/' || sep2 != '/') {
        throw myerror("invalid date format.");
    }
    sim.setter_day(d);
    sim.setter_year(y);
    sim.setter_month(m);
    return in;
};

ostream& operator<<(ostream& out,const simpledata& sim){
  out<<sim.getter_year()<<"/"<<sim.getter_month()<<"/"<<sim.getter_day()<<endl;
  return out;
};
string simpledata::date_retrun(){
    string date =to_string(getter_year()) + "/" +to_string(getter_month()) + "/" +to_string(getter_day());
    return date;
}





