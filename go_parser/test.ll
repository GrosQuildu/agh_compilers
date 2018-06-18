; ModuleID = 'Go2LLVM module'

@global_str = private unnamed_addr constant [4 x i8] c"%d\0A\00"

define void @main() {
"main entrypoint":
  %i.addr = alloca i32
  %0 = sext i4 5 to i32
  store i32 %0, i32* %i.addr
  %i = load i32, i32* %i.addr
  %1 = sext i4 2 to i32
  %binaryMul = mul i32 %i, %1
  %x.addr = alloca i322
  %2 = sext i32 %binaryMul to i322
  store i322 %2, i322* %x.addr
  %x = load i322, i322* %x.addr
  %call_printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @global_str, i32 0, i32 0), i322 %x)
  ret void
}

declare i32 @puts(i8*)

declare i32 @printf(i8*, ...)

define i32 @test1(i32 %a) {
"test1 entrypoint":
  %a.addr = alloca i32
  store i32 %a, i32* %a.addr
  %a1 = load i32, i32* %a.addr
  %0 = sext i4 2 to i32
  %binaryAdd = add i32 %0, %a1
  ret void
}
