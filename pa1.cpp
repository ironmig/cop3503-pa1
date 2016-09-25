#include <iostream>
#include "pa1.h"
#include <stdexcept>
#include <stdio.h>
using namespace std;
/* Constructs a magic square with size n
 * Precondition: n is odd and between 3 and 15
 * Throws std::invalid_argument if n is invalid
 */
MagicSquare::MagicSquare(int n) : size(n)
{
  if (n % 2 != 1) throw invalid_argument("n must be odd");
  else if (n < 3 || n > 15) throw invalid_argument("n must be between 3 and 15");
}
/* Precondition: arr is an n by n 2-d array with all elements == 0
 * Fills the array with the correct magic square numbers
 * Uses the Siamese Method as described on
 * https://en.wikipedia.org/wiki/Magic_square
 */
void MagicSquare::fillSquare(int** arr)
{
  //Set the first element (row 1, middle col) to 1
  int row = 0;
  int col = size/2;
  int lastRow = row;
  int lastCol = col;
  arr[row][col] = 1;
  
  //Ensure runs once for each array element, besides one already set
  int num = 2;
  for (int i = 0; i < (size*size) - 1; i ++)
  {
    row -= 1;
    col += 1;
    if (row < 0) row = size -1;
    if (col >= size) col = 0;
    if (arr[row][col] != 0) 
    {
      row = lastRow + 1;
      col = lastCol;
    }
    if (row >= size) row = 0;
    if (col < 0 ) col = size-1;
    arr[row][col] = num;
    num++;
    lastRow = row;
    lastCol = col;
  }
}
/* Returns the size of the magic square,
 * Useful to generate an array of correct size to pass to fillSquare
 */ 
const int MagicSquare::getSize()
{
  return size;
}

/* Generates a MagicSquareTester with n = size
 * precondition: size is a valid size for a magic square
 */
MagicSquareTester::MagicSquareTester(int size) :
  ms(size),
  n(size)
{
  //Initilize array
  array = new int*[size];
  for (int i = 0; i < n; i++)
  {
    array[i] = new int[n];
    for (int j = 0; j < n; j++)
    {
      array[i][j] = 0;
    }
  }
}
MagicSquareTester::~MagicSquareTester()
{
  delete array; //Ensures array is cleared from memory on object destruction
}
void MagicSquareTester::fillArray()
{
  ms.fillSquare(array);
}
// Rotates generated magic square array to create additional magic squares
void MagicSquareTester::rotateArray()
{
  for(int r = 0; r < n; r++)
    for(int c = r; c < n; c++) 
      swap(array[r][c], array[c][r]);
      
  for(int r = 0; r < n; r++)
      for(int c =0; c < n/2; c++)
        swap(array[r][c], array[r][n-c-1]);
}
void MagicSquareTester::printArray()
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%4u",array[i][j]);
    }
    cout << endl;
  }   
}
void MagicSquareTester::printRowSums()
{
  //Row each row
  printf("%-20s","Sum of rows:");
  for (int i = 0; i < n; i++)
  {
    int sum = 0;
    //Add each column in this row to the sum
    for (int j = 0; j < n; j++)
    {
      sum += array[i][j];
      
    }
    printf("%6u",sum);
  }
  cout << endl;
}
void MagicSquareTester::printColumnSums()
{
  //For each column
  printf("%-20s","Sum of columns:");
  for (int i = 0; i < n; i++)
  {
    int sum = 0;
    //Add each row in this column to the sum
    for (int j = 0; j < n; j++)
    {
      sum += array[j][i];
      
    }
    printf("%6u",sum);
  }
  cout << endl;  
}
void MagicSquareTester::printDiagonalSums()
{
  //For each row
  printf("%-20s","Sum of diagonals:");
  int sum = 0;
  //Sum the top-left to bottom-right diagnal
  for (int i = 0; i < n; i++)
  {
    sum += array[i][i];

  }
  printf("%6u",sum);
  
  sum = 0;
  //sum the bottom-left to top-right diagonal
  for (int i = 0, j = n-1; i < n; i++,j--)
  {
    sum += array[i][j];

  }
  printf("%6u",sum);
  cout << endl;
}
//Prints all debug info for an already filled array
void MagicSquareTester::runTest()
{
  printArray();
  printRowSums();
  printColumnSums();
  printDiagonalSums();
}
// Prints out 3 valid magic squares and their sums
void MagicSquareTester::runAllTests()
{
  fillArray();
  cout << "Magic Square #1: " << endl;
  runTest();

  cout << endl;
  rotateArray();
  cout << "Magic Square #2: " << endl;
  runTest();
  
  cout << endl;
  rotateArray();
  cout << "Magic Square #2: " << endl;
  runTest();
}

// Gets size of magic square from cin then runs tests
int main()
{
  cout << "Enter Square Size (must be odd): ";
  int size;
  cin >> size;
  MagicSquareTester test(size);
  test.runAllTests();
}
