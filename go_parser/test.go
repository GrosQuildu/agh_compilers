package test;

// declare i32 @puts(i8* nocapture readonly) local_unnamed_addr #1
func puts(a *int8) int32;

// %1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str, i32 0, i32 0), i32 2)
func printf(s *int8, ...) int32;

var g int = 6;

func test1(a *int32, b int32) int32 {
    var x float = b;
    if x == 1 {
        *a = 1;
    } else if x==2 {
        *a = 2;
    } else {
        *a = 3;
    }

    return 0;
}

func test2() {
    puts("test2\n");
    return;
}

func main() {
    var x int32;
    printf("x %d\n", x)
    x = 1;
    var i *int32 = &x;
    test2();
    test1(i, 3);
    printf("%d\n", x);
    return;
}


