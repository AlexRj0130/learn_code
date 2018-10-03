package main

import (
	"fmt"
	"unsafe"
)

// 1. 常量的定义
func testConst() {
	// 常量值必须是编译期可确定的字符、字符串、数字、布尔值。
	// 可指定常量类型，或由编译器通过初始化值推断。
	// 可在函数代码块中定义常量。
	// 不曾使用的常量避讳引发编译错误。

	const x, y int = 123, 0x22
	const s = "hello, world!"
	const c = '我' // rune (unicode code point)

	const (
		i, f = 1, 0.123
		b    = false
	)

	// 如果显式指定类型，必须确保常量左右值类型一致，需要时可做显式转换。
	// 右值不能超出常量类型取值范围，否则会引发溢出错误
	const (
		m, n int  = 99, -999
		d    byte = byte(m)
		// e         = uint8(n) // constant -999 overflows uint8
	)

	// 常量值也可以是某些编译器能计算出结果的表达式，如 unsafe.Sizeof、len、cap 等
	const (
		prtSize = unsafe.Sizeof(uintptr(0))
		strSize = len("hello, world!")
	)

	// 在常量组中，如不指定类型和初始化值，则与上一行非空常量右值（表达式文本）相同
	const (
		x1 uint16 = 120
		y1
		s1 = "abc"
		r1
	)

	fmt.Printf("%T, %v\n", y1, y1) // 输出 uint16, 120
	fmt.Printf("%T, %v\n", r1, r1) // 输出 string, abc
}

func testEnum() {
	// Go 并没有明确意义上的 enum 定义，不过可以借助 iota 标识符实现一组自增常量值来实现枚举类型
	const (
		x = iota // 0
		y        // 1
		z        // 2
	)

	// 自增作用范围为常量组
	const (
		_  = iota             // 0
		KB = 1 << (10 * iota) // 1 << (10 * 1)
		MB                    // 1 << (10 * 2)
		GB                    // 1 << (10 * 3)
	)

	// 可在多常量定义中使用多个 iota，它们各自单独计数，只需要保证每行常量的列数量相同即可。
	const (
		_, _ = iota, iota * 10 // 0, 0 * 10
		a, b                   // 1, 1 * 10
		c, d                   // 2, 2 * 10
	)

	// 如果中断 iota 自增，则必须显式恢复。且后续自增值按行序递增，而非 C enum 那般按上一取值递增。
	const (
		a1 = iota // 0
		b1        // 1
		c1 = 100  // 100
		d1        // 100
		e1 = iota // 4
		f1        //5
	)

	// 自增默认数据类型为 int， 可显式指定类型
	const (
		a2         = iota // int
		b2 float32 = iota // float32
		c2         = iota // int (如不显式指定 iota，则与 b 数据类型相同)
	)

	fmt.Printf("%T, %v\n", a2, a2) // 输出 int, 0
	fmt.Printf("%T, %v\n", b2, b2) // 输出 float32, 1
	fmt.Printf("%T, %v\n", c2, c2) // 输出 int, 2

	// 在实际编码中，建议用自定义类型实现用途明确的枚举类型。
	// 但这并不能将取值范围限定在预定义的枚举值内。
	type color byte

	const (
		black color = iota // 指定常量类型
		red
		blue
	)

	fmt.Printf("%T, %v\n", black, black) // main.color, 0
	fmt.Printf("%T, %v\n", red, red)     // main.color, 1
	fmt.Printf("%T, %v\n", blue, blue)   // main.color, 2
}

func testUnfold() {
	// 不同于变量在运行期分配存储内存（非优化状态）
	// 常量通常会被编译器在预处理阶段直接展开，作为指令数据使用
	// 数字常量通常不会分配存储空间，无须像变量那样通过内存来取值，因此，无法获取地址
	var x = 100
	const y = 0x200
	fmt.Println(&x, x)
	// fmt.Println(&y, y) // cannot take the address of y
}

func constVariable() {
	// testConst()
	testEnum()
}
