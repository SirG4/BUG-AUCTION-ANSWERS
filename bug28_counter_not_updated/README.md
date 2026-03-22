# Bug 28 – Counter Not Updated

## Bug Description
A `counter` variable is used inside the loop to vary the hash computation, but it is never incremented. It stays `0` for all 10 iterations, making every loop iteration identical.

---

## Python (`main.py`)
### Buggy Code (missing line)
```python
for _ in range(10):
    acc ^= counter * 0x9E3779B97F4A7C15
    ...
    acc *= 0xBF58476D1CE4E5B9
    # counter += 1  ← MISSING
```
### Fixed (line added at end of loop)
```python
    counter += 1
```
### Line Changed: **After Line 12 (new line added)**
### Output
```
9Cp9zJ0gHKI=
```

---

## Java (`main.java`)
### Buggy Code (missing line)
```java
for (int i = 0; i < 10; i++) {
    ...
    acc *= 0xBF58476D1CE4E5B9L;
    // counter++; ← MISSING
}
```
### Fixed (line added at end of loop)
```java
counter++;
```
### Line Changed: **After Line 14 (new line added)**
### Output
```
9Cp9zJ0gHKI=
```

---

## C (`main.c`)
### Buggy Code (missing line)
```c
for (int i = 0; i < 10; i++) {
    ...
    acc *= 0xBF58476D1CE4E5B9ULL;
    // counter++; ← MISSING
}
```
### Fixed (line added at end of loop)
```c
counter++;
```
### Line Changed: **After Line 40 (new line added)**
### Output
```
9Cp9zJ0gHKI=
```

---

## C++ (`main.cpp`)
### Buggy Code (missing line)
```cpp
for (int i = 0; i < 10; i++) {
    ...
    acc *= 0xBF58476D1CE4E5B9ULL;
    // counter++; ← MISSING
}
```
### Fixed (line added at end of loop)
```cpp
counter++;
```
### Line Changed: **After Line 43 (new line added)**
### Output
```
9Cp9zJ0gHKI=
```

---

## JavaScript (`main.js`)
### Buggy Code (missing line)
```js
for (let i = 0; i < 10; i++) {
    ...
    acc = BigInt.asUintN(64, acc * 0xBF58476D1CE4E5B9n);
    // counter++; ← MISSING
}
```
### Fixed (line added at end of loop)
```js
counter++;
```
### Line Changed: **After Line 11 (new line added)**
### Output
```
9Cp9zJ0gHKI=
```
