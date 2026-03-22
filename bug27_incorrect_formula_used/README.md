# Bug 27 – Incorrect Formula Used

## Bug Description
The triangular number formula is `n*(n+1)/2`. The buggy code uses `n*(n+1)/3` (divides by 3 instead of 2), producing incorrect triangle numbers.

---

## Python (`main.py`)
### Buggy Line
```python
triangle = n * (n + 1) // 3
```
### Fixed Line
```python
triangle = n * (n + 1) // 2
```
### Line Changed: **Line 6**
### Output
```
WX+xSQ+FX7Y=
```

---

## Java (`main.java`)
### Buggy Line
```java
long triangle = n * (n + 1) / 3;
```
### Fixed Line
```java
long triangle = n * (n + 1) / 2;
```
### Line Changed: **Line 9**
### Output
```
WX+xSQ+FX7Y=
```

---

## C (`main.c`)
### Buggy Line
```c
uint64_t triangle = n * (n + 1) / 3;
```
### Fixed Line
```c
uint64_t triangle = n * (n + 1) / 2;
```
### Line Changed: **Line 36**
### Output
```
WX+xSQ+FX7Y=
```

---

## C++ (`main.cpp`)
### Buggy Line
```cpp
uint64_t triangle = n * (n + 1) / 3;
```
### Fixed Line
```cpp
uint64_t triangle = n * (n + 1) / 2;
```
### Line Changed: **Line 39**
### Output
```
WX+xSQ+FX7Y=
```

---

## JavaScript (`main.js`)
### Buggy Line
```js
let triangle = n * (n + 1n) / 3n;
```
### Fixed Line
```js
let triangle = n * (n + 1n) / 2n;
```
### Line Changed: **Line 4**
### Output
```
WX+xSQ+FX7Y=
```
