; ModuleID = 'Go2LLVM module'

@global_str = private unnamed_addr constant [4 x i8] c"%d\0A\00"
@global_str.1 = private unnamed_addr constant [6 x i8] c"nope\0A\00"

define void @main() {
"main entrypoint":
  %x.addr = alloca i64
  store i64 5, i64* %x.addr
  br i1 true, label %if, label %else

if:                                               ; preds = %"main entrypoint"
  %call_printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @global_str, i32 0, i32 0), i5 1)
  br label %merge

else:                                             ; preds = %"main entrypoint"
  %call_printf1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @global_str.1, i32 0, i32 0))
  br label %merge

merge:                                            ; preds = %else, %if
  ret void
}

declare i32 @puts(i8*)

declare i32 @printf(i8*, ...)
