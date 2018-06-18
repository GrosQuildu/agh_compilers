package test;

// declare i32 @puts(i8* nocapture readonly) local_unnamed_addr #1
func puts(a *int8) int32;

// %1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str, i32 0, i32 0), i32 2)
func printf(s *int8, ...) int32;


func test1(a int32) int32 {
    return 2+a;
}


func main() {
    var i int32 = 5;
    var x int322 = i*2;
    printf("%d\n",x);
    return;
}


