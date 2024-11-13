#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

void QuickSort(int *Vet, int left, int right) {
    int i = left, j = right;
    int pivo = Vet[(left + right) / 2];
    int y;

    // Loop principal do QuickSort
    while (i <= j) {
        // Encontra o próximo elemento à esquerda que deve ser trocado
        while (Vet[i] < pivo && i < right) {
            i++;
        }
        // Encontra o próximo elemento à direita que deve ser trocado
        while (Vet[j] > pivo && j > left) {
            j--;
        }
        // Troca os elementos e ajusta os índices
        if (i <= j) {
            y = Vet[i];
            Vet[i] = Vet[j];
            Vet[j] = y;
            i++;
            j--;
        }
    }

    // Chamada recursiva para a sublista à esquerda
    if (j > left) {
        QuickSort(Vet, left, j);
    }

    // Chamada recursiva para a sublista à direita
    if (i < right) {
        QuickSort(Vet, i, right);
    }
}


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


  std::cout << "QuickSort: " << string_entrada << " Execução: " << argv[2] << std::endl;
  // Inicia a medição de tempo
  auto start = std::chrono::high_resolution_clock::now();
  ///////////////////////////////////////////////////////


  
  int* arr = numbers.data();
  QuickSort(arr, 0, numbers.size() - 1);



  
  ///////////////////////////////////////////////////////
  // Finaliza a medição de tempo
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration = end - start;
  std::cout << "Tempo " << duration.count() << " segundos" << std::endl;

  // Output the numbers to verify
  for (int num : numbers) {
    std::cout << num << " ";
  }
  std::cout << "\n";
  //

  // ESCREVE CSV
  std::ofstream outfile("output.csv", std::ios::app);
  outfile << "QUICKSORT" << ";" << string_entrada << ";" << duration.count() << ";" << argv[2] << std::endl;
  outfile.close();

  return 0;
}