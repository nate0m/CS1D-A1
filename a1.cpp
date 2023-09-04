#include "algorithms.h"

int main(int argc, char* argv[]) {
  if(argc != 3) {
    std::cerr << argv[0] << " <file_path> <integer'1,2,3,4'>" << std::endl;
    return 1;
  }

  const char* filePath = argv[1];
  const int algChoice = std::atoi(argv[2]);

  int* numbers = nullptr;
  int lineCount = 0;
  int num = 0;
  std::string line;

  std::ifstream inFile;
  inFile.open(filePath);

  while(std::getline(inFile, line)) {
    lineCount++;
  }
  inFile.close();
  inFile.open(filePath);

  if(lineCount == 0) {
    std::cerr << "No numbers found in file." << std::endl;
    return 1;
  }

  numbers = new int[lineCount];

  for(int i = 0; i < lineCount; i++) {
    if(std::getline(inFile, line)) {
      try {
        num = std::stoi(line);
        numbers[i] = num;
      } catch(const std::invalid_argument& e) {
        std::cerr << "Error parsing line " << i + 1 << ": " << e.what() << std::endl;
      } catch(const std::out_of_range& e) { 
        std::cerr << "Error parsing line " << i + 1 << ": " << e.what() << std::endl; 
      }
    }
  }

  inFile.close();

  std::cout << "Number of lines in the file: " << lineCount << std::endl;

  /*
  std::cout << "The numbers in the array  before sorting are as follows:" << std::endl;
  for(int i = 0; i < lineCount; i++) 
    std::cout << numbers[i] << " ,";
  std::cout << std::endl;
  */

  switch(algChoice) {
    case 1:
      std::cout << "Algorithm Chosen: InsertionSort" << std::endl;
      InsertionSort(numbers, lineCount);
      break;
    case 2:
      std::cout << "Algorithm Chosen: BubbleSort" << std::endl; 
      BubbleSort(numbers, lineCount);
      break;
    case 3:
      std::cout << "Algorithm Chosen: MergeSort" << std::endl; 
      MergeSort(numbers, 0, lineCount - 1);
      break;
    case 4:
      std::cout << "Algorithm Chosen: HeapSort" << std::endl; 
      HeapSort(numbers, lineCount);
      break;
    case 5:
      std::cout << "Algorithm Chosen: QuickSort" << std::endl;
      QuickSort(numbers, 0, lineCount - 1);
      break;
    default:
      std::cerr << "Invalid algorithm choice. Change integer input to 1,2,3 or 4." << std::endl;
  }

  /*
  std::cout << "The numbers in the array after being sorted are as follows: " << std::endl;
  for(int i = 0; i < lineCount; i++) 
    std::cout << numbers[i] << " ,";
  std::cout << std::endl;
  */

  delete[] numbers;

  return 0;
}
