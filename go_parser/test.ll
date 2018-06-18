; ModuleID = 'Go2LLVM module'

@global_str = private unnamed_addr constant [4 x i8] c"%d\0A\00"

define void @main() {
"main entrypoint":
  %x.addr = alloca i32
  store i32 268435456, i32* %x.addr
  %x = load i32, i32* %x.addr
  %call_printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @global_str, i32 0, i32 0), i32 %x)
  ret void
}

declare i32 @puts(i8*)

declare i32 @printf(i8*, ...)
