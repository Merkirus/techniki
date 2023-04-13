#include "ctreestatic.h"

CTreeStatic::CTreeStatic()
{

}

CTreeStatic::~CTreeStatic()
{

}

CNodeStatic* CTreeStatic::pcGetRoot()
{
    return &c_root;
}

bool CTreeStatic::bMoveSubtree(CNodeStatic *pcParentNode, CNodeStatic *pcNewChildNode)
{
    CNodeStatic temp = *pcNewChildNode;
    pcParentNode->vAddNewChild(&temp);
    if (pcNewChildNode->pcGetParent())
        pcNewChildNode->pcGetParent()->vRemoveChild(pcNewChildNode);
    return true;
}

void CTreeStatic::vPrintTree()
{
    c_root.vPrintAllBelow();
}

CNodeStatic::CNodeStatic()
{
    i_val = 0;
    pc_parent_node = NULL;
}

CNodeStatic::~CNodeStatic()
{
    // Nie ma leaków, ponieważ root jest statycznie,
    // dzieci są zarządzane przez vector
}

void CNodeStatic::vSetValue(int iNewVal)
{
    i_val = iNewVal;
}

int CNodeStatic::iGetChildrenNumber()
{
    return v_children.size();
}

void CNodeStatic::vAddNewChild()
{
    CNodeStatic child;
    child.pc_parent_node = this;
    v_children.push_back(child);

    for (int i = 0; i < v_children.size(); ++i)
        v_children.at(i).vFixParents();
}

void CNodeStatic::vAddNewChild(CNodeStatic *pcNewNode)
{
    pcNewNode->pc_parent_node = this;
    v_children.push_back(*pcNewNode);

    for (int i = 0; i < v_children.size(); ++i)
        v_children.at(i).vFixParents();
}

void CNodeStatic::vRemoveChild(CNodeStatic *pcChild)
{
    int index;
    index = -1;

    bool run = true;

    for (int i = 0; i < v_children.size() && run; ++i) {
        if (&(v_children.at(i)) == pcChild) {
            index = i;
            run = false;
        }
    }

    if (index == -1)
       return;

    v_children.erase(v_children.begin() + index - 1);

    for (int i = 0; i < v_children.size(); ++i)
        v_children.at(i).vFixParents();
}

CNodeStatic* CNodeStatic::pcGetChild(int iChildOffset)
{
    if (iChildOffset < 0 || iChildOffset > v_children.size() - 1)
        return NULL;

   CNodeStatic *pResult = &(v_children.at(iChildOffset)); 

    return pResult;
}

CNodeStatic* CNodeStatic::pcGetParent()
{
    return pc_parent_node;
}

void CNodeStatic::vPrint()
{
    std::cout << " " << i_val;
}

void CNodeStatic::vPrintAllBelow()
{
    vPrint();
    for (int i = 0; i < v_children.size(); ++i)
        v_children.at(i).vPrintAllBelow();
}

void CNodeStatic::vPrintUp()
{
    vPrint();
    if (pc_parent_node)
        pc_parent_node->vPrintUp();
}

void CNodeStatic::vFixParents()
{
    for (int i = 0; i < v_children.size(); ++i) {
        v_children.at(i).pc_parent_node = this;
        v_children.at(i).vFixParents();
    }
}