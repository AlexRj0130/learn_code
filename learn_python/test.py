# -*- coding: utf-8 -*-

def func(x, l=[]):
    for i in range(x):
        l.append(i*i)
    print(l)

func(2)
func(3, [1, 2, 3])
func(2)  # 注意这里的输出结果
func(2)  # 还有这里