#include <iostream>
#include <fstream>
#include <vector>

int main() {
  std::ofstream file("output.csv");

  if (!file.is_open()) {
    std::cerr << "Failed to open file." << std::endl;
    return 1;
  }

  std::vector<std::string> header = {"Método", "Entrada", "Tempo", "Execução"};

  for (size_t i = 0; i < header.size(); ++i) {
    file << header[i];
    if (i < header.size() - 1) {
      file << ";";
    }
  }
  file << "\n";

  file.close();
  std::cout << "CSV CRIADO!" << std::endl;

  return 0;
}
