# Bug 20 – Index Used Instead of Value

## Bug Description
The loop accumulates using `i` (the index: 0–9) instead of `v` (the actual value: 0x100–0xA00). Both the XOR operation and the bit-shift use the wrong variable.

---

## Python (`main.py`)
### Buggy Lines
```python
acc = (acc ^ i) * 0x9E3779B97F4A7C15        # should be ^ v
acc = ((acc << (i % 15 + 1)) | ...)          # should shift by v
acc ^= i >> 2                                # should be v >> 2
```
### Fixed Lines
```python
acc = (acc ^ v) * 0x9E3779B97F4A7C15
acc = ((acc << (v % 15 + 1)) | ...)
acc ^= v >> 2
```
### Lines Changed: **Lines 10, 12, 13**
### Output
```
8Youtfk63uA=
```

---

## Java (`main.java`)
### Buggy Lines
```java
acc ^= i;
long sl = i % 15 + 1, sr = 63 - (i % 15);
acc ^= i >>> 2;
```
### Fixed Lines
```java
acc ^= v;
long sl = v % 15 + 1, sr = 63 - (v % 15);
acc ^= v >>> 2;
```
### Lines Changed: **Lines 13, 14, 17**
### Output
```
8Youtfk63uA=
```

---

## C (`main.c`)
### Buggy Lines
```c
acc ^= i;
acc = (acc << (i%15+1)) | (acc >> (63-(i%15)));
acc ^= i >> 2;
```
### Fixed Lines
```c
acc ^= v;
acc = (acc << (v%15+1)) | (acc >> (63-(v%15)));
acc ^= v >> 2;
```
### Lines Changed: **Lines 37, 38, 40**
### Output
```
8Youtfk63uA=
```

---

## C++ (`main.cpp`)
### Buggy Lines
```cpp
acc ^= i;
acc = (acc << (i%15+1)) | (acc >> (63-(i%15)));
acc ^= i >> 2;
```
### Fixed Lines
```cpp
acc ^= v;
acc = (acc << (v%15+1)) | (acc >> (63-(v%15)));
acc ^= v >> 2;
```
### Lines Changed: **Lines 42, 43, 45**
### Output
```
8Youtfk63uA=
```

---

## JavaScript (`main.js`)
### Buggy Lines
```js
acc ^= i;
let sl = i % 15n + 1n, sr = 63n - (i % 15n);
acc ^= i >> 2n;
```
### Fixed Lines
```js
acc ^= v;
let sl = v % 15n + 1n, sr = 63n - (v % 15n);
acc ^= v >> 2n;
```
### Lines Changed: **Lines 7, 8, 11**
### Output
```
8Youtfk63uA=
```
