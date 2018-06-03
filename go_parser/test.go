package test;

func test1(a int32) int32;

func main() {
    var i int32 = test1(3);
    return;
}

func test1(a int32) int32 {
    return 2+a;
}
