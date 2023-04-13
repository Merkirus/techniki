#ifndef CTREEDYNAMIC_H

#include <iostream>
#include <vector>

class CNodeDynamic
{
public:
    CNodeDynamic();
    ~CNodeDynamic();
    void vSetValue(int iNewVal);
    int iGetChildrenNumber();
    void vAddNewChild();
    void vAddNewChild(CNodeDynamic *pcNewNode);
    void vRemoveChild(CNodeDynamic *pcChild);
    CNodeDynamic *pcGetChild(int iChildOffset);
    CNodeDynamic *pcGetParent();
    void vPrint();
    void vPrintAllBelow();
    int iGetValue();
    void vNodeDepthPair(int iDepth, std::vector< std::pair<int, int> >& rows);
private:
    std::vector<CNodeDynamic *> v_children;
    CNodeDynamic *pc_parent_node;
    int i_val;
};

class CTreeDynamic
{
public:
    CTreeDynamic();
    ~CTreeDynamic();
    CNodeDynamic *pcGetRoot();
    bool bMoveSubtree(CNodeDynamic *pcParentNode, CNodeDynamic *pcNewChildNode);
    void vPrintTree();
    void vPrintTreeRows();
private:
    CNodeDynamic *pc_root;
};

#endif
