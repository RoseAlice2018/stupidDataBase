#include<iostream>
#include<vector>
using namespace std;
enum NodeKind{NormalNode,LeafNode};//普通节点和叶子节点
struct data{
    int _data;
};
typedef data* Nodedata;
typedef float KeyType;
typedef int DataType;
const int ORDER = 6; //M阶B+树
//每个中间节点都包含K个元素和K个孩子，其中 m/2 <= k <= m
const int MIN_ORDER = ORDER/2;
const int MAX_ORDER = ORDER; 
const int MIN_CHILD = ORDER/2;
const int MAX_CHILD = ORDER;
//每一个叶子节点都包含k个元素，其中 m/2 <= k <= m
const int MIN_LEAF = ORDER/2;
const int MAX_LEAF = ORDER;
/*
    定义一个B+树
    1.B+树有两种类型的节点：普通节点和叶子节点，普通节点有key值和指向孩子节点的指针，叶子节点有关键值和数据。
    2.叶子节点是所有关键字从小到大排序，叶子节点有指向兄弟节点的指针
    3.一颗B+树一般存有两个指针，一个指向根节点，一个指向存有最小关键字的叶子节点。
    4.每个普通节点最多有 M个子树（M叉树）最少有ceiling（M/2）个子树
    5.M叉树对应M-1关键字
    6.
*/
//基类节点
class Node
{
    //构造
    //插入
    //删除
    protected:
        NodeKind kind;
        //关键字的数量
        int key_num;
        KeyType key_Values[MAX_ORDER];
};
class NormalNode
{
    private:
        //指向孩子节点的指针
        Node* childs[MAX_CHILD];
};
class LeafNode
{
    private:
        //指向兄弟节点的指针
        LeafNode* next;
        //数据指针，指向数据
        DataType datas[MAX_LEAF];
};
int main()
{
        
}