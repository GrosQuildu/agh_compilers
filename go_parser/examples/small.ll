; ModuleID = 'Go2LLVM module'

@global_str = private unnamed_addr constant [2 x i8] c"x\00"
@global_str.1 = private unnamed_addr constant [5 x i8] c"nope\00"

define void @main() {
"main entrypoint":
  %x.addr = alloca i1
  store i1 true, i1* %x.addr
  %x = load i1, i1* %x.addr
  br i1 %x, label %if, label %else

if:                                               ; preds = %"main entrypoint"
  %call_puts = call i32 @puts(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @global_str, i32 0, i32 0))
  br label %merge

else:                                             ; preds = %"main entrypoint"
  %call_puts1 = call i32 @puts(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @global_str.1, i32 0, i32 0))
  br label %merge

merge:                                            ; preds = %else, %if
  ret void
}

declare i32 @puts(i8*)

declare i32 @printf(i8*, ...)

define void @x() {
"x entrypoint":
  ret void
}
