# Bug 22 – Missing Return Statement

## Bug Description
`wave_hash()` computes a result in `acc` but never returns it. In Python it implicitly returns `None`; in other languages an exception is thrown instead of a return.

---

## Python (`main.py`)
### Buggy Code
```python
def wave_hash(n):
    acc = 0x7654321076543210
    for k in range(1, n + 1):
        ...
    # no return statement — returns None
```
### Fixed Line (added at end of function)
```python
    return acc
```
### Line Changed: **After Line 13 (new line added)**
### Output
```
/1rDh76yCXs=
```

---

## Java (`main.java`)
### Buggy Line
```java
throw new RuntimeException("TypeError: missing return statement");
```
### Fixed Line
```java
return acc;
```
### Line Changed: **Line 16**
### Output
```
/1rDh76yCXs=
```

---

## C (`main.c`)
### Buggy Lines
```c
fprintf(stderr, "TypeError: missing return statement\n");
exit(1);
```
### Fixed Line
```c
return acc;
```
### Lines Changed: **Lines 39–40**
### Output
```
/1rDh76yCXs=
```

---

## C++ (`main.cpp`)
### Buggy Line
```cpp
throw std::runtime_error("TypeError: missing return statement");
```
### Fixed Line
```cpp
return acc;
```
### Line Changed: **Line 39**
### Output
```
/1rDh76yCXs=
```

---

## JavaScript (`main.js`)
### Buggy Code
```js
function wave_hash(n) {
    ...
    // no return statement — returns undefined
}
```
### Fixed Line (added at end of function)
```js
    return acc;
```
### Line Changed: **After Line 12 (new line added)**
### Output
```
/1rDh76yCXs=
```
