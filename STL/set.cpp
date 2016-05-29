set<type, predicate> name; 创建一个名为name，并且包含type类型数据的空对象。该对象使用谓词所指定的函数来对集合中的元素进行排序。
谓词包括： less<int>-----> 从小到大
           greater<int> ----> 从大到小

 set<type, predicate> name(myset); 
    用拷贝构造函数从一个已存在的集合myset中生成一个set对象

    begin() 返回集合中第一个元素的迭代器
	end() 返回最末元素的迭代器(实指向最末元素的下一个位置)
	clear() 清空所有元素
    empty() 判断集合是否为空（返回true时为空）
    
    erase(start，end) 删除迭代器start和end所辖范围内的集合元素
	erase(i) 删除迭代器i所指向的集合元素

	count（x）返回集合中值为x的元素个数

	find（x） 返回一个指向x的迭代器，如果x不存在，则返回的迭代器等于end  ！！注意点！！

	insert(i，x) 把x插入集合，插入位置从迭代器i所指明的元素处开始查找
	insert(start，end) 把迭代器start和end所辖范围内的元素插入到集合中
	insert(x) 把x插入集合

	Lower_bound(x) 返回一个迭代器，指向位于x或之前紧邻x的元素       //这两者主要在multiset和multimap中使用，在元素有重复的情况下
	upper_bound(x) 返回一个指向紧邻x之后的迭代器

	size() 返回集合的大小
	rbegin() 返回set尾部的逆迭代器
	rend() 返回set起始的逆迭代器


equal_range() ，返回一对定位器，分别表示第一个大于或等于给定关键值的元素和 第一个大于给定关键值的元素，这个返回值是一个pair类型，
如果这一对定位器中哪个返回失败，就会等于end()的值。
如   pair<set<int>::const_iterator,set<int>::const_iterator> pr;
     pr = s.equal_range(3);

 如果set中的类型是结构体，那么可以在结构体中重载符号，来规定set储存顺序
 如  struct node
{
	int x;
	int y;
	bool operator < (const node &tem) const
	{
		return x != tem.x ? x > tem.x:y > tem.y;
	}
};




