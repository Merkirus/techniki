#include "ctreedynamic_temp.h"
#include <vector>
#include <string>

int main (int argc, char *argv[])
{
    CTreeDynamicT<int> tree;
    tree.pcGetRoot()->vSetValue(1);
    tree.pcGetRoot()->vAddNewChild();
    tree.pcGetRoot()->vAddNewChild();
    tree.pcGetRoot()->pcGetChild(0)->vSetValue(2);
    tree.pcGetRoot()->pcGetChild(1)->vSetValue(3);
    tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(4);
    
    tree.vPrintTree();
    std::cout << "\n";
    std::cout << tree.tSum();
    std::cout << "\n";

    CTreeDynamicT<double> tree2;
    tree2.pcGetRoot()->vSetValue(2.5);
    tree2.pcGetRoot()->vAddNewChild();
    tree2.pcGetRoot()->vAddNewChild();
    tree2.pcGetRoot()->pcGetChild(0)->vSetValue(3.8);
    tree2.pcGetRoot()->pcGetChild(1)->vSetValue(4.1);
    tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(6.0);
    
    tree2.vPrintTree();
    std::cout << "\n";
    std::cout << tree2.tSum();
    std::cout << "\n";

    CTreeDynamicT<std::string> tree3;
    tree3.pcGetRoot()->vSetValue("1");
    tree3.pcGetRoot()->vAddNewChild();
    tree3.pcGetRoot()->vAddNewChild();
    tree3.pcGetRoot()->pcGetChild(0)->vSetValue("2");
    tree3.pcGetRoot()->pcGetChild(1)->vSetValue("3");
    tree3.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    tree3.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue("4");
    
    tree3.vPrintTree();
    std::cout << "\n";
    std::cout << tree3.tSum();
    std::cout << "\n";

    return 0;
}
