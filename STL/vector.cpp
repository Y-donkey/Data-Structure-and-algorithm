创建vector对象

vector<type> name;
vector<type> name(size); 创建具有size元素个数的vector对象
vector<type> name(size，value); 创建具有size元素个数的vector对象，并将对象的初始值设为value
vector<type> name(myvector); 采用拷贝构造函数，用现有的向量myvector创建一个vector对象
vector<type> name(start，end); 创建了元素在指定范围内的向量，start代表起始范围，end代表结束范围。（构造一个初始值为[start,end)区间元素的Vector）

assign(first, last) 用迭代器first和last所辖范围内的元素替换向量元素
如：	v2.assign(v1.begin(), v1.end());

assign(num, val) 用val的num个副本替换向量元素
如：	v3.assign(7, 3) ;

at(n) 返回指定位置的元素       //从零开始计数

front() 返回第一个元素
back() 返回最末一个元素

begin() 返回第一个元素的迭代器
end() 返回最末元素的迭代器(实指向最末元素的下一个位置)

clear() 清空所有元素
empty() 判断Vector是否为空（返回true时为空）

erase(i) 删除迭代器i所指向的向量元素
erase(start，end) 删除迭代器start和end所辖范围内的向量元素
如：	it1 = v1.begin() + 2;
		it2 = v1.begin() + 5;
		v1.erase(it1, it2);


insert(i，x) 把x插入向量中由迭代器i所指明的位置
insert(i，start，end) 把迭代器start和end所辖范围内的元素插入到向量中由迭代器所指明的位置
insert(i，n，x) 把x的n个副本插入向量中由迭代器i所指明的位置
如：	it1 = v1.begin() + 2;
		it2 = v1.begin() + 5;
		v1.insert(v1.begin(), it1, it2);

pop_back() 移除最后一个元素
push_back(x) 在Vector最后添加一个元素x

size() 返回Vector元素数量的大小

rbegin() 返回Vector尾部的逆迭代器，它指向容器的最后一个元素
rend() 返回Vector起始的逆迭代器，它指向容器的第一个元素前面的位置
如：	逆序遍历容器：

	for(it=v.rbegin();it!=v.rend();it++)   cout<<*it<<" ";




		!!  list and deque和vector类似，在此就不列举了 ！！

