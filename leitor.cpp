#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main(int argc, char* argv[]) {

  std::string file_path = argv[1];
  std::ifstream file(file_path);

  std::vector<int> numbers;
  int number;
  while (file >> number) {
    numbers.push_back(number);
  }

  
  file.close();
  /*/ Output the numbers to verify
  for (int num : numbers) {
    std::cout << num << "\n";
  }
  /*/
  return 0;
}