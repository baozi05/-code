#include<iostream>
using namespace std;
#define eleType int
struct ListNode{
    eleType data;
    ListNode *next; //下一个结点
    ListNode(eleType x)
    {
        data=x;
        next=NULL;
    }
} ;
class LinkedList{
    private:
    ListNode *head;// 一个结点 内含指针域和数据域
    int size;
    public:
    LinkedList(){
        head=NULL;
        size=0;
    }
    // 各种操作的方法
    ~LinkedList();
    void insert1(int i,eleType value); // 左插入 
    void insert2(int i,eleType value); // 右插入
    void remove(int i); //  删除
    ListNode* find(eleType value); //  查找---返回结点本身（索引）
    ListNode* get(int i); // 获取某个结点 （值）
    void update(int i,eleType value); //更新元素
    void print(); // 打印值
    int findIndex(eleType value);
};
LinkedList::~LinkedList(){
    ListNode *curr=head; // 定义另一个结点等于头结点
    if(curr!=NULL){
        ListNode *temp=curr; //临时节点 储存 curr
        curr=curr->next;
        delete temp;
    }
}
void LinkedList::insert1(int i,eleType value){
    if(i<0||i>size)
    throw out_of_range("Invalid position");
    ListNode *newNode=new ListNode(value);
    if(i==0) // 插入至头结点
    {
        newNode->next=head;
        head=newNode;
    }
    else //若不是头结点 
    {
        ListNode *curr=head;
        // 从 head 开始遍历
        for(int j=0;j<i-1;j++){
            curr=curr->next;
        }
        // 遍历完成后
        newNode->next=curr->next;
        curr->next=newNode;
    }
        size++; // 加入节点
}
void LinkedList::insert2(int i,eleType value){
    if(i<0||i>size)
    throw out_of_range("Invalid position");
    ListNode *newNode=new ListNode(value);
    if(i==size-1){
     ListNode *curr=head;
     for(int j=0;j<size-1;j++){
         curr=curr->next;
    }
    curr->next=newNode;
    }
    else{ 
    ListNode *curr=head;
    for(int j=0;j<i;j++){
        curr=curr->next;
    }
    newNode->next=curr->next;
    curr->next=newNode;
    }
    size++;
}
void LinkedList::remove(int i){
    if(i<0||i>size)
    throw out_of_range("Invalid position");
    if(i==0) // 删除头结点
    {
        ListNode *temp=head; // 临时节点储存头结点
        head=head->next;
        delete temp;
    }
    else {
        ListNode* curr=head;
        for(int j=0;j<i-1;j++){
            curr=curr->next;
        }
        // 当遍历到要删除元素前的结点时停止
        // 之后用一个临时结点储存要删除的结点
        ListNode *temp=curr->next;  // 此时的 curr->next 就是要删除的结点
        curr->next=temp->next;
        delete temp;
    }
    size--;
}
ListNode *LinkedList::find(eleType value) //找到该元素------所在的结点！！！！
{
    ListNode *curr=head;
    while(curr!=NULL&&curr->data!=value)
    {
        curr=curr->next;
    }
    return curr;
}
ListNode *LinkedList::get(int i)
{
    if(i<0||i>=size)
    throw out_of_range("Invalid position");
    else{
        ListNode *curr=head;
        for(int j=0;j<i;j++){
            curr=curr->next;
        }
        return curr;
    }
}
void LinkedList::update(int i,eleType value)
{
    get(i)->data=value; // 直接获取 i 的值更新为 value
}
void LinkedList::print(){
    ListNode *curr=head;
    while(curr!=NULL)
    {
        cout<<curr->data<<' ';
        curr=curr->next;
    }
    cout<<endl;
}
int LinkedList::findIndex(eleType value) // ------ 获取该元素所在的下标，而不是返回结点，类似于顺序表
{
    ListNode *curr=head;
    int index=0;
    while(curr!=NULL){
        if(curr->data==value)
        return index;
        else{
            curr=curr->next;
            index++;
        }
    }
    return -1;
}
int main(){
    LinkedList list;
    list.insert1(0,1);
    int n,i=2;
    cin>>n;
    n--;
    while(n--){
        int k,p;
        cin>>k>>p;
        int dex=list.findIndex(k);
        if(p==0){
        list.insert1(dex,i);
        i++;
        }
        else if(p==1)
        {
            list.insert2(dex,i);
            i++;
            }
    }
    int m;cin>>m;
    while(m--){
        int x;cin>>x;
        int index=list.findIndex(x);
        if(index==-1) continue;
        list.remove(index);
    }
    list.print();
    system("pause");
    return 0;
}