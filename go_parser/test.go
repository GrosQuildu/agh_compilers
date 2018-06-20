package test;

// declare i32 @puts(i8* nocapture readonly) local_unnamed_addr #1
func puts(a *int8) int32;

// %1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str, i32 0, i32 0), i32 2)
func printf(s *int8, ...) int32;

var g int = 55;


func main() {
    printf("%d\n", g);
    var x int;
    if 1==0 {
        x = 5;
    } else if x==1 {
        x = 6;
    } else if x-1 == g - 56 {
        x = 7
    } else {
        x = 8;
    }
    printf("%d\n",x);
    return;
}


