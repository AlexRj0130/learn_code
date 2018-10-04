package main

import "fmt"

// 1. 使用关键字 type 定义用户自定义类型
type flags byte

const (
	read flags = 1 << iota
	write
	exec
)

func testType() {
	f := read | exec
	fmt.Printf("%b\n", f) // 输出 101
}

// 2. 将多个 type 定义合并成组
type (
	user struct { // 结构体
		name string
		age  uint8
	}

	event func(string) bool // 函数类型
)

func testTypeGroup() {
	u := user{"Tom", 20}
	fmt.Println(u) // 输出 {Tom, 20}

	var f event = func(s string) bool {
		fmt.Println(s) // 输出 abc
		return s != ""
	}

	ret := f("abc")
	fmt.Println(ret) // 输出 true
}

// 3. 自定义类型和其基础类型之间的关系

func testRelationshipBetweenSelfDefineTypeAndBasicType() {
	/*
		即便制定了基础类型，也只表明它们有相同底层数据结构，两者间不存在任何关系，属于完全不同的两种类型。
		除操作符外，自定义类型不会继承基础类型的其他信息（包括方法）。
		不能视作别名，不能隐式转换，不能直接用于比较表达式。
	*/
	type data int
	var d data = 10
	fmt.Println(d)

	// var x int = d // cannot use d (type data) as type int in assignment
	// fmt.Println(x)

	// fmt.Println(d == x) // invalid operation: d == x (mismatched types data and int)
}

func selfDefineType() {
	testType()
	testTypeGroup()
}
