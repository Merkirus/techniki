#ifndef CTABLE_H
#define CTABLE_H

#include <string>
#include <iostream>

#define BASIC_TABLE_LENGTH 20
#define BASIC_TABLE_NAME "Base"

class CTable
{
public:
    CTable();
    CTable(std::string sName, int iTableLen);
    CTable(CTable &pcOther);
    ~CTable();
    void operator=(const CTable &pcOther);
    CTable operator+(CTable &pcOther);
    void operator--(int);
    void vSetName(std::string sName);
    void vSetValueAt(int iOffset, int iNewVal);
    bool bSetNewSize(int iTableLen);
    CTable *pcClone();
    void vPrint();
    int iTable_length();
private:
    std::string s_name;
    int table_length;
    int *entries;
};

#endif
