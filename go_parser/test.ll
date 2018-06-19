; ModuleID = 'Go2LLVM module'

@global_str = private unnamed_addr constant [4 x i8] c"%d\0A\00"

define void @main() {
"main entrypoint":
  %i.addr = alloca double
  store double 2.000000e+00, double* %i.addr
  %x.addr = alloca i64
  store i64 11, i64* %x.addr
  %x = load i64, i64* %x.addr
  %call_printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @global_str, i32 0, i32 0), i64 %x)
  ret void
}

declare i32 @puts(i8*)

declare i32 @printf(i8*, ...)
