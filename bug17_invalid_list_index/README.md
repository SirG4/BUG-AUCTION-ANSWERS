# Bug 17 – Invalid List Index

## Bug Description
`step * 3 % 11` can produce index `10` (when step=7: 7×3=21, 21%11=10), which is out of bounds for a 10-element list (valid indices: 0–9). The modulus must match the list size.

---

## Python (`main.py`)
### Buggy Line
```python
idx = step * 3 % 11   # can produce index 10 → IndexError
```
### Fixed Line
```python
idx = step * 3 % 10   # stays within 0–9
```
### Line Changed: **Line 8**
### Output
```
+PQ4mUgVMrU=
```

---

## Java (`main.java`)
### Buggy Line
```java
int idx = step * 3 % 11;
```
### Fixed Line
```java
int idx = step * 3 % 10;
```
### Line Changed: **Line 12**
### Output
```
+PQ4mUgVMrU=
```

---

## C (`main.c`)
### Buggy Line
```c
int idx = step * 3 % 11;
```
### Fixed Line
```c
int idx = step * 3 % 10;
```
### Line Changed: **Line 36**
### Output
```
+PQ4mUgVMrU=
```

---

## C++ (`main.cpp`)
### Buggy Line
```cpp
int idx = step * 3 % 11;
```
### Fixed Line
```cpp
int idx = step * 3 % 10;
```
### Line Changed: **Line 41**
### Output
```
+PQ4mUgVMrU=
```

---

## JavaScript (`main.js`)
### Buggy Line
```js
let idx = Number((step * 3n) % 11n);
```
### Fixed Line
```js
let idx = Number((step * 3n) % 10n);
```
### Line Changed: **Line 5**
### Output
```
+PQ4mUgVMrU=
```
