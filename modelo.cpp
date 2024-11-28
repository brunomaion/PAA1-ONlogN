#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

int main(int argc, char* argv[]) {

  std::string string_entrada = argv[1];

  size_t pos = string_entrada.find("entradas/");
  if (pos != std::string::npos) {
    string_entrada.erase(pos, 9); // 9 is the length of "entradas/"
  }

  pos = string_entrada.find(".txt");
  if (pos != std::string::npos) {
    string_entrada.erase(pos, 4); // 4 is the length of ".txt"
  }

  //LE DENTRO TXT
  std::string file_path = argv[1];
  std::ifstream file(file_path);
  std::vector<int> numbers;
  int number;
  while (file >> number) {
    numbers.push_back(number);
  }
  file.close();


  std::cout << "Quicksort: " << string_entrada << " Execução: " << argv[2] << std::endl;
  // Inicia a medição de tempo
  auto start = std::chrono::high_resolution_clock::now();
  ///////////////////////////////////////////////////////
  
  
  





  


  
  
  ///////////////////////////////////////////////////////
  // Finaliza a medição de tempo
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration = end - start;
  std::cout << "Tempo " << duration.count() << " segundos" << std::endl;

  /*/ Output the numbers to verify
  for (int num : numbers) {
    std::cout << num << "\n";
  }
  /*/

  // ESCREVE CSV
  std::ofstream outfile("output.csv", std::ios::app);
  outfile << "QUICKSORT" << ";" << string_entrada << ";" << duration.count() << ";" << argv[2] << std::endl;
  outfile.close();

  return 0;
}