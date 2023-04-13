#include "ctreedynamic.h"

CNodeDynamic::CNodeDynamic()
{
    i_val = 0;
    pc_parent_node = NULL;
}

CNodeDynamic::~CNodeDynamic()
{
    for (int  i = 0; i < v_children.size(); ++i)
        delete v_children.at(i);
}

void CNodeDynamic::vSetValue(int iNewVal)
{
    i_val = iNewVal;
}

int CNodeDynamic::iGetChildrenNumber()
{
    return v_children.size();
}

void CNodeDynamic::vAddNewChild()
{
    CNodeDynamic *pcTemp;
    pcTemp = new CNodeDynamic();
    pcTemp->pc_parent_node = this;
    v_children.push_back(pcTemp);
}

void CNodeDynamic::vAddNewChild(CNodeDynamic *pcNewNode)
{
    CNodeDynamic *pcTemp;
    pcTemp = pcNewNode;
    pcTemp->pc_parent_node = this;
    v_children.push_back(pcTemp);
}

void CNodeDynamic::vRemoveChild(CNodeDynamic *pcChild)
{
    int index;
    index = -1;

    bool run = true;

    for (int i = 0; i < v_children.size() && run; ++i) {
        if (v_children.at(i) == pcChild) {
            index = i;
            run = false;
        }
    }

    if (index == -1)
        return;

    v_children.erase(v_children.begin() + index - 1);
}

CNodeDynamic* CNodeDynamic::pcGetChild(int iChildOffset)
{
    return v_children.at(iChildOffset);
}

CNodeDynamic* CNodeDynamic::pcGetParent()
{
    return pc_parent_node;
}

void CNodeDynamic::vPrint()
{
    std::cout << " " << i_val;
}

void CNodeDynamic::vPrintAllBelow()
{
    vPrint();
    for (int i = 0; i < v_children.size(); ++i)
        v_children.at(i)->vPrintAllBelow();
}

int CNodeDynamic::iGetValue()
{
    return this->i_val;
}

CTreeDynamic::CTreeDynamic()
{
    pc_root = new CNodeDynamic();
}

CTreeDynamic::~CTreeDynamic()
{
    delete pc_root;
}

CNodeDynamic* CTreeDynamic::pcGetRoot()
{
    return pc_root;
}

void CNodeDynamic::vNodeDepthPair(int iDepth, std::vector< std::pair<int, int> >& rows)
{
    std::pair<int, int> result(this->i_val, iDepth);
    rows.push_back(result);
    for (int i = 0; i < v_children.size(); ++i)
        v_children.at(i)->vNodeDepthPair(iDepth + 1, rows);
}

bool CTreeDynamic::bMoveSubtree(CNodeDynamic *pcParentNode, CNodeDynamic *pcNewChildNode)
{
    CNodeDynamic *pcTemp;
    pcTemp = pcNewChildNode;
    if (pcNewChildNode->pcGetParent())
        pcNewChildNode->pcGetParent()->vRemoveChild(pcNewChildNode);
    pcParentNode->vAddNewChild(pcTemp);
    return true;
}

void CTreeDynamic::vPrintTree()
{
    pc_root->vPrintAllBelow();
}

void CTreeDynamic::vPrintTreeRows()
{
    std::vector< std::pair<int, int> > rows;

    pc_root->vNodeDepthPair(0, rows);

    int max = 0;

    for (int i = 0; i < rows.size(); ++i) {
        if (rows.at(i).second > max)
            max = rows.at(i).second;
    }

    max++;

    for (int i = 0; i < max; ++i) {
        for (int j = 0; j < rows.size(); ++j) {
            if (rows.at(j).second == i)
                std::cout << rows.at(j).first << " ";
        }
        std::cout << '\n';
    }
}