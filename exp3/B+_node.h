enum NodeKind{NormalNodekind,LeafNodekind};//普通节点和叶子节点
enum SIBLING_DIRECTION{LEFT,RIGHT};//兄弟节点方向：左兄弟节点，右兄弟节点
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
    Node();
    virtual ~Node();

    NodeKind getType() const{return kind;}
    void setType(NodeKind rkind){kind=rkind;}
    int getKeyNum() const {return key_num;}
    void setKeyNum(int n) {key_num = n;}
    KeyType getKeyValue(int i){return key_Values[i];}
    void setKeyValue(int i,KeyType key){key_Values[i]=key;}
    int getKeyIndex(KeyType key)const;//找到键值在节点中存储的下标
    
    //纯虚函数，定义接口
    virtual void removeKey(int KeyIndex,int childIndex)=0;// 从结点中移除键值
    virtual void split(Node* parentNode,int childIndex)=0;// 分裂节点
    virtual void mergeChild(Node* parentNode,Node* childNode,int keyIndex)=0; // 合并节点
    virtual void clear()=0; // 清空节点，同时会清空节点所包含的子树节点
    virtual void borrowFrom(Node* destNode, Node* parentNode, int keyIndex, SIBLING_DIRECTION d)=0; // 从兄弟结点中借一个键值
    virtual int getChildIndex(KeyType key,int keyIndex)const=0; //根据键值获取孩子节点指针下标

    protected:
        NodeKind kind;
        //关键字的数量
        int key_num;
        KeyType key_Values[MAX_ORDER];
};
class NormalNode:public Node
{
    public:
        NormalNode();
        virtual ~NormalNode();

        Node* getChild(int i)const {return childs[i];}
        void setChild(int i,Node* Kchild){childs[i]=Kchild;}
        void insert(int keyIndex,int childIndex,KeyType key,Node* childNode);

    public:
    virtual void removeKey(int KeyIndex,int childIndex);// 从结点中移除键值
    virtual void split(Node* parentNode,int childIndex);// 分裂节点
    virtual void mergeChild(Node* parentNode,Node* childNode,int keyIndex); // 合并节点
    virtual void clear(); // 清空节点，同时会清空节点所包含的子树节点
    virtual void borrowFrom(Node* destNode, Node* parentNode, int keyIndex, SIBLING_DIRECTION d); // 从兄弟结点中借一个键值
    virtual int getChildIndex(KeyType key,int keyIndex)const; //根据键值获取孩子节点指针下标

    private:
        //指向孩子节点的指针
        Node* childs[MAX_CHILD];
};
class LeafNode
{
    public:
        LeafNode();
        virtual ~LeafNode();

        LeafNode* getLeftSibling()const {return left_next;}
        void setLeftSibling(LeafNode* node){left_next = node;}
        LeafNode* getRightSibling()const {return right_next;}
        void setRightSibling(LeafNode* node){ right_next=node;}
        DataType getData(int i)const {return datas[i];}
        void setData(int i,const DataType& data){datas[i]=data;}
        void insert(KeyType key,const DataType& data);

        virtual void removeKey(int KeyIndex,int childIndex);// 从结点中移除键值
        virtual void split(Node* parentNode,int childIndex);// 分裂节点
        virtual void mergeChild(Node* parentNode,Node* childNode,int keyIndex); // 合并节点
        virtual void clear(); // 清空节点，同时会清空节点所包含的子树节点
        virtual void borrowFrom(Node* destNode, Node* parentNode, int keyIndex, SIBLING_DIRECTION d); // 从兄弟结点中借一个键值
        virtual int getChildIndex(KeyType key,int keyIndex)const; //根据键值获取孩子节点指针下标
    private:
        //指向兄弟节点的指针
        LeafNode* left_next;
        LeafNode* right_next;
        //数据指针，指向数据
        DataType datas[MAX_LEAF];
};