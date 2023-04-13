#include "ctable.h"

int main(int argc, char const *argv[])
{
    CTable c_tab_0, c_tab_1;
    c_tab_0.bSetNewSize(6);
    c_tab_1.bSetNewSize(4);

    c_tab_0 = c_tab_1;
    c_tab_1.vSetValueAt(2, 123);
    c_tab_0.vPrint();
    c_tab_1.vPrint();

    CTable c_tab_2;
    c_tab_2 = c_tab_0 + c_tab_1;
    c_tab_2.vPrint();

    std::cout << "\n";

    CTable c_tab_3;
    c_tab_3.bSetNewSize(3);
    c_tab_3.vSetValueAt(0,1);
    c_tab_3.vSetValueAt(1,2);
    c_tab_3.vSetValueAt(2,3);
    c_tab_3--;
    c_tab_3--;

    c_tab_3.vPrint();

    return 0;
}
