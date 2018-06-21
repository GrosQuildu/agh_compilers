; ModuleID = 'Go2LLVM module'

@g = internal global i64 0
@global_str = private unnamed_addr constant [7 x i8] c"test2\0A\00"
@global_str.1 = private unnamed_addr constant [6 x i8] c"x %d\0A\00"
@global_str.2 = private unnamed_addr constant [4 x i8] c"%d\0A\00"

define void @main() {
"main entrypoint":
  store i64 6, i64* @g
  %x.addr = alloca i32
  %x = load i32, i32* %x.addr
  %call_printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @global_str.1, i32 0, i32 0), i32 %x)
  %x1 = load i32, i32* %x.addr
  store i32 1, i32* %x.addr
  %i.addr = alloca i32*
  store i32* %x.addr, i32** %i.addr
  call void @test2()
  %i = load i32*, i32** %i.addr
  %call_test1 = call i32 @test1(i32* %i, i32 3)
  %x2 = load i32, i32* %x.addr
  %call_printf3 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @global_str.2, i32 0, i32 0), i32 %x2)
  ret void
}

declare i32 @puts(i8*)

declare i32 @printf(i8*, ...)

define i32 @test1(i32* %a, i32 %b) {
"test1 entrypoint":
  %a.addr = alloca i32*
  store i32* %a, i32** %a.addr
  %b.addr = alloca i32
  store i32 %b, i32* %b.addr
  %b1 = load i32, i32* %b.addr
  %0 = sitofp i32 %b1 to double
  %x.addr = alloca double
  store double %0, double* %x.addr
  %x = load double, double* %x.addr
  %binaryFCmp = fcmp oeq double %x, 1.000000e+00
  br i1 %binaryFCmp, label %if, label %else

if:                                               ; preds = %"test1 entrypoint"
  %load_a = load i32*, i32** %a.addr
  %dereference_a = load i32, i32* %load_a
  %load_a2 = load i32*, i32** %a.addr
  store i32 1, i32* %load_a2
  br label %merge13

else:                                             ; preds = %"test1 entrypoint"
  %x3 = load double, double* %x.addr
  %binaryFCmp4 = fcmp oeq double %x3, 2.000000e+00
  br i1 %binaryFCmp4, label %if5, label %else9

if5:                                              ; preds = %else
  %load_a6 = load i32*, i32** %a.addr
  %dereference_a7 = load i32, i32* %load_a6
  %load_a8 = load i32*, i32** %a.addr
  store i32 2, i32* %load_a8
  br label %merge

else9:                                            ; preds = %else
  %load_a10 = load i32*, i32** %a.addr
  %dereference_a11 = load i32, i32* %load_a10
  %load_a12 = load i32*, i32** %a.addr
  store i32 3, i32* %load_a12
  br label %merge

merge:                                            ; preds = %else9, %if5
  br label %merge13

merge13:                                          ; preds = %merge, %if
  ret i32 0
}

define void @test2() {
"test2 entrypoint":
  %call_puts = call i32 @puts(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @global_str, i32 0, i32 0))
  ret void
}
