package test;

// declare i32 @puts(i8* nocapture readonly) local_unnamed_addr #1
func puts(a *int8) int32;

// %1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str, i32 0, i32 0), i32 2)
func printf(s *int8, ...) int32;

var g int32 = 55;


func main() {
    var i float = 33;
    printf("%f\n", i+g+3+1);
    puts("end\n");
    return;
}


