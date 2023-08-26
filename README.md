# C - Stacks, Queues - LIFO, FIFO

The Monty Bytecode Interpreter is a program written in C programming language that reads and executes Monty bytecode files. Monty is a simple programming language that uses a stack data structure.

## Table of Contents

- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Supported Opcodes](#supported-opcodes)
- [Examples](#examples)
- [Contributors](#contributors)

## Features

- Reads Monty bytecode files and executes the specified instructions.
- Supports various stack manipulation and arithmetic operations.
- Provides clear error messages for incorrect input or unexpected behavior.

## Getting Started

### Prerequisites

- A C compiler (e.g., GCC)

### Installation

1. Clone the repository: 
```
git clone https://github.com/khairatAA/monty
```

2. Compile the source code:
```
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```

## Usage

Run the Monty interpreter with the following command:
```
./monty bytecode_file
```

Replace `bytecode_file` with the path to your Monty bytecode file.

## Supported Opcodes

The interpreter supports the following opcodes:

| Opcodes | File |
| ---- | ---- |
| 0. push | [push.c](./push.c) |
| 1. pint | [pint.c](./pint.c) |
| 2. pop | [pop.c](./pop.c) |
| 3. swap | [swap.c](./swap.c) |
| 4. add | [add.c](./add.c) |
| 5. nop | [nop.c](./nop.c) |
| 6. sub | [sub.c](./sub.c) |
| 7. div | [div.c](./div.c) |
| 8. mul | [mul.c](./mul.c) |
| 9. mod | [mod.c](./mod.c) |
| 10. comments | [hash.c](./hash.c) |
| 11. pchar | [pchar.c](./pchar.c) |
| 12. pstr | [pstr.c](./pstr.c) |
| 13. rotl | [rotl.c](./rotl.c) |
| 14. rotr | [rotr.c](./rotr.c) |
| 15. stack, queue | [SOON](./) |
| 16. Brainfuck | [1000-school.bf](./1000-school.bf) |
| 17. Add two digits | [1001-add.bf](./1001-add.bf) |
| 18. push | [push.c](./push.c) |


## Examples

Here's an example Monty bytecode file that adds two numbers:
```
push 5
push 10
add
pall
```
When executed, the above bytecode will output: `15`

## Contributors

This project was done  by:

- _Khairat Adesina_ <khairatadesina01@gmail.com>
- _Joshua Oseghale_ <aigbokhaebholojoshua@gmail.com>
