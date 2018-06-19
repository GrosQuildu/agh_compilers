; ModuleID = 'Go2LLVM module'

@g = internal global i64 0
@global_str = private unnamed_addr constant [4 x i8] c"%d\0A\00"
@global_str.1 = private unnamed_addr constant [4 x i8] c"%d\0A\00"
@global_str.2 = private unnamed_addr constant [4 x i8] c"%d\0A\00"

define void @main() {
"main entrypoint":
  store i64 55, i64* @g
  br i1 false, label %if, label %else

if:                                               ; preds = %"main entrypoint"
  %call_printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @global_str, i32 0, i32 0), i5 1)
  br label %ifcont

else:                                             ; preds = %"main entrypoint"
  %call_printf1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @global_str.1, i32 0, i32 0), i5 2)
  br label %ifcont

ifcont:                                           ; preds = %else, %if
  %call_printf2 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @global_str.2, i32 0, i32 0), i5 3)
  ret void
}

declare i32 @puts(i8*)

declare i32 @printf(i8*, ...)
