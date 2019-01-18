; ModuleID = 'Go2LLVM module'

@global_str = private unnamed_addr constant [8 x i8] c"a = %d\0A\00"
@global_str.1 = private unnamed_addr constant [12 x i8] c"almost end\0A\00"
@global_str.2 = private unnamed_addr constant [5 x i8] c"end\0A\00"

define void @main() {
"main entrypoint":
  call void @test_func(i64 5)
  ret void
}

declare i32 @printf(i8*, ...)

define void @test_func(i64 %a) {
"test_func entrypoint":
  %a.addr = alloca i64
  store i64 %a, i64* %a.addr
  %a1 = load i64, i64* %a.addr
  %binaryCmpICMP_SLE = icmp sge i64 %a1, 0
  br i1 %binaryCmpICMP_SLE, label %if, label %else

if:                                               ; preds = %"test_func entrypoint"
  %a2 = load i64, i64* %a.addr
  %call_printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([8 x i8], [8 x i8]* @global_str, i32 0, i32 0), i64 %a2)
  %a3 = load i64, i64* %a.addr
  %CreateSub = sub i64 %a3, 1
  call void @test_func(i64 %CreateSub)
  br label %merge9

else:                                             ; preds = %"test_func entrypoint"
  %a4 = load i64, i64* %a.addr
  %binaryCmpICMP_EQ = icmp eq i64 %a4, -1
  br i1 %binaryCmpICMP_EQ, label %if5, label %else7

if5:                                              ; preds = %else
  %call_printf6 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @global_str.1, i32 0, i32 0))
  call void @test_func(i64 -99)
  br label %merge

else7:                                            ; preds = %else
  %call_printf8 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @global_str.2, i32 0, i32 0))
  br label %merge

merge:                                            ; preds = %else7, %if5
  br label %merge9

merge9:                                           ; preds = %merge, %if
  ret void
}
