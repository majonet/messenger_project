#include <iostream>
#include <fstream>
#include <string>
#include<list>
using namespace std;


int main()
{ 
std::list<std::string> lst = {"a", "b", "c", "d"};

int index = 0;

auto it = lst.begin();
std::advance(it, index);

std::cout << *it;   // "c"

}