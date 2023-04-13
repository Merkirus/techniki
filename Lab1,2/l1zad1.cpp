#include <iostream>

#define WARTOŚĆ_TABLICY 34
#define ROZMIAR_TABLICY 15

void v_alloc_table_fill_34(int iSize);

int main(int argc, char const *argv[])
{
    v_alloc_table_fill_34(ROZMIAR_TABLICY);
    return 0;
}

void v_alloc_table_fill_34(int iSize)
{
    if (iSize < 1) {
        /* nie powinna nic wypisywac ale w przypadku
        tak malego programu jest ok */
        std::cout << "Nieprawidłowy rozmiar tablicy";
        return;
    }

    int *p_tablica;

    p_tablica = new int[iSize];

    for (int it = 0; it < iSize; ++it)
        p_tablica[it] = WARTOŚĆ_TABLICY;

    for (int it = 0; it < iSize; ++it)
        std::cout << p_tablica[it] << " ";

    delete [] p_tablica;
}
