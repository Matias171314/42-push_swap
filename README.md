*This project has been created as part of the 42 curriculum by mvasquez.*

# Push Swap

## Description

Push Swap is a sorting project written in C. It sorts unique integers using
two stacks and a restricted set of swap, push and rotation operations.

The goal is to place the integers in ascending order in stack `a`, with the
smallest value at the top and stack `b` empty, while keeping the number of
operations low.

This implementation combines dedicated routines for small inputs with binary
radix sorting for larger inputs. Values are normalized to ranks before sorting,
so negative and positive integers can be handled using the same bitwise logic.

The project explores linked lists, input validation, sorting algorithms and
the distinction between operation count and execution time.

---

## Instructions

### Requirements

- A C compiler providing `cc`.
- `make`.
- A Unix-like environment.

The repository includes the Libft sources used by the program.

### Compilation

```bash
git clone https://github.com/Matias171314/42-push_swap.git
cd 42-push_swap
make re
```

A clean rebuild is recommended because the repository also contains previously
built binaries and `libft.a`.

The Makefile builds Libft and the `push_swap` executable using:

```text
-Wall -Wextra -Werror
```

| Rule | Purpose |
|---|---|
| `make` | Build the library and program when needed. |
| `make clean` | Remove object files. |
| `make fclean` | Remove object files, the library and the executable. |
| `make re` | Perform a clean rebuild. |

### Execution

Pass integers as separate arguments:

```bash
./push_swap 4 67 3 87 23
```

A single argument containing space-separated integers is also supported:

```bash
./push_swap "4 67 3 87 23"
```

The first number becomes the top of stack `a`. Stack `b` starts empty.

### Input validation

The parser checks integer syntax, duplicate values and the signed integer
range defined by `INT_MIN` and `INT_MAX`.

These examples produce `Error` followed by a newline on standard error:

```bash
./push_swap 1 2 1
./push_swap 1 two 3
./push_swap 2147483648
./push_swap ""
```

With no arguments, the program exits without output.

---

## Stack Operations

| Operation | Effect |
|---|---|
| `sa` / `sb` | Swap the top two values of the selected stack. |
| `ss` | Swap the top two values of both stacks. |
| `pa` | Move the top of `b` to the top of `a`. |
| `pb` | Move the top of `a` to the top of `b`. |
| `ra` / `rb` | Move the first element to the end of the selected stack. |
| `rr` | Rotate both stacks. |
| `rra` / `rrb` | Move the last element to the front of the selected stack. |
| `rrr` | Reverse rotate both stacks. |

Operation wrappers print one instruction followed by a newline.
The sorting routines use `sa`, `pa`, `pb`, `ra` and `rra`.

---

## Algorithm and Design

### Stack representation

Each stack is a doubly linked list. A node stores:

| Field | Purpose |
|---|---|
| `value` | Original integer. |
| `index` | Rank among the input values. |
| `next` | Next node toward the bottom of the stack. |
| `prev` | Previous node toward the top of the stack. |

Push operations move nodes between lists. Swap operations exchange both the
value and index of the first two nodes.

### Index normalization

`assign_index` assigns each value the number of input values smaller than it.

| Original value | Rank |
|---|---|
| `-10` | `0` |
| `3` | `1` |
| `42` | `2` |
| `100` | `3` |

For an input ordered as `42 -10 100 3`, the corresponding rank sequence is
`2 0 3 1`.

Sorting these ranks gives the same ordering as sorting the original integers,
while providing a compact non-negative range from `0` to `n - 1`.

### Small inputs

| Input size | Strategy |
|---|---|
| Already sorted | Skip sorting operations. |
| Two values | Swap if needed. |
| Three values | Move the largest value to the bottom, then swap the first two if needed. |
| Four or five values | Move the smallest values to `b`, sort the remaining three, then push the saved values back. |
| More than five values | Apply binary radix sort to normalized indices. |

For four and five values, the minimum is brought to the top using forward or
reverse rotation according to its position, reducing unnecessary rotations.

### Binary radix sort

`radix_sort` processes rank bits from least significant to most significant.

For each bit position:

1. Inspect exactly `n` elements from stack `a`.
2. If the current bit is `1`, rotate `a` with `ra`.
3. If the current bit is `0`, push the element to `b` with `pb`.
4. Push every element from `b` back to `a` with `pa`.

The rotations preserve the relative order of the one-bit group. Moving the
zero-bit group to `b` and back reverses it twice, preserving its order too.
Each pass is therefore a stable partition, allowing successive bit passes to
produce ascending rank order.

### Why this approach?

Specialized routines avoid radix overhead for very small inputs.
Normalization makes radix sorting independent of the sign and magnitude of
the original values.

Binary radix maps directly to the available stack operations and gives a
predictable operation count. It prioritizes a simple sorting strategy rather
than guaranteeing the shortest possible instruction sequence.

### Complexity

- Rank assignment and duplicate detection each use quadratic comparisons.
- Radix emits `O(n log n)` stack instructions.
- Stack storage requires `O(n)` space.
- The current rotation helpers traverse the list to find its tail. A rotation
  can therefore take `O(n)` time, so the radix stage can take
  `O(n² log n)` time despite its smaller instruction count.

Instruction count and CPU complexity are different measures in this project.

---

## Validation and Benchmarks

A clean source build with `make re` succeeded.

An independent operation simulator checked all 153 permutations of sizes one
through five, plus 20 seeded samples across sizes 6, 20, 100 and 500.
The operation sequences sorted `a` and emptied `b`.

For this diagnostic check, the final debug display was excluded from the
operation stream. This is not a successful direct checker validation.

Five sampled inputs at each larger benchmark size produced:

| Input size | Observed operations | Subject target for maximum validation |
|---|---|---|
| 100 | 1084 | Fewer than 700 |
| 500 | 6784 | At most 5500 |

These counts fit one of the subject's minimum-validation benchmark combinations
(under 1100 and under 8500 respectively), but do not reach its maximum-validation
targets. This is an operation-count comparison, not a claim of a passing grade.

### Checker workflow

The repository contains a `checker_linux` binary. It is not a locally
implemented bonus checker; no checker source or `bonus` target is present.

After resolving the output issue described below, use a compatible checker:

```bash
chmod +x checker_linux
./push_swap 4 67 3 87 23 | ./checker_linux 4 67 3 87 23
./push_swap 4 67 3 87 23 | wc -l
```

The checker should report `OK` only when the instructions sort `a` and
leave `b` empty.

### Additional checks

```bash
norminette src include libft
valgrind --leak-check=full --show-leak-kinds=all ./push_swap 5 2 4 1 3
```

Norminette and Valgrind were not run as part of this documentation update.

---

## Current Limitations

The current source is not ready for subject-compliant evaluation:

- `main` calls `print_stack` after sorting. The extra numeric output and stack
  labels violate the required instruction-only output and also appear for
  already sorted inputs.
- Stack nodes and the array created by `ft_split` are not freed before exit.
- Allocation failures during stack construction are not propagated to
  `main` as a clean failure.
- `ft_atol` does not guard against overflow while accumulating very long
  numeric strings.
- The radix strategy exceeds the maximum-validation benchmark targets.

These are implementation issues to address separately from documentation.

---

## Project Structure

| Path | Responsibility |
|---|---|
| `Makefile` | Library and executable build rules. |
| `include/push_swap.h` | Stack structure and function declarations. |
| `src/push_swap.c` | Argument handling, sorting selection and debug display. |
| `src/parsing.c` | Number validation, duplicates and range checks. |
| `src/stack_utils.c` | Node creation, stack construction, size and rank assignment. |
| `src/utils.c` | Error reporting and string-to-long conversion. |
| `src/algorithm/sort.c` | Sorted-state checks and small-input routines. |
| `src/algorithm/radix_sort.c` | Binary radix sorting. |
| `src/operations/` | Swap, push, rotate and reverse-rotate operations. |
| `libft/` | Supporting C library. |
| `checker_linux` | Included checker executable for Linux. |

---

## Resources

- Push Swap subject, version 10.0: rules, output format and benchmark targets.
- [NIST Dictionary of Algorithms and Data Structures: Radix Sort](https://www.nist.gov/dads/HTML/radixsort.html).
- C and POSIX manual pages for memory allocation, output and process exit.
- 42 Norm documentation.

Useful local references:

```bash
man 3 malloc
man 3 free
man 2 write
man 3 exit
```

### Use of AI

For this documentation update, AI assistance was used to:

- inspect the existing sources and compare their behavior with the subject;
- explain index normalization, small-input sorting and binary radix;
- prepare build checks and an independent operation simulator;
- write this README and identify current limitations.

The C sources and Makefiles were not modified during this update.
This section describes the assistance used for documentation; it does not
assert how AI was used during the original implementation.

---

## Author

**mvasquez** · [Matias171314](https://github.com/Matias171314)
