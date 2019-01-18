# Go2LLVM


LLVM based compiler for Golang like language.

## General info

Written in C++. Uses ANTLR4 (c++ API) as a parser generator and LLVM (version 6) for code generation.

## Tokens
[[https://github.com/GrosQuildu/agh_compilers/blob/master/go_parser/Go2LLVM.g4#L246|plik G4]]

```
LEXER
string_tok = '"' {'\"' | unicode_value | byte_value} '"'

unicode_value    = unicode_char | escaped_char .
unicode_char = /* an arbitrary Unicode code point except newline */ .

escaped_char     = `\` ( "a" | "b" | "f" | "n" | "r" | "t" | "v" | `\` | "'" | `"` ) .

letter           = unicode_letter | '_'
unicode_letter = /* long list of unicode letters */;

byte_value       = octal_byte_value | hex_byte_value
octal_byte_value = '\' octal_digit octal_digit octal_digit;
hex_byte_valye = '\x' hex_digit hex_digit

bool_tok = true | false
int_tok = (1..9) {(1..9)} | 0 {(0..7)} | 0 (x | X) {(0..9 | a..f | A..F)}
float_tok = {(1..9)} '.' [{(1..9)}] | '.' [{(1..9)}]

unary_op_tok = ('+' | '-' | '!' | '*' | '&')
binary_op_tok = ('||' | '&&' | '==' | '!=' | '<' | '<=' | '>' | '>=' | '+' | '-' | '|' | '^'' | '*' | '/' | '%' | '<<' | '>>' | '&' | '&^')

//keywords
package_tok = 'package'
var_tok = 'var'
func_tok = 'func'
return_tok = 'return'
if_tok = 'if'
ekse_tok = 'else'
ident_tok =  (a..z | _) {(a..z | _) | (0..9)}
        
// Whitespace and comments
line_comment = '/' [{.*}]
comment = '/*' [{.*}] '*/'
whitespace = '\t '
statement_termination = (';' | '\n' | comment)  
```

##  Grammar
[[https://github.com/GrosQuildu/agh_compilers/blob/master/go_parser/Go2LLVM.g4#L68|plik G4]]

```
PARSER
// top level stuff
SourceFile = PackageClause Eos { TopLevelDecl Eos }
PackageClause = "package" ident_tok

TopLevelDecl = Declaration | FunctionDecl

Block = "{" StatementList "}"
Type = [*] IDENT_TOK
EOS = statement_termination

// Statements
StatementList = { Statement EOS }
Statement = Declaration | SimpleStmt | Block | ReturnStmt | IfStmt

IfStmt = 'if' [SimpleStmt ';'] Expression Block ['else' (IfStmt | Block)]       
ReturnStmt = "return" [ExpressionList]

SimpleStmt = EmptyStmt | Expression | Assignment
Assignment = identifierList [('+' | '-' | '|' | '^' | '*' | '/' | '%' | '<<' | '>>' | '&')] '=' expressionList
EmptyStmt = ";"


// Declarations
Declaration = "var" IdentifierList Type ["=" ExpressionList]
IdentifierList = ident_tok { "," ident_tok }


// Expressions
Expression = UnaryExpr | Expression binary_op_tok Expression
binary_op_tok=('*' | '/' | '%' | '<<' | '>>' | '&' | '&^' | '+' | '-' | '|' | '^' | '==' | '!=' | '<' | '<=' | '>' | '>=' | '&&' | '||')

UnaryExpr = unary_op_tok UnaryExpr | operand
unary_op_tok=('*' | '&' | '+' | '-' | '!' | '^')

ExpressionList = Expression { "," Expression }


// Operands
Operand = basicLit | ident_tok | ident_tok Arguments | "(" Expression ")"

Arguments '(' [ExpressionList [',']] ')'

BasicLit = int_tok | float_tok | imag_tok  | string_tok | bool_tok


// Functions
Function = func_tok ident_tok signature [block]
Signature = parameters [result]
Result = type

Parameters = '(' [parameterList [',']] [...] ')'
ParameterList = parameterDecl { COMMA parameterDecl }
ParameterDecl = identifielList type
```

##  Input language

### header
    	
File have to start with: `package id` (id is not realy used for anything).

### variables

Variable declaration: `var var_name type`.

Variables declared outside of any function are global.

Variables scope is restricted to a block (between `{` and `}`) and superior bloks. 

Example:
```go
package small

func main() {
	var y int;
	y = 5;
	var x float = -1.1 * 5;
	return;
}
```

```llvm
define void @main() {
"main entrypoint":
  %x.addr = alloca double
  %y.addr = alloca i64         ; alokacja pamięci na zmienne
  %y = load i64, i64* %y.addr  ; pobierz wartość y, nieużywane
  store i64 5, i64* %y.addr    ; zapisz liczbę 5 do y
  store double -5.500000e+00, double* %x.addr
  ret void
}
```

### types

Allowed types are: `intX` (X is a bit amount, between `1` and `(1<<24)-1`), `floatX` (X is one of: 16, 32, 64, 128), bool. 

Types are dynamically typed. In expression "best possible" casting is used. In assignments right hand is casted to left hang side type.

If casting loose precision (i.e. `int64`->`int7` or `float`->`int`) warning is generated.e.

All types are signed.

== arithmetic ==

Implemented binary operators (in order of precedence):
```
  - * | / | % | << | >> | & | &^
  - + | - | | | ^
  - == | != | < | <= | > | >=
  - &&
  - ||
```

Unary operators:
  ```- - | !```

Precedence is enforced on gramma level.

```go
package small

func main() {
	var x int;
	x += 5;
	x *= 3

	var y float
	y = 5.4 * x
	return;
}
```

```llvm
define void @main() {
"main entrypoint":
  %y.addr = alloca double
  %x.addr = alloca i64
  
  ; addition
  %x = load i64, i64* %x.addr
  %assign_op_load = load i64, i64* %x.addr
  %binaryAdd = add i64 %assign_op_load, 5
  store i64 %binaryAdd, i64* %x.addr
  
  ; multiplication
  %x1 = load i64, i64* %x.addr
  %assign_op_load2 = load i64, i64* %x.addr
  %CreateMul = mul i64 %assign_op_load2, 3
  store i64 %CreateMul, i64* %x.addr
  
  ; multiplication with var (sitofp is casting instruction)
  %y = load double, double* %y.addr
  %x3 = load i64, i64* %x.addr
  %0 = sitofp i64 %x3 to double
  %CreateFMul = fmul double 5.400000e+00, %0
  store double %CreateFMul, double* %y.addr
  ret void
}
```

### functions

"Main" function is the first executed, must be defined.

Functions can have arguments (in form of `(arg1, arg type, arg3 typ2)`).

Return value occurs after arguments and is optional.

Every function have to end with `return expression` (even if it return nothing, then `expression` should be empty).

Functions can be only declared (without body). But they need to be defined afterwards (so "forward references" are possible).

If definition of a function won't be provided, it will be treated as function from `libc` library.

```go
package small

func puts(a *int8) int32
func printf(a *int8, ...) int32

func test_func(a int, b float) int77 {
	puts("start test_func");
	return a+b;
}

func main() {
	printf("%d\n", test_func(2, 3));
	return;
}
```

```llvm
; constant strings
@global_str = private unnamed_addr constant [16 x i8] c"start test_func\00"
@global_str.1 = private unnamed_addr constant [4 x i8] c"%d\0A\00"


define void @main() {
"main entrypoint":
  ; call test_func 
  %call_test_func = call i77 @test_func(i64 2, double 3.000000e+00)
  
  ; call printf
  %call_printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @global_str.1, i32 0, i32 0), i77 %call_test_func)
  ret void
}

; libc functions declarations
declare double @sin(double %a)

declare i32 @puts(i8* %a)

declare i32 @printf(i8* %a, ...)


define i77 @test_func(i64 %a, double %b) {
"test_func entrypoint":
  ; "mutable" argumets
  %a.addr = alloca i64
  store i64 %a, i64* %a.addr
  %b.addr = alloca double
  store double %b, double* %b.addr
  
  %call_puts = call i32 @puts(i8* getelementptr inbounds ([16 x i8], [16 x i8]* @global_str, i32 0, i32 0))
  
  ; two casting operations
  %a1 = load i64, i64* %a.addr
  %b2 = load double, double* %b.addr
  %0 = sitofp i64 %a1 to double
  %CreateFAdd = fadd double %0, %b2
  %1 = fptosi double %CreateFAdd to i77
  
  ; return value
  ret i77 %1
}
```

### pointers

Syntax: `var var_name *type`

Address assignemnt: `var_name = &other_var`

Dereferene: `*var_name`

Value assignemnts: `*var_name = 5`

Pointers are strictly typed.

### conditional expressions

Syntax: `if expression {} else if expression {} else {}`

```go
package small

func printf(a *int8, ...) int32

func test_func(a int) {
	if a >= 0 {
		printf("a = %d\n", a)
		test_func(a-1)
	} else if a == -1 {
		printf("almost end\n")
		test_func(-99)
	} else {
		printf("end\n")
	}
	return
}

func main() {
	test_func(5)
	return;
}
```

```llvm
@global_str = private unnamed_addr constant [8 x i8] c"a = %d\0A\00"
@global_str.1 = private unnamed_addr constant [12 x i8] c"almost end\0A\00"
@global_str.2 = private unnamed_addr constant [5 x i8] c"end\0A\00"

define void @main() {
"main entrypoint":
  call void @test_func(i64 5)
  ret void
}

declare i32 @printf(i8* %a, ...)


define void @test_func(i64 %a) {
"test_func entrypoint":
  %a.addr = alloca i64
  store i64 %a, i64* %a.addr
  
  ; compare "a" with 0 and jump to "if" or "else" block
  %a1 = load i64, i64* %a.addr
  %binaryCmpICMP_SLE = icmp sge i64 %a1, 0
  br i1 %binaryCmpICMP_SLE, label %if, label %else

; if a >= 0
if:                                               ; preds = %"test_func entrypoint"
  %a2 = load i64, i64* %a.addr
  %call_printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([8 x i8], [8 x i8]* @global_str, i32 0, i32 0), i64 %a2)
  %a3 = load i64, i64* %a.addr
  %CreateSub = sub i64 %a3, 1
  call void @test_func(i64 %CreateSub)
  br label %merge9

; if a < 0
else:                                             ; preds = %"test_func entrypoint"
  %a4 = load i64, i64* %a.addr
  %binaryCmpICMP_EQ = icmp eq i64 %a4, -1
  br i1 %binaryCmpICMP_EQ, label %if5, label %else7

; if a == -1
if5:                                              ; preds = %else
  %call_printf6 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @global_str.1, i32 0, i32 0))
  call void @test_func(i64 -99)
  br label %merge

; any other case
else7:                                            ; preds = %else
  %call_printf8 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @global_str.2, i32 0, i32 0))
  br label %merge

merge:                                            ; preds = %else7, %if5
  br label %merge9

merge9:                                           ; preds = %merge, %if
  ret void
}
```

## Complete example

```go
package examples

/*
** multiline comment
*/

// external functions
func sin(a float) float
func puts(a *int8) int32
func printf(a *int8, ...) int32

// func1 declaration
func func1(a int) int;

func func2(a int32, b, c float) float {
	return a+b+c;
}

func func3(counter int) {
	if counter > 0 {
		func3(counter-1);
	}
	printf("func3, counter %d\n", counter);
	return;
}

func main() {

	// basic variables
	var var1 int = 5;
	var var2 int7331 = 4444
	var var3 float = -.11;
	var var4 float128 = 1234;
	printf("vars: %d, %d, %f, %a\n", var1, var2, var3, var4);

	// hex/oct
	var var5 int = 0x123;
	var var6 int = 0123;
	printf("vars2: %x %d\n", var5, var6);

	// identifiers may be unicode letters and underscore _
	var testółęążźǷƿwwooŁĄŻŹƤƤƤ int131 = 123;
	printf("bum: %d\n", testółęążźǷƿwwooŁĄŻŹƤƤƤ)

	// pointers
	var ptr1 *int = &var1;
	*ptr1 = 66;
	printf("ptr: %d, %d\n", *ptr1, var1);
	// ptr1 = &var2; // can't do that, pointers' types must be exact

	// arithmetic
	puts("\narithmetic:");
	printf("%d\n", (1+2*341/4)%100 << 2 >> 1 & (11 | 2222 ^ 1));
	printf("%f\n", (1.1+2*341/4)%100.2);

	var z float = 10;
	z += 2.2;
	printf("%f\n", z);
	puts("");

	// branches
	puts("\nbranches:");
	if 12 == 12 {
		puts("12 == 12");
	}
	if 12 ==13 {
		puts("12 ==13");
	} else if 12 == 14 {
		puts("12 ==14");
	} else {
		puts("12 -> else");
	}

	if (12*2) >= 0 {
		puts("var1*var2*var3 <= 0");
	}

	// functions
	puts("\nfunctions:");
	var f1Input int = 0x515551111111111112835135512318263;
	var f1Result int = func1(f1Input);
	printf("f1(%d): %d\n", f1Input, f1Result)
	printf("f2(%d,%f,%f): %f\n", 1, 2.0, 3.0, func2(1,2.0,3));


	// recursion
	puts("\nrecursion:");
	func3(4);


	// scopes
	// scopes are defined by {}, for example
	{
		var a int = 1;
		{
			// var a = 2; // can't redeclare
			var b int = 2;
		}
		var b int = 3;  // that's ok, b from previous block is out of the current scope
	}

	// casting
	// auto-casting is supported, in ambiguous situations best possible casting is chosen
	// except on declarations (with 'var'), right-hand-side is always casted to variable in this situations
	// if casting loose precision, warning is shown
	var precFloat float = 123;
	var precInt int = precFloat;  // warning
	var precFloatSmall int8 = precInt // warning
	var precFloatBig float128 = precFloat; // no warning

	// string formating
	puts("string formatting:");
	puts("\x41\x42\x20");

	// statements ending
	// may be with newline or with semicolon ;

	puts("end");
	return;
}


// func1 definition
func func1(a int) int {
	return a / 12;
}
```

## Build & run
```bash
# ANTLR -> generate parser
$ java -jar antlr-4.7.1-complete.jar -Werror -Dlanguage=Cpp -listener -visitor -o src/generated/ -package go_parser Go2LLVM.g4

# build (llvm libs have to be installed)
$ cmake .
$ make -j2

# run
$ ./cmake-build-debug/go_parser
Usage ./cmake-build-debug/go_parser file.go [-o | --out file.ll]

# example
$ /cmake-build-debug/go_parser examples/all.go && clang++ -g -lm examples/all.ll -o ./examples/all.bin && ./examples/all.bin
```
