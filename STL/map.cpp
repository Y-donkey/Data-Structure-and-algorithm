map<key, type, predicate> name; 创建一个名为name，并且包含type类型数据的空对象。
该对象使用谓词所指定的函数来对集合中的元素进行排序。

为了实现快速查找，map内部本身就是按序存储的（比如红黑树）。
在我们插入<key, value>键值对时，就会按照key的大小顺序进行存储。这也是作为key的类型必须能够进行<运算比较的原因。
默认从小到大


map按照key值进行排序：
	默认的有less<type>,greater<type>
	如果自己想自定义，写一个函数对象即可：
	如 ：
	  struct CmpByKey {  
   bool operator()(const string& k1, const string& k2) {  
     return k1.length() < k2.length();  
     }  
   };  

   定义map时可这样定义：  map<string, int, CmpByKey> v;


 map按照value值排序：

 		把map中的pair转入vector后用sort即可

其他用法和set差不多，参考即可



