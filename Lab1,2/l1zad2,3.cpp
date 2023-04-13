#include <iostream>

#define SIZEX 5
#define SIZEY 3
#define SIZEZ 2

bool b_alloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY);
bool b_dealloc_table_2_dim(int **piTable, int iSizeX, int iSizeY);

bool b_alloc_table_3_dim(int ****piTable, int iSizeX, int iSizeY, int iSizeZ);

int main(int argc, char const *argv[])
{
    int **pi_table;
    int ***pi_table_3dim;

    std::cout << "Alokacja: " << b_alloc_table_2_dim(&pi_table, SIZEX, SIZEY)  << std::endl;
    
    std::cout << "Dealokacja: " << b_dealloc_table_2_dim(pi_table, SIZEX, SIZEY) << std::endl;

    std::cout << "Modyfikacja: " << b_alloc_table_3_dim(&pi_table_3dim, SIZEX, SIZEY, SIZEZ) << std::endl;

    return 0;
}

bool b_alloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY)
{
    if (iSizeX < 1 || iSizeY < 1)
        return false;

    *piTable = new int*[iSizeY];

    for (int it = 0; it < iSizeY; ++it)
        (*piTable)[it] = new int[iSizeX];

    return true;
}

// Można usunąć parametr iSizeX
bool b_dealloc_table_2_dim(int **piTable, int iSizeX, int iSizeY)
{
    if (!piTable || iSizeY < 1)
        return false;

    for (int it = 0; it < iSizeY; ++it)
        delete [] (piTable[it]);

    delete [] piTable;

    return true;
}

bool b_alloc_table_3_dim(int ****piTable, int iSizeX, int iSizeY, int iSizeZ)
{
    if (iSizeX < 1 || iSizeY < 1 || iSizeZ < 1)
        return false;

    *piTable = new int**[iSizeZ];

    for (int it = 0; it < iSizeZ; ++it)
        (*piTable)[it] = new int*[iSizeY];   

    for (int it = 0; it < iSizeZ; ++it)
        for (int it2 = 0; it2 < iSizeY; ++it2)
            ((*piTable)[it])[it2] = new int[iSizeX];

    return true;
}
