#include "ctable.h"

CTable::CTable()
{
    this->s_name = BASIC_TABLE_NAME;
    std::cout << "bezp: " << this->s_name << std::endl;
    this->entries = new int[BASIC_TABLE_LENGTH];
    this->table_length = BASIC_TABLE_LENGTH;
}

CTable::CTable(std::string sName, int iTableLen)
{
    this->s_name = sName;
    std::cout << "parametr: " << this->s_name << std::endl;
    this->entries = new int[iTableLen];
    this->table_length = iTableLen;
}

CTable::CTable(CTable &pcOther)
{
    this->s_name = pcOther.s_name + "_copy";
    this->entries = new int[pcOther.table_length];
    this->table_length = pcOther.table_length;
    for (int it = 0; it < table_length; ++it)
        this->entries[it] = pcOther.entries[it];
    std::cout << "kopiuj: " << this->s_name << std::endl;
}

CTable::CTable(CTable &&pcOther)
{
    this->s_name = pcOther.s_name + "_move";
    v_move(pcOther);
    std::cout << "MOVE: " << this->s_name << std::endl;
}

CTable::~CTable()
{
    std::cout << "usuwam: " << this->s_name << std::endl;
    if (entries)
        delete [] entries;
}

CTable CTable::operator=(const CTable &pcOther)
{
    this->table_length = pcOther.table_length;

    if (this->entries)
      delete [] this->entries;

    this->entries = new int[table_length];
    
    for (int i = 0; i < table_length; ++i)
        this->entries[i] = pcOther.entries[i];

    std::cout << this->s_name << "op= " << pcOther.s_name << std::endl;

    return *this;
}

CTable CTable::operator+(const CTable &pcOther)
{
    CTable result;
    int size;

    size = this->table_length + pcOther.table_length;

    result = *this;

    result.bSetNewSize(size);

    for (int i = table_length; i < size; ++i)
        result.vSetValueAt(i, pcOther.entries[i - table_length]);

    return result;
}

CTable& CTable::operator=(CTable &&pcOther)
{
  if (this->entries)
    delete [] this->entries;

  v_move(pcOther);

  std::cout << this->s_name << "op=MOVE " << pcOther.s_name << std::endl;

  return *this;
}

CTable& CTable::operator+(CTable &&pcOther)
{
  int size = this->table_length + pcOther.table_length;

  bSetNewSize(size);
  
  for (int i = size - pcOther.table_length; i < size; ++i)
    this->entries[i] = pcOther.entries[i - size + pcOther.table_length];

  return *this;
}

void CTable::operator--(int)
{   
    if (this->table_length > 0)
        this->table_length = this->table_length - 1;
}

void CTable::vSetName(std::string sName)
{
    this->s_name = sName;
}

void CTable::vSetValueAt(int iOffset, int iNewVal)
{
    if (iOffset >= this->table_length || iOffset < 0)
        return;

    this->entries[iOffset] = iNewVal;
}

bool CTable::bSetNewSize(int iTableLen)
{   
    if (iTableLen < 1)
        return false;

    int *buffer;
    int size;

    buffer = new int[iTableLen];
    size = iTableLen > table_length ? table_length : iTableLen;

    for (int i = 0; i < size; ++i)
        buffer[i] = this->entries[i];

    delete [] this->entries;

    this->entries = new int[iTableLen];

    for (int i = 0; i < size; ++i)
        this->entries[i] = buffer[i];

    delete [] buffer;

    this->table_length = iTableLen;

    return true;
}

CTable *CTable::pcClone()
{
    CTable *copy;

    copy = new CTable(*this);

    return copy;
}

void CTable::vPrint()
{
    std::cout << "Wartości " << this->s_name << std::endl;
    for (int i = 0; i < this->table_length; ++i)
        std::cout << this->entries[i] << " ";
    std::cout << std::endl;
}

int CTable::iTable_length()
{
    return table_length;
}

void CTable::v_move(CTable &pcOther)
{
    this->entries = pcOther.entries;
    this->table_length = pcOther.table_length;
    pcOther.entries = NULL;
}