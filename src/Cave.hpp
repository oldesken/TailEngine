#include <iostream>
#include <random>

int numberOfAdjacentCells(int** grid, int posX, int posY)
{
    int result = 0;
    for (int i = posY - 1; i <= posY + 1; i++)
    {
        for (int j = posX - 1; j <= posX + 1; j++)
        {
            if (grid[i][j] == 1 && (i != posY || j != posX))
            {
                result += 1;
            }
        }

    }
	return result;
}

int** generateCave(int length, int width, int fill, int clutch, int cicles)
{
    
    // Reserva espaco na memoria para um grid
    int** grid;
    grid = new int*[length];
    for (int i = 0; i < length; i++) grid[i] = new int[width];
    
    // Preenche o grid aleatoriamente e com densidade dada pelo parametro fill
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Decide se a celula vai ter valor 0 ou 1
            if (std::rand() % 100 < fill) grid[i][j] = 1;
            else grid[i][j] = 0;
        }
    }


    
    for (int iteration = 0; iteration < cicles; iteration++)
    {
        for (int i = 1; i < length - 1; i++)
        {
            for (int j = 1; j < width - 1; j++)
            {
                int vizinhos = numberOfAdjacentCells(grid, j, i);
                if (vizinhos > clutch) grid[i][j] = 1;
                else grid[i][j] = 0;
            }
        }
    }

    return grid;
}