package main

import (
	"fmt"
	"math"
	"strconv"
)

// 1. 支持八进制、十六进制，以及科学计数法
func testNotation() {
	a, b, c := 100, 0144, 0x64

	fmt.Println(a, b, c)                    // 输出 100 100 100
	fmt.Printf("0b%b, %#o, %#x\n", a, a, a) // 输出 0b1100100, 0144, 0x64
}

// 2. 标准库 math 定义了各数字类型的取值范围
func testValueRange() {
	fmt.Println(math.MinInt8, math.MaxInt8) // 输出 -128 127
}

// 3. 标准库 strconv 可在不同进制（字符串）间转换
func testStrconv() {
	// 将表示不同进制的字符串，转化为 int
	a, _ := strconv.ParseInt("1100100", 2, 32)
	b, _ := strconv.ParseInt("0144", 8, 32)
	c, _ := strconv.ParseInt("64", 16, 32)

	fmt.Println(a, b, c) // 输出 100 100 100

	// 将 10 进制 int 值转换为不同进制的字符串
	fmt.Println("0b" + strconv.FormatInt(a, 2))  // 输出 0b1100100
	fmt.Println("0" + strconv.FormatInt(a, 8))   // 输出 0144
	fmt.Println("0x" + strconv.FormatInt(a, 16)) // 输出 0x64
}

// 4. 测试浮点数的精度
func testFloatPrecision() {
	var a float32 = 1.1234567899 // 注意：默认浮点类型是 float64
	var b float32 = 1.12345678
	var c float32 = 1.123456781

	fmt.Println(a, b, c)              // 输出 1.1234568 1.1234568 1.1234568
	fmt.Println(a == b, a == c)       // 输出 true true
	fmt.Printf("%v, %v, %v", a, b, c) // 输出 1.1234568, 1.1234568, 1.1234568
}

// 5. 别名
func printAlias(x byte) {
	fmt.Println(x)
}

func testAlias() {
	// 在官方的语言规范中，专门提到两个别名，分别是
	// byte  alias for uint8
	// rune  alias for int32

	// 别名无需类型转换，可直接赋值
	var a byte = 0x11
	var b uint8 = a
	var c uint8 = a + b
	printAlias(c) // 输出 34

	// 注意，并非拥有相同底层结构的就属于别名。
}

func basicType() {
	// testNotation()
	// testValueRange()
	// testStrconv()
	// testFloatPrecision()
	testAlias()
}
