#ifndef CTAB_H
#define CTAB_H

#include <iostream>

#define DEF_TAB_SIZE 10

class CTab
{
  public:
    CTab();
    CTab(const CTab &cOther);
    CTab(CTab &&cOther);
    CTab operator=(const CTab &cOther);
    CTab& operator=(CTab &&cOther);
    ~CTab();
    bool bSetSize(int iNewSize);
    int iGetSize();
  private:
    void v_copy(const CTab &cOther);
    int *pi_tab;
    int i_size;
};

#endif 
