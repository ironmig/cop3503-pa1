/* MagicSquare can generate a valid magic square of size n
 * n must be odd and between 3 and 15
 * 
 * 
 */
class MagicSquare
{
  private:
    const int size;
    int** square;
  public:
    MagicSquare(int n);
    void fillSquare(int** arr);
    const int getSize();
};
/* Wrapper class to test MagicSquare
 * internally, creates a MagicSquare with n = size
 * runAllTests will print out the square + the sums
 * also uses original square to generate 2 more valid MagicSquares
 */
class MagicSquareTester
{
  private:
    MagicSquare ms;
    int** array;
    int n;
    void fillArray();
    void printArray();
    void printRowSums();
    void printColumnSums();
    void printDiagonalSums();
    void rotateArray();
    void runTest();
  public:
    MagicSquareTester(int size);
    ~MagicSquareTester();
    void runAllTests();
};
