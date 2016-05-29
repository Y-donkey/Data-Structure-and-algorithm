priority_queue<int> v;
默认从小到大 ，等价于priority_queue<int,vector<int>,less<int> >v;

从大到小： priority_queue<int, vector<int>, greater<int> >pq;

自定义：
 struct node
{
    friend bool operator< (node n1, node n2)
    {
        return n1.priority < n2.priority;
    }
    int priority;
    int value;
}; 

priority_queue<node> qn;
