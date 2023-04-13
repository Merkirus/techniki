#ifndef CTREEDYNAMIC_TEMP_H

#include <iostream>
#include <vector>
#include <typeinfo>

template<typename T> class CNodeDynamicT
{
public:
    CNodeDynamicT() {pc_parent_node = NULL;}
    ~CNodeDynamicT() {for (int i = 0; i < v_children.size(); ++i) delete v_children.at(i);}
    void vSetValue(T tNewVal) {t_val = tNewVal;}
    int iGetChildrenNumber() {return v_children.size();}
    void vAddNewChild()
    {
        CNodeDynamicT<T> *pcTemp;
        pcTemp = new CNodeDynamicT<T>();
        pcTemp->pc_parent_node = this;
        v_children.push_back(pcTemp);
    }
    void vAddNewChild(CNodeDynamicT<T> *pcNewNode)
    {
        CNodeDynamicT<T> *pcTemp;
        pcTemp = pcNewNode;
        pcTemp->pc_parent_node = this;
        v_children.push_back(pcTemp);
    }
    void vRemoveChild(CNodeDynamicT<T> *pcChild)
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
    CNodeDynamicT<T> *pcGetChild(int iChildOffset) {return v_children.at(iChildOffset);}
    CNodeDynamicT<T> *pcGetParent() {return pc_parent_node;}
    void vPrint() {std::cout << " " << t_val;}
    void vPrintAllBelow()
    {
        vPrint();
        for (int i = 0; i < v_children.size(); ++i)
            v_children.at(i)->vPrintAllBelow();
    }
    T tGetValueOfChildren();
private:
    std::vector<CNodeDynamicT<T> *> v_children;
    CNodeDynamicT<T> *pc_parent_node;
    T t_val;
};

template<>
int CNodeDynamicT<int>::tGetValueOfChildren()
{
    int result;
    result = 0;
    for (int i = 0; i < v_children.size(); ++i)
        result += (int)v_children.at(i)->tGetValueOfChildren();

    return (int)t_val + result;
}

template<>
double CNodeDynamicT<double>::tGetValueOfChildren()
{
    double result;
    result = 0;
    for (int i = 0; i < v_children.size(); ++i)
        result += (int)v_children.at(i)->tGetValueOfChildren();

    return (int)t_val + result;
}

template<typename T>
T CNodeDynamicT<T>::tGetValueOfChildren()
{
    return 0;
}

template<typename T> class CTreeDynamicT
{
public:
    CTreeDynamicT() {pc_root = new CNodeDynamicT<T>;}
    ~CTreeDynamicT() {delete pc_root;}
    CNodeDynamicT<T> *pcGetRoot() {return pc_root;}
    bool bMoveSubtree(CNodeDynamicT<T> *pcParentNode, CNodeDynamicT<T> *pcNewChildNode)
    {
        CNodeDynamicT<T> *pcTemp;
        pcTemp = pcNewChildNode;
        if (pcNewChildNode->pcGetParent())
            pcNewChildNode->pcGetParent()->vRemoveChild(pcNewChildNode);
        pcParentNode->vAddNewChild(pcTemp);
        return true;
    }
    void vPrintTree() {pc_root->vPrintAllBelow();}
    T tSum()
    {
        return pc_root->tGetValueOfChildren();
    }
private:
    CNodeDynamicT<T> *pc_root;
};

#endif
