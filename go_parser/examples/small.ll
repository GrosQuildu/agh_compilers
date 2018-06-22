; ModuleID = 'Go2LLVM module'

@global_str = private unnamed_addr constant [3 x i8] c"%d\00"
@x = internal global i64 0

define void @main() {
"main entrypoint":
  %x.addr = alloca i64
  store i64 0, i64* %x.addr
  %x = load i64, i64* %x.addr
  %call_printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @global_str, i32 0, i32 0), i64 %x)
  ret void
  store i64 2, i64* @x
}

declare i32 @putsx(i8*)

declare i32 @printf(i8*, ...)
