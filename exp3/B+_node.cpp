#include "B+_node.h"

//Node
Node::Node(){
    setType(LeafNodekind);
    setKeyNum(0);
}

Node::~Node(){
    setKeyNum(0);
}

int Node::getKeyIndex(KeyType key)const
{
    //o(n) or o(logn)
    for(int i=0;i<getKeyNum();i++)
    {
        KeyType currentKey = getKeyValue(i);
        if(key == currentKey)
            return i;
    }
    return -1;
}

//NormalNode
NormalNode::NormalNode():Node(){
    setType(NormalNodekind);
}

NormalNode::~NormalNode(){

}

void NormalNode::clear()
{
    for(int i = 0; i<=key_num;i++)
    {
        childs[i]->clear();
        delete childs[i];
        childs[i] = nullptr;
    }
}


