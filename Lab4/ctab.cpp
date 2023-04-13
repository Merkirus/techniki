#include "ctab.h"

CTab::CTab()
{
  pi_tab = new int[DEF_TAB_SIZE];
  i_size = DEF_TAB_SIZE;
}

CTab::CTab(const CTab &cOther)
{
  v_copy(cOther);
  std::cout << "Copy ";
}

CTab::CTab(CTab &&cOther)
{
  pi_tab = cOther.pi_tab;
  i_size = cOther.i_size;

  cOther.pi_tab = NULL;

  std::cout << "MOVE ";
}

CTab CTab::operator=(const CTab &cOther)
{
  if (pi_tab)
    delete pi_tab;
  v_copy(cOther);
  std::cout << "op= ";
  return *this;
}

CTab& CTab::operator=(CTab &&cOther)
{
  if (pi_tab)
    delete pi_tab;

  pi_tab = cOther.pi_tab;
  i_size = cOther.i_size;

  cOther.pi_tab = NULL;

  std::cout << "op=MOVE " ;

  return *this;
}

CTab::~CTab()
{
  if (pi_tab)
    delete pi_tab;
  std::cout << "Destr ";
}

bool CTab::bSetSize(int iNewSize)
{
  if (iNewSize < 1)
    return false;

  int *pi_temp = pi_tab;
  pi_tab = new int[iNewSize];

  int temp_size = iNewSize < i_size ? iNewSize : i_size;

  for (int i = 0; i < temp_size; ++i)
    pi_tab[i] = pi_temp[i];

  i_size = iNewSize;

  if (pi_temp)
    delete pi_temp;

  return true;
}

int CTab::iGetSize()
{
  return i_size;
}

void CTab::v_copy(const CTab &cOther)
{
  pi_tab = new int[cOther.i_size];
  i_size = cOther.i_size;
  for (int i = 0; i < cOther.i_size; ++i)
    pi_tab[i] = cOther.pi_tab[i];
}
