; ModuleID = 'Go2LLVM module'

@global_str = private unnamed_addr constant [19 x i8] c"func3, counter %d\0A\00"
@global_str.1 = private unnamed_addr constant [22 x i8] c"vars: %d, %d, %f, %a\0A\00"
@global_str.2 = private unnamed_addr constant [2 x i8] c"x\00"
@global_str.3 = private unnamed_addr constant [5 x i8] c"no x\00"
@global_str.4 = private unnamed_addr constant [14 x i8] c"vars2: %x %d\0A\00"
@global_str.5 = private unnamed_addr constant [9 x i8] c"bum: %d\0A\00"
@global_str.6 = private unnamed_addr constant [13 x i8] c"ptr: %d, %d\0A\00"
@global_str.7 = private unnamed_addr constant [13 x i8] c"\0Aarithmetic:\00"
@global_str.8 = private unnamed_addr constant [4 x i8] c"%d\0A\00"
@global_str.9 = private unnamed_addr constant [4 x i8] c"%f\0A\00"
@global_str.10 = private unnamed_addr constant [4 x i8] c"%f\0A\00"
@global_str.11 = private unnamed_addr constant [1 x i8] zeroinitializer
@global_str.12 = private unnamed_addr constant [11 x i8] c"\0Abranches:\00"
@global_str.13 = private unnamed_addr constant [9 x i8] c"12 == 12\00"
@global_str.14 = private unnamed_addr constant [8 x i8] c"12 ==13\00"
@global_str.15 = private unnamed_addr constant [8 x i8] c"12 ==14\00"
@global_str.16 = private unnamed_addr constant [11 x i8] c"12 -> else\00"
@global_str.17 = private unnamed_addr constant [20 x i8] c"var1*var2*var3 <= 0\00"
@global_str.18 = private unnamed_addr constant [12 x i8] c"\0Afunctions:\00"
@global_str.19 = private unnamed_addr constant [12 x i8] c"f1(%d): %d\0A\00"
@global_str.20 = private unnamed_addr constant [18 x i8] c"f2(%d,%f,%f): %f\0A\00"
@global_str.21 = private unnamed_addr constant [12 x i8] c"\0Arecursion:\00"
@global_str.22 = private unnamed_addr constant [19 x i8] c"string formatting:\00"
@global_str.23 = private unnamed_addr constant [4 x i8] c"AB \00"
@global_str.24 = private unnamed_addr constant [4 x i8] c"end\00"

define void @main() {
"main entrypoint":
  %precFloatBig.addr = alloca fp128
  %precFloatSmall.addr = alloca i8
  %precInt.addr = alloca i64
  %precFloat.addr = alloca double
  %b.addr36 = alloca i64
  %b.addr = alloca i64
  %a.addr = alloca i64
  %f1Result.addr = alloca i64
  %f1Input.addr = alloca i64
  %z.addr = alloca double
  %ptr1.addr = alloca i64*
  %"test\C3\B3\C5\82\C4\99\C4\85\C5\BC\C5\BA\C7\B7\C6\BFwwoo\C5\81\C4\84\C5\BB\C5\B9\C6\A4\C6\A4\C6\A4.addr" = alloca i131
  %var6.addr = alloca i64
  %var5.addr = alloca i64
  %x.addr = alloca i1
  %var4.addr = alloca fp128
  %var3.addr = alloca double
  %var2.addr = alloca i7331
  %var1.addr = alloca i64
  store i64 5, i64* %var1.addr
  store i7331 4444, i7331* %var2.addr
  store double -1.100000e-01, double* %var3.addr
  store fp128 0xL00000000000000004009348000000000, fp128* %var4.addr
  %var1 = load i64, i64* %var1.addr
  %var2 = load i7331, i7331* %var2.addr
  %var3 = load double, double* %var3.addr
  %var4 = load fp128, fp128* %var4.addr
  %call_printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([22 x i8], [22 x i8]* @global_str.1, i32 0, i32 0), i64 %var1, i7331 %var2, double %var3, fp128 %var4)
  store i1 true, i1* %x.addr
  %x = load i1, i1* %x.addr
  br i1 %x, label %if, label %else

if:                                               ; preds = %"main entrypoint"
  %call_puts = call i32 @puts(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @global_str.2, i32 0, i32 0))
  br label %merge

else:                                             ; preds = %"main entrypoint"
  %call_puts1 = call i32 @puts(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @global_str.3, i32 0, i32 0))
  br label %merge

merge:                                            ; preds = %else, %if
  store i64 291, i64* %var5.addr
  store i64 83, i64* %var6.addr
  %var5 = load i64, i64* %var5.addr
  %var6 = load i64, i64* %var6.addr
  %call_printf2 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([14 x i8], [14 x i8]* @global_str.4, i32 0, i32 0), i64 %var5, i64 %var6)
  store i131 123, i131* %"test\C3\B3\C5\82\C4\99\C4\85\C5\BC\C5\BA\C7\B7\C6\BFwwoo\C5\81\C4\84\C5\BB\C5\B9\C6\A4\C6\A4\C6\A4.addr"
  %"test\C3\B3\C5\82\C4\99\C4\85\C5\BC\C5\BA\C7\B7\C6\BFwwoo\C5\81\C4\84\C5\BB\C5\B9\C6\A4\C6\A4\C6\A4" = load i131, i131* %"test\C3\B3\C5\82\C4\99\C4\85\C5\BC\C5\BA\C7\B7\C6\BFwwoo\C5\81\C4\84\C5\BB\C5\B9\C6\A4\C6\A4\C6\A4.addr"
  %call_printf3 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([9 x i8], [9 x i8]* @global_str.5, i32 0, i32 0), i131 %"test\C3\B3\C5\82\C4\99\C4\85\C5\BC\C5\BA\C7\B7\C6\BFwwoo\C5\81\C4\84\C5\BB\C5\B9\C6\A4\C6\A4\C6\A4")
  store i64* %var1.addr, i64** %ptr1.addr
  %load_ptr1 = load i64*, i64** %ptr1.addr
  %dereference_ptr1 = load i64, i64* %load_ptr1
  %load_ptr14 = load i64*, i64** %ptr1.addr
  store i64 66, i64* %load_ptr14
  %load_ptr15 = load i64*, i64** %ptr1.addr
  %dereference_ptr16 = load i64, i64* %load_ptr15
  %var17 = load i64, i64* %var1.addr
  %call_printf8 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @global_str.6, i32 0, i32 0), i64 %dereference_ptr16, i64 %var17)
  %call_puts9 = call i32 @puts(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @global_str.7, i32 0, i32 0))
  %call_printf10 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @global_str.8, i32 0, i32 0), i15 142)
  %call_printf11 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @global_str.9, i32 0, i32 0), double 0x4051B99999999999)
  %call_sin = call double @sin(double 1.000000e+00)
  store double %call_sin, double* %z.addr
  %z = load double, double* %z.addr
  %assign_op_load = load double, double* %z.addr
  %CreateFAdd = fadd double %assign_op_load, 1.000000e+01
  store double %CreateFAdd, double* %z.addr
  %z12 = load double, double* %z.addr
  %call_printf13 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @global_str.10, i32 0, i32 0), double %z12)
  %call_puts14 = call i32 @puts(i8* getelementptr inbounds ([1 x i8], [1 x i8]* @global_str.11, i32 0, i32 0))
  %call_puts15 = call i32 @puts(i8* getelementptr inbounds ([11 x i8], [11 x i8]* @global_str.12, i32 0, i32 0))
  br i1 true, label %if16, label %merge18

if16:                                             ; preds = %merge
  %call_puts17 = call i32 @puts(i8* getelementptr inbounds ([9 x i8], [9 x i8]* @global_str.13, i32 0, i32 0))
  br label %merge18

merge18:                                          ; preds = %if16, %merge
  br i1 false, label %if19, label %else21

if19:                                             ; preds = %merge18
  %call_puts20 = call i32 @puts(i8* getelementptr inbounds ([8 x i8], [8 x i8]* @global_str.14, i32 0, i32 0))
  br label %merge27

else21:                                           ; preds = %merge18
  br i1 false, label %if22, label %else24

if22:                                             ; preds = %else21
  %call_puts23 = call i32 @puts(i8* getelementptr inbounds ([8 x i8], [8 x i8]* @global_str.15, i32 0, i32 0))
  br label %merge26

else24:                                           ; preds = %else21
  %call_puts25 = call i32 @puts(i8* getelementptr inbounds ([11 x i8], [11 x i8]* @global_str.16, i32 0, i32 0))
  br label %merge26

merge26:                                          ; preds = %else24, %if22
  br label %merge27

merge27:                                          ; preds = %merge26, %if19
  br i1 true, label %if28, label %merge30

if28:                                             ; preds = %merge27
  %call_puts29 = call i32 @puts(i8* getelementptr inbounds ([20 x i8], [20 x i8]* @global_str.17, i32 0, i32 0))
  br label %merge30

merge30:                                          ; preds = %if28, %merge27
  %call_puts31 = call i32 @puts(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @global_str.18, i32 0, i32 0))
  store i64 2897243191381164643, i64* %f1Input.addr
  %f1Input = load i64, i64* %f1Input.addr
  %call_func1 = call i64 @func1(i64 %f1Input)
  store i64 %call_func1, i64* %f1Result.addr
  %f1Input32 = load i64, i64* %f1Input.addr
  %f1Result = load i64, i64* %f1Result.addr
  %call_printf33 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @global_str.19, i32 0, i32 0), i64 %f1Input32, i64 %f1Result)
  %call_func2 = call double @func2(i32 1, double 2.000000e+00, double 3.000000e+00)
  %call_printf34 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([18 x i8], [18 x i8]* @global_str.20, i32 0, i32 0), i5 1, double 2.000000e+00, double 3.000000e+00, double %call_func2)
  %call_puts35 = call i32 @puts(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @global_str.21, i32 0, i32 0))
  call void @func3(i64 4)
  store i64 1, i64* %a.addr
  store i64 2, i64* %b.addr
  store i64 3, i64* %b.addr36
  store double 1.230000e+02, double* %precFloat.addr
  %precFloat = load double, double* %precFloat.addr
  %0 = fptosi double %precFloat to i64
  store i64 %0, i64* %precInt.addr
  %precInt = load i64, i64* %precInt.addr
  %1 = trunc i64 %precInt to i8
  store i8 %1, i8* %precFloatSmall.addr
  %precFloat37 = load double, double* %precFloat.addr
  %2 = fpext double %precFloat37 to fp128
  store fp128 %2, fp128* %precFloatBig.addr
  %call_puts38 = call i32 @puts(i8* getelementptr inbounds ([19 x i8], [19 x i8]* @global_str.22, i32 0, i32 0))
  %call_puts39 = call i32 @puts(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @global_str.23, i32 0, i32 0))
  %call_puts40 = call i32 @puts(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @global_str.24, i32 0, i32 0))
  ret void
}

declare double @sin(double)

declare i32 @puts(i8*)

declare i32 @printf(i8*, ...)

define i64 @func1(i64 %a) {
"func1 entrypoint":
  %a.addr = alloca i64
  store i64 %a, i64* %a.addr
  %a1 = load i64, i64* %a.addr
  %CreateDiv = sdiv i64 %a1, 12
  ret i64 %CreateDiv
}

define double @func2(i32 %a, double %b, double %c) {
"func2 entrypoint":
  %a.addr = alloca i32
  store i32 %a, i32* %a.addr
  %b.addr = alloca double
  store double %b, double* %b.addr
  %c.addr = alloca double
  store double %c, double* %c.addr
  %a1 = load i32, i32* %a.addr
  %b2 = load double, double* %b.addr
  %0 = sitofp i32 %a1 to double
  %CreateFAdd = fadd double %0, %b2
  %c3 = load double, double* %c.addr
  %CreateFAdd4 = fadd double %CreateFAdd, %c3
  ret double %CreateFAdd4
}

define void @func3(i64 %counter) {
"func3 entrypoint":
  %counter.addr = alloca i64
  store i64 %counter, i64* %counter.addr
  %counter1 = load i64, i64* %counter.addr
  %binaryCmpICMP_SGT = icmp sgt i64 %counter1, 0
  br i1 %binaryCmpICMP_SGT, label %if, label %merge

if:                                               ; preds = %"func3 entrypoint"
  %counter2 = load i64, i64* %counter.addr
  %CreateSub = sub i64 %counter2, 1
  call void @func3(i64 %CreateSub)
  br label %merge

merge:                                            ; preds = %if, %"func3 entrypoint"
  %counter3 = load i64, i64* %counter.addr
  %call_printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([19 x i8], [19 x i8]* @global_str, i32 0, i32 0), i64 %counter3)
  ret void
}
