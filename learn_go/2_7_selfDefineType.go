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
	fmt.Println(d) // 输出 10

	// var x int = d // cannot use d (type data) as type int in assignment
	// fmt.Println(x)

	// fmt.Println(d == x) // invalid operation: d == x (mismatched types data and int)
}

// 4. 未命名类型
func testUnnamedType() {
	/*
	   与有明确标识符的 bool, int, string 等类型相比，数组、切片、字典、通道等类型与具体元素类型或长度等属性相关，故称作未命名类型（unnamed type）。
	   当然，可用 type 为其提供具体名称，将其改变为命名类型（named type）。
	   具有相同声明的未命名类型被视作同一类型：
	   	具有相同基类型的指针。
	   	具有相同元素类型和长度的数组（array）。
	   	具有相同元素类型的切片（slice）。
	   	具有相同键值类型的字典（map）。
	   	具有相同数据类型及操作方向的通道（channel）。
	   	具有相同字段序列（字段名、字段类型、标签、以及字段顺序）的结构体(struct)。
	   		注意，struct tag 也属于类型组成部分，而不仅仅是元数据描述。
	   	具有相同签名（参数和返回值列表，不包括参数名）的函数(func)。
	   		注意，函数的参数顺序也属于签名组成部分。
	   	具有相同方法集（方法名，方法签名，不包括顺序）的接口（interface）。
	*/
	var a struct { // 匿名结构类型
		x int    `x`
		s string `s`
	}
	fmt.Println(a) // 输出 {0 }

	var b struct {
		x int
		s string
	}
	fmt.Println(b) // 输出 {0 }

	// b = a // cannot use a type struct {x int "x"; s string "s"} as type struct {x int; s string} in assignment

	var fa func(int, string)
	fmt.Println(fa) // 输出 nil
	var fb func(string, int)
	fmt.Println(fb) // 输出 nil
	// fb = fa // cannot use fa (type func(int, string)) as type func(stirng, int) in assignment

	/*
	   未命名类型转换规则：
	   	所属类型相同。
	   	基础类型相同，且其中一个是未命名类型。
	   	数据类型相同，将双向通道赋值给单向通道，且其中一个是未命名类型。
	   	将默认值 nil 赋值给切片、字典、通道、指针、函数或接口。
	   	对象实现了目标接口。
	*/
	type data [2]int
	var d data = [2]int{1, 2} // 基础类型相同，右值为未命名类型
	fmt.Println(d)            // 输出 [1 2]

	ca := make(chan int, 2)
	var cb chan<- int = ca // 双向通道转换为单向通道，其中 cb 是未命名类型
	fmt.Println(cb)        // 输出 0xc00004e070
}

func selfDefineType() {
	// testType()
	// testTypeGroup()
	// testRelationshipBetweenSelfDefineTypeAndBasicType()
	testUnnamedType()
}
