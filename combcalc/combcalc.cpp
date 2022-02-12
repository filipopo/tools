// Number combination calculator, for understanding integer number bases
#include <iostream>
#include <fstream>
#include <cmath>

class redpill {
  std::ofstream myfile;
  short digits, nbase;
  char convertor[37] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  public:
  /* Converts a number to the given number base
  Effectively if the number is below 10 it'll be ascii converted to
  a char by adding 48, if it's between 9 and 36, 55 will be added */
  std::string modifier(unsigned long i) {
    std::string res = "";
    /* In any base n number the rightmost digit can be parsed by
    modular division and each next left digit can be parsed by
    dividing by the number base and repeating the process */
    if (i >= nbase)
      res = modifier(i / nbase) + res;

    unsigned long temp = i % nbase;
    if (temp < 36)
      res += convertor[temp];
    else
      res += '(' + temp + ')';

    return res;
  }

  // Sums the maximum value for each digit in the given number
  // base, (base)^position * (base - 1)
  unsigned long combinations() {
    unsigned long p = 0;
    for (short i = 0; i < digits; i++)
      p += std::pow(nbase, i) * (nbase - 1);

    return p + 1;
  }

  // Goes through all numbers that can represented in the given
  // Number base with the given amount of digits
  void print_combinations() {
    myfile.open("comb.txt");
    for (unsigned long i = 0; i < combinations(); i++) {
      std::cout << modifier(i) << std::endl;
      myfile << modifier(i) << std::endl;
    }
    myfile.close();
  }

  /* Prints every number combination for each position, with
  these any possible number can be formed with the given number
  base and the given amount of digits, (base)^position * number */
  void print_figures() {
    myfile.open("figures.txt");
    for (short i = 0; i < digits; i++) {
      for (short j = 0; j < nbase; j++) {
        std::cout << modifier(std::pow(nbase, i) * j) << std::endl;
        myfile << modifier(std::pow(nbase, i) * j) << std::endl;
      }
    }
    myfile.close();
  }

  redpill() {
    std::cout << "Input number base:" << std::endl;
    std::cin >> nbase;
    std::cout << "Digits: ";
    std::cin >> digits;
  }

  redpill(short nbase, short digits) {
    this->nbase = nbase;
    this->digits = digits;
  }
};

int main() {
  redpill a;
  a.print_figures();
  //a.print_combinations();
  std::cout << "Max combinations: " << a.combinations() << std::endl;
}
