# Bug 29 – Variable Reset Inside Loop

## Bug Description
`acc = 0` is placed **inside** the loop body as the first statement, which resets the accumulator to zero at the start of every iteration. All previous computation is thrown away each cycle.

---

## Python (`main.py`)
### Buggy Lines
```python
for i in range(10):
    acc = 0          # BUG: resets accumulator every iteration
    acc ^= i * 0x6C62272E07BB0142
    ...
```
### Fixed Lines
```python
acc = 0              # FIX: initialise BEFORE the loop, not inside it
for i in range(10):
    acc ^= i * 0x6C62272E07BB0142
    ...
```
### Lines Changed: **Line 6 removed from inside loop; already present before loop**
### Output
```
Zsug6Utxa2g=
```

---

## Java (`main.java`)
### Buggy Line (inside loop)
```java
acc = 0;
```
### Fixed: Remove that line from inside the loop (it belongs before it)
### Line Changed: **Line 8**
### Output
```
Zsug6Utxa2g=
```

---

## C (`main.c`)
### Buggy Line (inside loop)
```c
acc = 0;
```
### Fixed: Remove that line from inside the loop
### Line Changed: **Line 36**
### Output
```
Zsug6Utxa2g=
```

---

## C++ (`main.cpp`)
### Buggy Line (inside loop)
```cpp
acc = 0;
```
### Fixed: Remove that line from inside the loop
### Line Changed: **Line 39**
### Output
```
Zsug6Utxa2g=
```

---

## JavaScript (`main.js`)
### Buggy Line (inside loop)
```js
acc = 0n;
```
### Fixed: Remove that line from inside the loop
### Line Changed: **Line 4**
### Output
```
Zsug6Utxa2g=
```
