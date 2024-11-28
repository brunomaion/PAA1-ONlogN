#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

void heapify(int *Vet, int n, int i) {
    int largest = i;          // Inicializa o maior como a raiz
    int left = 2 * i + 1;      // Filho à esquerda
    int right = 2 * i + 2;     // Filho à direita

    // Se o filho à esquerda é maior que a raiz
    if (left < n && Vet[left] > Vet[largest]) {
        largest = left;
    }

    // Se o filho à direita é maior que o maior atual
    if (right < n && Vet[right] > Vet[largest]) {
        largest = right;
    }

    // Se o maior não é a raiz
    if (largest != i) {
        std::swap(Vet[i], Vet[largest]);
        // Recursivamente ajusta o sub-heap afetado
        heapify(Vet, n, largest);
    }
}

void heapSort(int *Vet, int n) {
    // Constrói o heap (reorganiza o array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(Vet, n, i);
    }

    // Extrai elementos do heap um por um
    for (int i = n - 1; i > 0; i--) {
        // Move a raiz atual para o fim
        std::swap(Vet[0], Vet[i]);
        // Chama heapify no heap reduzido
        heapify(Vet, i, 0);
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


  std::cout << "HeapSort: " << string_entrada << " Execução: " << argv[2] << std::endl;
  // Inicia a medição de tempo
  auto start = std::chrono::high_resolution_clock::now();
  ///////////////////////////////////////////////////////


  
  int* arr = numbers.data();
  heapSort(arr, numbers.size());



  
  ///////////////////////////////////////////////////////
  // Finaliza a medição de tempo
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration = end - start;
  std::cout << "Tempo " << duration.count() << " segundos" << std::endl;

  /*/ Output the numbers to verify
  for (int num : numbers) {
    std::cout << num << " ";
  }
  std::cout << "\n";
  /*/

  // ESCREVE CSV
  std::ofstream outfile("output.csv", std::ios::app);
  outfile << "HEAPSORT" << ";" << string_entrada << ";" << duration.count() << ";" << argv[2] << std::endl;
  outfile.close();

  return 0;
}