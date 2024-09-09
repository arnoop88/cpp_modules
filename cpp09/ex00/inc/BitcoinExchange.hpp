#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <utility>
#include <cctype>
#include <cstdlib>

void parse(std::ifstream &infile, std::vector<std::pair<std::string, double> > &vector, int mode);
bool check_date(std::string date);
void output(const std::vector<std::pair<std::string, double> > &vector1, const std::vector<std::pair<std::string, double> > &vector2);
int binary_search(std::string date, const std::vector<std::pair<std::string, double> > &vector2);
