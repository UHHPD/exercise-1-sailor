#include<iostream>
#include<fstream>

int main() {
  std::ifstream fin("daten.txt");
  std::ofstream fout("datensumme.txt");
  int zahl1;
  int zahl2;
  int summe;
  for(int i = 0; i < 234; i++) {
    fin >> zahl1 >> zahl2;
    summe = zahl1 + zahl2;
    fout << summe << std::endl;
  }
  fin.close();
  fout.close();
}
