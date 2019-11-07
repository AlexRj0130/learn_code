package main

import (
	"fmt"
)

// 引用类型
func mkSlice() []int {
	s := make([]int, 0, 10)
	s = append(s, 100)
	return s
}

func mkMap() map[string]int {
	m := make(map[string]int)
	m["a"] = 1
	return m
}

func testReferenceType() {
	s := mkSlice()
	fmt.Println(s[0]) // 输出 100

	m := mkMap()
	fmt.Println(m)
}

func referenceType() {
	testReferenceType() // 输出 map[a:1]
}
