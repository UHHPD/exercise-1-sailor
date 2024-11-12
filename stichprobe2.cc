#include<iostream>
#include<fstream>
#include<cmath>

int main() {
  std::ifstream finmean("datensumme.txt");
  std::ifstream finvar("datensumme.txt");
  std::ofstream foutmean("mittelwerte.txt");
  std::ofstream foutvar("varianzen.txt");

  double a[9];
  double sum[26] = {};
  double mean[26];
  double b[9];
  double varsum[26] = {};
  double var[26];

  for(int i = 0; i < 26; i++) {

    for(int j = 0; j < 9; j++) {
      finmean >> a[j];
      sum[i] = sum[i] + a[j];
    }
    mean[i] = sum[i]/9.;

    for(int k = 0; k < 9; k++) {
      finvar >> a[k];
      b[k] = (a[k] - mean[i])*(a[k] - mean[i]);
      varsum[i] = varsum[i] + b[k];
    }
    var[i] = varsum[i]/9.;

    foutmean << mean[i] << std::endl;
    foutvar << var[i] << std::endl;
  }

  finmean.close();
  finvar.close();
  foutmean.close();
  foutvar.close();

  std::ifstream finmm("mittelwerte.txt");
  std::ifstream finmv("varianzen.txt");

  double c[26];
  double d[26];
  double smm = 0;
  double mm;
  double smv = 0;
  double mv;
  double bmv;

  for(int i = 0; i < 26; i++) {
    finmm >> c[i];
    finmv >> d[i];

    smm = smm + c[i];
    smv = smv + d[i];
  }
  mm = smm/26.;
  mv = smv/26.;
  bmv = smv/25.;

  std::cout << "Mean of 26 means: " << mm << std::endl;
  std::cout << "Mean of 26 variances: " << mv << std::endl;
  std::cout << "Unbiased sample variance: " << bmv << std::endl;

  finmm.close();
  finmv.close();
}
