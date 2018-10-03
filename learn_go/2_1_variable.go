package main

import (
	"fmt"
	"os"
)

// 1. 定义
func testVarDefine() {
	var x int         // 使用关键字 var 定义变量；类型名被放在变量名之后；编译器确保变量自动初始化为 0；
	var y = false     // 显式提供初始化值时，可由编译器自动推断变量类型
	fmt.Println(x, y) // 输出 0 false
}

// 2. 简短模式
var shortModeVal int

func testVarShortMode() {
	// 使用简短模式定义、初始化变量
	/*
		使用限制：
			1. 定义变量，同时显式初始化；
			2. 不能提供数据类型；
			3. 只能用在函数内部。
	*/
	x := 100
	fmt.Println(x) // 输出 100

	a, s := 1, "abc"
	fmt.Println(a, s) // 输出 1 abc

	// 局部变量会遮蔽全局变量
	fmt.Println(&shortModeVal, shortModeVal) // 输出 0x11a9ea0 0

	shortModeVal := "abc"
	fmt.Println(&shortModeVal, shortModeVal) // 输出 0xc0000681d0 abc

	// 简短模式部分退化为赋值操作
	// 退化的前提条件为：最少有一个新变量被定义，且必须是同一作用域
	fmt.Println(&x, x) // 输出 0xc00007a008 100
	x, y := 200, "abc"
	fmt.Println(&x, x) // 输出 0xc00007a008 200
	fmt.Println(y)     // 输出 abc

	// 如果不满足退化的前提条件
	// 不满足”最少有一个新变量被定义“的要求
	z := 100
	fmt.Println(&z, z) // 输出 0xc00008e040 100
	// z := 100  // 错误：no new variables on left side of :=
	// fmt.Println(&z, z)
	// 不满足”必须是同一作用域“的要求
	{
		z, y := 200, 300
		fmt.Println(&z, z, y) // 输出 0xc00008e050 200 300
	}

	// 在处理函数的错误返回值时，退化赋值允许我们重复利用 err 变量
	f, err := os.Open("/dev/random")
	fmt.Println(&err, err) // 输出 0xc000068200 <nil>
	buf := make([]byte, 1024)
	n, err := f.Read(buf) // 输出 0xc000068200 <nil> 1024
	fmt.Println(&err, err, n)
}

// 3. 多变量赋值
func testVarMulAssign() {
	x, y := 1, 2
	// 首先，计算出所有右值，然后再依次完成赋值操作
	x, y = y+3, x+2
	fmt.Println(x, y) // 输出 5 3
}

// 4. 未使用错误
var unUsedGlobal int

func testVarUnused() {
	// 编译器将未使用的 局部变量 当做错误
	// 未使用的全局变量不会被当做错误
	// var unUsedLocal int
}

func variable() {
	// testVarDefine()
	// testVarShortMode()
	testVarMulAssign()
}
