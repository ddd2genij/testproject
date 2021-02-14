#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>

namespace matroperating
{
    void inputmatr(int**, int, int, int);
}

void matroperating::inputmatr(int** matrix, int sizematrix_row, int sizematrix_column, int number)
{
    std::cout << "Started reading the values of the "<<number<<" matrix\n";
    for (int i = 0; i < sizematrix_row; i++)
    {
        matrix[i] = new int[sizematrix_column];
        for (int j = 0; j < sizematrix_column; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
    std::cout << "finished reading the values of the "<<number<<" matrix\n\n";
}


int main()
{
    int sizematrix_column, sizematrix_row;
    SetConsoleOutputCP(CP_UTF8);

    std::cout << "Please, sequentially enter kol colum of matrix and kol row\n";
    std::cin >> sizematrix_column >> sizematrix_row;
    while ((sizematrix_column <= 0) or (sizematrix_row <= 0))
    {
        std::cout << "Entered values must be > 0\n";
        std::cin >> sizematrix_column >> sizematrix_row;
    }

    std::cout << "Plese enter values of two matrix(Entered values must be > 0)\n";
    int** matrix1 = new int* [sizematrix_row];
    matroperating::inputmatr(matrix1, sizematrix_row, sizematrix_column, 1);
    int** matrix2 = new int* [sizematrix_row];
    matroperating::inputmatr(matrix2, sizematrix_row, sizematrix_column, 2);

    std::cout << "Please enter name of file to output values\n";
    std::string filename;
    std::cin >> filename;
    if (filename.size()<4)
    {
        filename += ".txt\0";
    }
    else if (filename.substr(filename.size()-4) != ".txt")
    {
        filename += ".txt\0";
    }
    std::ofstream file;
    file.open(filename);

    if (file.is_open())
    {
        file << "first matrix\n";
        for (int i = 0; i < sizematrix_row; i++)
        {
            for (int j = 0; j < sizematrix_column; j++)
            {
                file << matrix1[i][j] << ' ';
            }
            file << "\n";
        }
        file << "\n";
        file << "Second matrix matrix\n";
        for (int i = 0; i < sizematrix_row; i++)
        {
            for (int j = 0; j < sizematrix_column; j++)
            {
                file << matrix2[i][j] << ' ';
            }
            file << "\n";
        }
        file << "\n";
        file << "Sum matrix matrix\n";
        for (int i = 0; i < sizematrix_row; i++)
        {
            for (int j = 0; j < sizematrix_column; j++)
            {
                file << matrix2[i][j]+ matrix1[i][j] << ' ';
            }
            file << "\n";
            delete[] matrix1[i];
            delete[] matrix2[i];
        }
        std::cout << "Successfully recorded\n";
    }
    else
    {
        std::cout << "Error while opening file\n";
        return 0;
    }

    file.close();
    delete matrix1;
    delete matrix2;
    char endprogram;
    std::cout << "Enter any symbol to finish\n";
    std::cin >> endprogram;
    return 1;
}

