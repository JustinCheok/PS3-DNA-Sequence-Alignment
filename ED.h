/*
Copyright[2021]
Justin Cheok
*/
#ifndef ED_H
#define ED_H

#include <iostream>
#include <string>

using namespace std;

class ED {
private:
std::string left;
std::string right;
int x, y, **table;
public:
static int penalty(char a, char b);
static int min(int a, int b, int c);
int OptDistance();
std::string Alignment();
ED();
ED(const std::string &left, const std::string &right);
};
#endif
