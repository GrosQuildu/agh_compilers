package small

func printf(a *int8, ...) int32

func test_func(a int) {
	if a >= 0 {
		printf("a = %d\n", a)
		test_func(a-1)
	} else if a == -1 {
		printf("almost end\n")
		test_func(-99)
	} else {
		printf("end\n")
	}
	return
}

func main() {
	test_func(5)
	return;
}

