#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  cout << "Ruth Higgason\n";
  cout << "Lab #6: Matrix Manipulation\n";
  
  //open file
  ifstream matrixFile;
  matrixFile.open ("matrix_input.txt");

  //get matrix size and change to int
  string input;
  getline(matrixFile, input);
  int matrixLen = stoi(input);

  //make matrixs
  int matrix1[matrixLen][matrixLen];
  int matrix2[matrixLen][matrixLen];
  for (int i = 0; i < matrixLen; i++) {
    for (int j = 0; j < matrixLen; j++){
      matrixFile >> matrix1[i][j];
    }
  }
  for (int i = 0; i < matrixLen; i++) {
    for (int j = 0; j < matrixLen; j++){
      matrixFile >> matrix2[i][j];
    }
  }

  //print matrix out
  cout << "Matrix 1: \n";
  for (int i = 0; i < matrixLen; i++) {
    for (int j = 0; j < matrixLen; j++){
      printf("%-3d", matrix1[i][j]);
    }
    cout << "\n";
  }
  cout << "\n";
  cout << "Matrix 2: \n";
  for (int i = 0; i < matrixLen; i++) {
    for (int j = 0; j < matrixLen; j++){
      printf("%-3d", matrix2[i][j]);
    }
    cout << "\n";
  }
  cout << "\n";

  //add two matrix together
  int addMatrix[matrixLen][matrixLen];
  for (int i = 0; i < matrixLen; i++) {
    for (int j = 0; j < matrixLen; j++){
      addMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }
  cout << "Matrix Sum (A + B):\n";
  for (int i = 0; i < matrixLen; i++) {
    for (int j = 0; j < matrixLen; j++){
      printf("%-3d", addMatrix[i][j]);
    }
    cout << "\n";
  }
  cout << "\n";

  //multiply two matrix together
  int multiMatrix[matrixLen][matrixLen];
  for (int i = 0; i < matrixLen; i++) {
    for (int j = 0; j < matrixLen; j++){
      int sum = 0;
      for (int k = 0; k < matrixLen; k++) {
        sum += matrix1[i][k] * matrix2[k][j];
      }
      multiMatrix[i][j] = sum;
    }
  }
  cout << "Matrix Product (A * B):\n";
  for (int i = 0; i < matrixLen; i++) {
    for (int j = 0; j < matrixLen; j++){
      printf("%-4d", multiMatrix[i][j]);
    }
    cout << "\n";
  }
  cout << "\n";
  
  //subtract two matrix together
  int subMatrix[matrixLen][matrixLen];
  for (int i = 0; i < matrixLen; i++) {
    for (int j = 0; j < matrixLen; j++){
      subMatrix[i][j] = matrix1[i][j] - matrix2[i][j];
    }
  }
  cout << "Matrix Difference (A - B): \n";
  for (int i = 0; i < matrixLen; i++) {
    for (int j = 0; j < matrixLen; j++){
      printf("%-3d", subMatrix[i][j]);
    }
    cout << "\n";
  }
  cout << "\n";
  matrixFile.close();
}