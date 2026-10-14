# Compiler Design Lab

Source code for the Compiler Design lab experiments, plus extra Lex programs.

## Contents

| Folder | Program | Type |
|---|---|---|
| `EXP 01` | `lexical.c` (reads `input.c`) | C |
| `EXP 02` | `prgm.l` | Lex |
| `EXP 03` | `count.l` | Lex |
| `EXP 04` | `vowel.l` | Lex |
| `EXP 05` | `identifier.y` | Yacc |
| `EXP 06` | `epsilon.c` | C |
| `EXP 07` | `enfa.c` | C |
| `EXP 14` | `fandf.c` | C |
| `EXP 15` | `recursive.c` | C |
| `EXP 16` | `shiftreduce.c` | C |
| `EXP 18` | `intermediate_code.c` | C |
| `extra/extra lex programs` | 7 additional Lex programs | Lex |

## Running on Ubuntu

### 1. Install the tools

```bash
sudo apt update
sudo apt install gcc flex bison
```

### 2. Plain C programs

(EXP 01, 06, 07, 14, 15, 16, 18)

```bash
cd "EXP 06"
gcc epsilon.c -o a.out
./a.out
```

`EXP 01` reads `input.c` from the current directory, so run it from inside `EXP 01`.

### 3. Lex programs

(EXP 02, EXP 03, EXP 04, and everything in `extra/extra lex programs`)

```bash
cd "EXP 03"
flex count.l
gcc lex.yy.c -o count
./count
```

Type the input, then press `Ctrl+D` to finish.

If you get an `undefined reference to yywrap` error, add `-lfl`:

```bash
gcc lex.yy.c -o count -lfl
```

### 4. Yacc program

(EXP 05)

```bash
cd "EXP 05"
yacc -d identifier.y
gcc y.tab.c -o identifier
./identifier
```

If the `.y` file depends on a separate lexer, add `-ly` or build it together with the matching `.l` file.

### 5. Extra Lex programs

```bash
cd "extra/extra lex programs"
flex 4_count_uppercase_lowercase.l
gcc lex.yy.c -o out
./out
```

Generated files (`lex.yy.c`, `y.tab.c`, `y.tab.h`, `a.out`) are git-ignored.
