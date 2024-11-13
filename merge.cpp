#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>



// Exemplo de implementação da função merge
void merge(int *Vet, int comeco, int meio, int fim) {
    int i, j, k;
    int n1 = meio - comeco + 1;
    int n2 = fim - meio;

    // Vetores temporários para armazenar as duas metades
    int *esquerda = new int[n1];
    int *direita = new int[n2];

    // Copia os dados para os vetores temporários
    for (i = 0; i < n1; i++)
        esquerda[i] = Vet[comeco + i];
    for (j = 0; j < n2; j++)
        direita[j] = Vet[meio + 1 + j];

    // Mescla os vetores temporários de volta no vetor original
    i = 0;
    j = 0;
    k = comeco;
    while (i < n1 && j < n2) {
        if (esquerda[i] <= direita[j]) {
            Vet[k] = esquerda[i];
            i++;
        } else {
            Vet[k] = direita[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes, se houver
    while (i < n1) {
        Vet[k] = esquerda[i];
        i++;
        k++;
    }
    while (j < n2) {
        Vet[k] = direita[j];
        j++;
        k++;
    }

    // Libera a memória alocada para os vetores temporários
    delete[] esquerda;
    delete[] direita;
}

void MergeSort(int *Vet, int comeco, int fim) {
    if (comeco < fim) {
        int meio = (fim + comeco) / 2;
        MergeSort(Vet, comeco, meio);
        MergeSort(Vet, meio + 1, fim);
        merge(Vet, comeco, meio, fim);  // Função de mesclagem das duas metades
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


  std::cout << "MergeSort: " << string_entrada << " Execução: " << argv[2] << std::endl;
  // Inicia a medição de tempo
  auto start = std::chrono::high_resolution_clock::now();
  ///////////////////////////////////////////////////////


  
  int* arr = numbers.data();
  MergeSort(arr, 0, numbers.size() - 1);



  
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
  outfile << "MERGESORT" << ";" << string_entrada << ";" << duration.count() << ";" << argv[2] << std::endl;
  outfile.close();

  return 0;
}