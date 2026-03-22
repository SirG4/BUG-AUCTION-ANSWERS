# Bug 18 – Wrong Index Position

## Bug Description
The index expression `9 - step + 1` equals `10` when `step = 0`, which is out of bounds for a 10-element list (valid indices 0–9). The `+1` must be removed.

---

## Python (`main.py`)
### Buggy Line
```python
v = tbl[9 - step + 1] if step < 9 else tbl[0]   # index 10 when step=0
```
### Fixed Line
```python
v = tbl[9 - step]   # correctly counts down from index 9 to 0
```
### Line Changed: **Line 9**
### Output
```
wnpk9gYWGX4=
```

---

## Java (`main.java`)
### Buggy Line
```java
int idx = (step < 9) ? (9 - step + 1) : 0;
```
### Fixed Line
```java
int idx = 9 - step;
```
### Line Changed: **Line 15**
### Output
```
wnpk9gYWGX4=
```

---

## C (`main.c`)
### Buggy Line
```c
int idx = (step < 9) ? (9 - step + 1) : 0;
```
### Fixed Line
```c
int idx = 9 - step;
```
### Line Changed: **Line 42**
### Output
```
wnpk9gYWGX4=
```

---

## C++ (`main.cpp`)
### Buggy Line
```cpp
int idx = (step < 9) ? (9 - step + 1) : 0;
```
### Fixed Line
```cpp
int idx = 9 - step;
```
### Line Changed: **Line 46**
### Output
```
wnpk9gYWGX4=
```

---

## JavaScript (`main.js`)
### Buggy Line
```js
let idx = (step < 9) ? (9 - step + 1) : 0;
```
### Fixed Line
```js
let idx = 9 - step;
```
### Line Changed: **Line 7**
### Output
```
wnpk9gYWGX4=
```
