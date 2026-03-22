# Bug 24 – Wrong Parameter Order

## Bug Description
`weighted_mix()` is called with `weight_val` and `base_val` swapped. The function expects `(base, weight, offset)` but receives `(weight, base, offset)`, producing a wrong result.

---

## Python (`main.py`)
### Buggy Line
```python
wrong = weighted_mix(weight_val, base_val, offset_val)
```
### Fixed Line
```python
result = weighted_mix(base_val, weight_val, offset_val)
```
### Line Changed: **Line 16**
### Output
```
w2zc2STRoaw=
```

---

## Java (`main.java`)
### Buggy Line
```java
long wrong = weighted_mix(weight_val, base_val, offset_val);
```
### Fixed Line
```java
long result = weighted_mix(base_val, weight_val, offset_val);
```
### Line Changed: **Line 22**
### Output
```
w2zc2STRoaw=
```

---

## C (`main.c`)
### Buggy Line
```c
uint64_t wrong = weighted_mix(weight_val, base_val, offset_val);
```
### Fixed Line
```c
uint64_t result = weighted_mix(base_val, weight_val, offset_val);
```
### Line Changed: **Line 47**
### Output
```
w2zc2STRoaw=
```

---

## C++ (`main.cpp`)
### Buggy Line
```cpp
uint64_t wrong = weighted_mix(weight_val, base_val, offset_val);
```
### Fixed Line
```cpp
uint64_t result = weighted_mix(base_val, weight_val, offset_val);
```
### Line Changed: **Line 50**
### Output
```
w2zc2STRoaw=
```

---

## JavaScript (`main.js`)
### Buggy Line
```js
let wrong = weighted_mix(weight_val, base_val, offset_val);
```
### Fixed Line
```js
let result = weighted_mix(base_val, weight_val, offset_val);
```
### Line Changed: **Line 14**
### Output
```
w2zc2STRoaw=
```
