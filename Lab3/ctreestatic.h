#ifndef CTREESTATIC_H

#include <vector>
#include <iostream>

// Gdyby nie testy zrobiłbym całą private
class CNodeStatic
{
public:
    CNodeStatic();
    ~CNodeStatic();
    void vSetValue(int iNewVal);
    int iGetChildrenNumber();
    void vAddNewChild();
    void vAddNewChild(CNodeStatic *pcNewNode);
    void vRemoveChild(CNodeStatic *pcChild);
    CNodeStatic *pcGetChild(int iChildOffset);
    CNodeStatic *pcGetParent();
    void vPrint();
    void vPrintAllBelow();
    void vPrintUp();
private:
    std::vector<CNodeStatic> v_children;
    CNodeStatic *pc_parent_node;
    int i_val;
    void vFixParents();
};

class CTreeStatic
{
public:
    CTreeStatic();
    ~CTreeStatic();
    CNodeStatic *pcGetRoot();
    bool bMoveSubtree(CNodeStatic *pcParentNode, CNodeStatic *pcNewChildNode);
    void vPrintTree();
private:
    CNodeStatic c_root;
};
#endif // CTREESTATIC_H
