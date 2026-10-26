# Simple C Find Largest & Smallest Integers

A modular C application that determines the maximum and minimum values among three input integers. Built to illustrate structured functional decomposition, pure function design with value-parameter passing, and defensive input validation.

---

## Architectural Pipeline

The application isolates evaluation logic from console I/O, using `main(void)` strictly as an input/output dispatcher while delegating comparison routines to dedicated pure functions:

```text
                           [ main(void) ]
                                 |
                     +-----------+-----------+
                     |                       |
                     v                       v
            [ findLargest(a,b,c) ]   [ findSmallest(a,b,c) ]
             - Assume max = a         - Assume min = a
             - Compare b > max        - Compare b < min
             - Compare c > max        - Compare c < min
             - Return max             - Return min
                     |                       |
                     +-----------+-----------+
                                 |
                                 v
                     [ Display Largest/Smallest ]
```

---

## Comparison Logic & Mechanics

Instead of nested ternary expressions or compound logical operators (`&&`), both subfunctions utilize the classic incremental update pattern:
1. Initialize the running extremal value to the first argument (`max = a`).
2. Conditionally update if the second argument exceeds the running extreme (`if (b > max) max = b;`).
3. Conditionally update if the third argument exceeds the running extreme (`if (c > max) max = c;`).
4. Return the finalized extreme value to the caller.

This guarantees optimal comparison efficiency (exactly two comparisons per function) and predictable linear control flow.

---

## Empirical Verification & Test Matrix

Compiled using `gcc -Wall -Wextra -Werror` and verified against multi-scenario test sets:

| Test Scenario | Input Integers (`num1, num2, num3`) | `findLargest()` Output | `findSmallest()` Output | Status |
| :--- | :---: | :---: | :---: | :---: |
| **Ascending Order** | `10 25 50` | `50` | `10` | **PASS** |
| **Descending Order** | `99 42 7` | `99` | `7` | **PASS** |
| **Negative Integers** | `-15 -3 -40` | `-3` | `-40` | **PASS** |
| **Mixed Signs** | `-20 0 15` | `15` | `-20` | **PASS** |
| **Identical Values** | `8 8 8` | `8` | `8` | **PASS** |
| **Two Equal Values** | `14 28 14` | `28` | `14` | **PASS** |

---

## Compilation & Execution

### Using GCC (MinGW / Linux / macOS):
```bash
gcc -Wall -Wextra -Werror Simple-c-find-largest-and-smallest-integers.c -o find_extremes
./find_extremes
```

### Sample Interactive Output:
```text
Enter three integers: 45 12 89
Largest number: 89
Smallest number: 12
```

---

## Static Safety Audit
Scanned using static analysis security scanner:
- Unsafe unbounded calls (`gets`, bare `scanf("%s")`): **0 findings**
- Shell injection / pipe traps: **0 findings**
- Return code validation: Enforces `3 != scanf("%d %d %d", ...)` to prevent uninitialized memory reads on malformed input.
