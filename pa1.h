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
