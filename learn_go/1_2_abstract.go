package main // 在文件头部用 package 声明所属包名称；支持 C 样式注释

import ( // 使用 import 导入标准库或第三方包; 由于编辑器会把未使用的导入当做错误，所以，vscode 在保存时，会自动删除没有使用的包。
	"errors"
	"fmt"
	"time"
)

// 1. 基本输出
func testPrint() {
	println("hello, world!")     // 输出 hello, world!
	fmt.Println("hello, world!") // 输出 hello, world!
}

// 2. 变量
func testVar() {
	// 编译器会将未使用的局部变量当做错误
	var x int32             // 使用 var 定义变量，编译器确保变量总是被初始化为 0 值
	var s = "hello, world!" // 支持类型推断
	println(x, s)           // 输出 0 hello, world!

	y := 100   // 在函数内部，还可以省略 var 关键字
	println(y) // 输出 100
}

// 3. 表达式: go 仅有三种流控制语句，分别是 if, switch, for
func testExpression() {
	// 表达式：if
	z := 10

	if z > 0 {
		println("z") // 输出 z
	} else if z < 0 {
		println("-z")
	} else {
		println("0")
	}

	// 表达式：switch
	z = 100
	switch {
	case z > 0:
		println("z") // 输出 z
	case z < 0:
		println("-z")
	default:
		println("0")
	}

	// 表达式：for
	for i := 0; i < 5; i++ {
		println(i) // 输出 0 1 2 3 4
	}

	for i := 4; i >= 0; i-- {
		println(i) // 输出 4 3 2 1 0
	}

	j := 0
	for j < 5 { // 相当于 while (j < 5)
		println(j) // 输出 0 1 2 3 4
		j++
	}

	j = 4
	for { // 相当于 while (true)
		println(j) // 输出 4 3 2 1 0
		j--
		if j < 0 {
			break
		}
	}

	p := []int{100, 101, 102}
	for i, n := range p { // for ... range 同时返回索引和元素
		println(i, ": ", n) // 输出 0: 100 \n 1: 101 \n 2: 102
	}
}

// 4. 函数
func div(a, b int) (int, error) { // 函数可以定义多个返回值，甚至对其命名
	if b == 0 {
		return 0, errors.New("division by zero")
	}
	return a / b, nil
}

func returnFunc(x int) func() { // 返回函数类型
	// 函数是第一类型，可作为参数或返回值
	return func() { // 匿名函数
		println(x) // 闭包
	}
}

func testDefer(a, b int) {
	// 用 defer 定义延迟调用，无论函数是否出错，它都确保结束前被调用
	// 常用来释放资源、解除锁定，或执行一些清理操作
	// 可定义多个 defer, 按 FILO 顺序执行
	defer println("dispose...")
	println(a / b)
}

func testFunction() {
	a, b := 10, 2
	c, err := div(a, b)
	fmt.Println(c, err) // 输出 5 <nil>

	f := returnFunc(c)
	f() // 输出 5

	// testDefer(10, 0) // 输出 dispose... \n panic: runtime error: integer divide by zero
}

// 5. 数据
func testData() {
	// 切片（Slice）可实现类似动态数组的功能
	xSlice := make([]int, 0, 5) // 创建容量为 5 的切片
	for i := 0; i < 8; i++ {
		xSlice = append(xSlice, i) // 追加数据。当超出容量限制时，自动分配更大的存储空间
	}
	fmt.Println(xSlice) // 输出 [0 1 2 3 4 5 6 7]

	// 字典，属于内置类型，可以直接从运行时层面获得优化
	xMap := make(map[string]int) // 创建字典类型对象
	xMap["a"] = 1                // 添加或设置
	x, ok := xMap["b"]           // 使用 ok-idiom，可知道 key/value 是否存在
	fmt.Println(x, ok)           // 输出 0 false
	delete(xMap, "a")            // 删除

	// 结构体：可以匿名嵌入其他类型
	type user struct { // 结构体类型
		name string
		age  byte
	}

	type manager struct {
		user  // 匿名嵌入其他类型，相当于直接引用了匿名类型中的成员
		title string
	}

	var mStruct manager
	mStruct.name = "Tom" // 直接访问匿名字段的成员
	mStruct.age = 29
	mStruct.title = "CTO"

	fmt.Println(mStruct) // 输出 {{Tom 29} CTO}
}

// 6. 方法
type xMethod int // 定义指定类型的方法

func (x *xMethod) inc() {
	*x++
}

type methodUser struct {
	name string
	age  byte
}

func (u methodUser) ToString() string {
	return fmt.Sprintf("%+v", u)
}

type methodManager struct {
	methodUser
	title string
}

func testMethod() {
	// 可以为当前包内的任意类型定义方法
	var xMethodTmp xMethod
	xMethodTmp.inc()
	println(xMethodTmp) // 输出 1

	// 直接调用匿名字段的方法，这种方式可实现与继承类似的功能
	var mm methodManager
	mm.name = "Tom"
	mm.age = 29
	println(mm.ToString()) // 输出 {name:Tom age:29}
}

// 7. 接口
type interfaceUser struct {
	name string
	age  byte
}

func (u interfaceUser) Print() {
	fmt.Printf("%+v\n", u)
}

type interfacePrinter interface {
	Print()
}

func testInterface() {
	// 接口采用了 duck type 方式，也就是说无须在实现类型上添加显式声明
	var u interfaceUser
	u.name = "Tom"
	u.age = 29

	// 可以看出，只要一个类型中包含了接口所需的全部方法，即表示该类型实现了该接口
	var p interfacePrinter = u
	p.Print() // 输出 {name:Tom age:29}
}

// 8. 并发
func concurTask(id int) {
	for i := 0; i < 5; i++ {
		fmt.Printf("%d: %d\n", id, i)
		time.Sleep(time.Second)
	}
}

func testConcurrency() {
	// 整个运行时完全并发化设计。
	// 凡能所见，几乎都在以 goroutine 方式运行。
	// 这是一种比普通协程或线程更加高效的并发设计，能轻松创建和运行成千上万的并发任务
	go concurTask(1) // 这个应该就是一个 goroutine
	go concurTask(2) // 这个应该也是一个 goroutine

	time.Sleep(time.Second * 6)
}

// 9. CSP 模型
func consumer(data chan int, done chan bool) {
	for x := range data { // for ... range 过程将一直持续，直到数据通道 data 被关闭
		println("recv: ", x)
	}
	done <- true
}

func producer(data chan int) {
	for i := 0; i < 4; i++ {
		data <- i
		time.Sleep(time.Second)
	}
	close(data) // 关闭数据通道
}

func testCSP() {
	done := make(chan bool) // 用于接收消费结束信号
	data := make(chan int)  // 数据通道

	go consumer(data, done) // 启动消费者
	go producer(data)       // 启动生产者

	<-done // 阻塞，直到消费者发回结束信号
}

func abstract() { // 入口 main 没有参数，且必须放在 main 包中
	// testPrint()
	// testVar()
	// testExpression()
	// testFunction()
	// testData()
	// testMethod()
	// testInterface()
	// testConcurrency()
	testCSP()
}
