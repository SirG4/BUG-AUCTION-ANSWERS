# Bug 23 – Returning Wrong Value

## Bug Description
`mix()` correctly computes the hash into `x`, but then discards it by returning the hardcoded `0` instead of `x`. Every call to `mix()` returns zero.

---

## Python (`main.py`)
### Buggy Line
```python
return 0
```
### Fixed Line
```python
return x
```
### Line Changed: **Line 10**
### Output
```
1Ef/XubkOT8=
```

---

## Java (`main.java`)
### Buggy Line
```java
return 0;
```
### Fixed Line
```java
return x;
```
### Line Changed: **Line 11**
### Output
```
1Ef/XubkOT8=
```

---

## C (`main.c`)
### Buggy Line
```c
return 0;
```
### Fixed Line
```c
return x;
```
### Line Changed: **Line 35**
### Output
```
1Ef/XubkOT8=
```

---

## C++ (`main.cpp`)
### Buggy Line
```cpp
return 0;
```
### Fixed Line
```cpp
return x;
```
### Line Changed: **Line 38**
### Output
```
1Ef/XubkOT8=
```

---

## JavaScript (`main.js`)
### Buggy Line
```js
return 0n;
```
### Fixed Line
```js
return x;
```
### Line Changed: **Line 7**
### Output
```
1Ef/XubkOT8=
```
