# Bug 25 – Wrong Arguments Passed

## Bug Description
`xor_chain(key, data)` is called with arguments in the wrong order. The function's first parameter is `values` (expects the list) and the second is `key` (expects the integer). Passing them reversed causes a type error.

---

## Python (`main.py`)
### Buggy Line
```python
result = xor_chain(key, data)
```
### Fixed Line
```python
result = xor_chain(data, key)
```
### Line Changed: **Line 14**
### Output
```
CnL/4aPqUSQ=
```

---

## Java (`main.java`)
### Buggy Lines
```java
throw new IllegalArgumentException("TypeError: 'int' object is not iterable");
```
### Fixed Line
```java
long result = xor_chain(data, key);
```
### Line Changed: **Lines 14–15**
### Output
```
CnL/4aPqUSQ=
```

---

## C (`main.c`)
### Buggy Lines
```c
fprintf(stderr, "TypeError: 'int' object is not iterable\n");
exit(1);
```
### Fixed Line
```c
uint64_t result = xor_chain(data, 10, key);
```
### Lines Changed: **Lines 44–45**
### Output
```
CnL/4aPqUSQ=
```

---

## C++ (`main.cpp`)
### Buggy Line
```cpp
throw std::runtime_error("TypeError: 'int' object is not iterable");
```
### Fixed Line
```cpp
uint64_t result = xor_chain(data, key);
```
### Line Changed: **Line 44**
### Output
```
CnL/4aPqUSQ=
```

---

## JavaScript (`main.js`)
### Buggy Line
```js
let result = xor_chain(key, data);
```
### Fixed Line
```js
let result = xor_chain(data, key);
```
### Line Changed: **Line 13**
### Output
```
CnL/4aPqUSQ=
```
