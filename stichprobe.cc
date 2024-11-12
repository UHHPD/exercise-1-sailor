#include<iostream>
#include<fstream>
#include<sstream>
#include<cmath>

int main() {
  std::ifstream fin;
  fin.open("datensumme.txt", std::ifstream::in);
  std::string line;
  double a;
  double sum = 0;
  double mean;

  while(getline(fin, line)) {
    std::string::size_type n = line.find("//");
    if(n != std::string::npos)
      line.erase(n);

    std::istringstream iss(line);

    while(iss >> a)
      sum = sum + a;
  }
  mean = sum/234.;
  std::cout << "Mean: " << mean << std::endl;
  fin.close();

  fin.open("datensumme.txt", std::ifstream::in);
  double b;
  double varsum = 0;
  double var;

  while(getline(fin, line)) {
    std::string::size_type n = line.find("//");
    if(n != std::string::npos)
      line.erase(n);

    std::istringstream iss(line);

    while(iss >> a) {
      b = (a - mean)*(a - mean);
      varsum = varsum + b;
    }
  }
  var = varsum/234.;
  std::cout << "Variance: " << var << std::endl;
  fin.close();

  double sigma;
  sigma = sqrt(var);
  std::cout << "Standard deviation: " << sigma << std::endl;
}
