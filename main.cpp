/*
Copyright[2021]
Justin Cheok
*/
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <iostream>
#include "ED.h"

int main(int argc, char **argv) {
std::string lString, rString;
std::getline(std::cin, lString);
// std::cout << "lString: " << lString << std::endl;
if(std::isspace(lString.at(lString.size() - 1))) {
  lString.erase(lString.size() - 1);
}
std::getline(std::cin, rString);
// std::cout << "rString: " << rString << std::endl;
if(std::isspace(rString.at(rString.size() - 1))) {
  rString.erase(rString.size() - 1);
}

sf::Clock clock;
sf::Time t;

ED testFile(lString, rString);
if(std::isspace(std::isspace(rString.at(0)) || std::isspace(rString.at(rString.size() - 1)))) {
}
std::cout << "Edit Distance: " << testFile.OptDistance() << std::endl;
std::cout << testFile.Alignment() << std::endl;
t = clock.getElapsedTime();
std::cout << "Execution time is " << t.asSeconds() << " seconds \n";
}
