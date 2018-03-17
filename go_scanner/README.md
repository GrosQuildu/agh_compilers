# Golang scanner in C

Lexical analyzer (scanner) for go language in C. It scans go source code and returns tokens.

Main token types (full definition in go\_scanner.h):
```
Identifiers
Keywords
Numbers
Strings
Chars
Comments
Operators
Errors
```

### Build'n'run
```bash
make
./go2html test.go out.html  # go source -> tokens -> highlighted go source
./go2html test.go --debug  # list tokens
```
