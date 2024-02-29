/*
Copyright[2021]
Justin Cheok
*/

#include "ED.h"
#include <string>
#include <sstream>
#include <SFML/System.hpp>

int ED::penalty(char a, char b) {
if(a == b) {
  return 0;
}
return 1;
}

int ED::OptDistance() {
  for(int i = x - 2; i >= 0; --i) {
  for(int j = y - 2; j >= 0; --j) {
table[i][j] = min(table[i + 1][j + 1] + penalty(left.at(i), right.at(j)), table[i + 1][j] + 2, table [i][j + 1] + 2);
  }
  }
  return table[0][0];
}

ED::ED(const std::string &left, const std::string &right) {
this-> left.assign(left);
this->right.assign(right);
x = static_cast<int>(this->left.size() + 1);
y = static_cast<int>(this->right.size() + 1);

table = new int *[x];
for(int i = 0; i < x; ++i) {
table[i] = new int[y];
table [i][y - 1] = (x - 1 - i) * 2;
}
for(int j = 0; j < y; ++j) {
table[x - 1][j] = (y - 1 - j) * 2;
}
}

ED::ED() {
for(int i = 0; i < x; i++) {
delete[]table[i];
}
delete[] table;
}

int ED::min(int a, int b, int c) {
if(a < b) {
if(a < c) {
return a;
}
return c;
} else {
if(b < c) {
return b;
}
return c;
}
}
std::string ED:: Alignment() {
int stringX = 0;
int stringY = 0;
int individualCostSum = 0;
int placeHolder;
int cost = 0;
std::string nLeft;
std::string nRight;
std::string compareLeft;
std::string compareRight;
std::string individualCost;
std::string costSum;
std::stringstream ss;

while(stringX < x && stringY < y) {
if(stringX + 1 < x && stringY + 1 < y) {

cost = min(table[stringX + 1][stringY + 1] + penalty(left.at(stringX),
right.at(stringY)), table[stringX + 1][stringY] + 2, table[stringX][stringY + 1] + 2);

if(stringX + 1 <= x && stringY + 1 <= y && table[stringX + 1][stringY + 1] + penalty(left.at(stringX),right.at(stringY)) == cost){
nLeft.append(&left.at(stringX), 1);
nRight.append(&right.at(stringY), 1);
++stringX;
++stringY;
} else if(stringX + 1 <= x && table[stringX + 1][stringY] + 2 == cost) {
nRight.append("-");
nLeft.append(&left[stringX], 1);
stringX++;
} else if(stringY + 1 <= x && table[stringX][stringY + 1] + 2 == cost) {
nLeft.append("-");
nRight.append(&right[stringY], 1);
stringY++;
}
} else if(stringX + 1 < x) {
nRight.append("-");
nLeft.append(&left[stringY], 1);
stringX++;
continue;
} else if(stringY + 1 < y) {
nLeft.append("-");
nRight.append(&right[stringY],1);
stringY++;
continue;
} else {
break;
}
}

int nLeftLength = nLeft.length() - 1;
int nRightLength = nRight.length() - 1;
int i = 0;
while(i <= nLeftLength && i <= nRightLength) {
if(nRight[i] == '-' || nLeft[i] == '-') {
individualCost += '2';
placeHolder = 2;
} else if(nLeft[i] == nRight[i]) {
individualCost += '0';
placeHolder = 0;
}
 else if(nLeft[i] != nRight[i]) {
individualCost += '1';
placeHolder = 1;
}
individualCostSum = individualCostSum + placeHolder;
i++;
}
ss << individualCostSum;
ss >> costSum;
return nLeft + "\n" + nRight + "\n" + individualCost + " = " + costSum;
}
