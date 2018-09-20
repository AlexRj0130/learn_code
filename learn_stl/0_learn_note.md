# List

list 容器分为 list 和 forward_list 两种类型  
list 类型的底层实现是一个双向链表  
forward_list 的底层实现是一个前向链表  

## 成员

list 类型中，size(), 得到容器中节点的个数   
forward_list 类型中，没有提供 size() 函数  
list 容器不支持下标运算符
list 容器支持快速地插入和删除  

list 中没有容量 capacity 的概念了，原因在于 list 的底层数据结构为链表，支持随机的插入和删除，不需要通过预留空间的方式提高效率

