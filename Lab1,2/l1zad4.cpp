#include "ctable.h"
#include <vector>
#include <iterator>

#define DLUGOSC_POCZATKOWA 15
#define DLUGOSC_KOPII 16
#define DLUGOSC_PTR 17
#define NAZWA_CTABLE "Test"

void v_mod_tab(CTable *pcTab, int iNewSize);
void v_mod_tab(CTable cTab, int iNewSize);

int main(int argc, char const *argv[])
{
    /* TEST FUNKCJI */
    CTable *pTable;

    pTable = new CTable(NAZWA_CTABLE, DLUGOSC_POCZATKOWA);
    std::cout << "Długość CTable przed funkcjami: " << pTable->iTable_length() << std::endl;
    v_mod_tab(*pTable, DLUGOSC_KOPII);
    v_mod_tab(pTable, DLUGOSC_PTR);
    std::cout << "Długość CTable po funkcjach: " << pTable->iTable_length() << std::endl;

    delete pTable;

    /* TEST ALOKACJI */

    int SIZE = 20;

    CTable* pTablica[SIZE];

    for (int i = 0; i < SIZE; ++i)
        pTablica[i] = new CTable();

    for (int i = 0; i < SIZE; ++i)
        delete pTablica[i];
    
    CTable tablica[SIZE];

    return 0;
}

void v_mod_tab(CTable *pcTab, int iNewSize)
{
    pcTab->bSetNewSize(iNewSize);
    std::cout << "Długość CTable w funkcji z ptr: " << pcTab->iTable_length() << std::endl;
}

void v_mod_tab(CTable cTab, int iNewSize)
{
    cTab.bSetNewSize(iNewSize);
    std::cout << "Długość CTable w funkcji z kopiowaniem: " << cTab.iTable_length() << std::endl;
}
