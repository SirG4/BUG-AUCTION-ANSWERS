# Bug 30 – Wrong Operator Precedence

## Bug Description
In `acc ^ v << i + 1`, the shift operator (`<<`) has higher precedence than XOR (`^`), so it evaluates as `acc ^ (v << (i + 1))`. The intended logic is `(acc ^ v) << (i + 1)` — XOR first, then shift. Missing parentheses cause the wrong result.

---

## Python (`main.py`)
### Buggy Line
```python
shifted = acc ^ v << i + 1        # evaluates as: acc ^ (v << (i+1))
```
### Fixed Line
```python
shifted = (acc ^ v) << (i + 1)    # XOR first, then shift
```
### Line Changed: **Line 8**
### Output
```
TktdrrG4AEU=
```

---

## Java (`main.java`)
### Buggy Line
```java
long shifted = acc ^ v << i + 1;
```
### Fixed Line
```java
long shifted = (acc ^ v) << (i + 1);
```
### Line Changed: **Line 10**
### Output
```
TktdrrG4AEU=
```

---

## C (`main.c`)
### Buggy Line
```c
uint64_t shifted = acc ^ v << i + 1;
```
### Fixed Line
```c
uint64_t shifted = (acc ^ v) << (i + 1);
```
### Line Changed: **Line 37**
### Output
```
TktdrrG4AEU=
```

---

## C++ (`main.cpp`)
### Buggy Line
```cpp
uint64_t shifted = acc ^ v << i + 1;
```
### Fixed Line
```cpp
uint64_t shifted = (acc ^ v) << (i + 1);
```
### Line Changed: **Line 40**
### Output
```
TktdrrG4AEU=
```

---

## JavaScript (`main.js`)
### Buggy Lines
```js
let shiftVal = BigInt.asUintN(64, v << (i + 1n));
let shifted = acc ^ shiftVal;      // shift applied BEFORE XOR
```
### Fixed Lines
```js
let shifted = BigInt.asUintN(64, (acc ^ v) << (i + 1n));   // XOR first, then shift
```
### Lines Changed: **Lines 5–6**
### Output
```
TktdrrG4AEU=
```
