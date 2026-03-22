# Bug 26 – Addition Instead of Multiplication

## Bug Description
The MurmurHash3 finalizer uses multiplication (`*=`) as the mixing step. The buggy code uses addition (`+=`) instead, which produces a completely different (and non-cryptographic) result.

---

## Python (`main.py`)
### Buggy Lines
```python
acc = (acc + 0xFF51AFD7ED558CCD) & 0xFFFFFFFFFFFFFFFF
acc = (acc + 0xC4CEB9FE1A85EC53) & 0xFFFFFFFFFFFFFFFF
```
### Fixed Lines
```python
acc = (acc * 0xFF51AFD7ED558CCD) & 0xFFFFFFFFFFFFFFFF
acc = (acc * 0xC4CEB9FE1A85EC53) & 0xFFFFFFFFFFFFFFFF
```
### Lines Changed: **Lines 8, 10**
### Output
```
xBUbO7bI+s8=
```

---

## Java (`main.java`)
### Buggy Lines
```java
acc += 0xFF51AFD7ED558CCDL;
acc += 0xC4CEB9FE1A85EC53L;
```
### Fixed Lines
```java
acc *= 0xFF51AFD7ED558CCDL;
acc *= 0xC4CEB9FE1A85EC53L;
```
### Lines Changed: **Lines 10, 12**
### Output
```
xBUbO7bI+s8=
```

---

## C (`main.c`)
### Buggy Lines
```c
acc += 0xFF51AFD7ED558CCDULL;
acc += 0xC4CEB9FE1A85EC53ULL;
```
### Fixed Lines
```c
acc *= 0xFF51AFD7ED558CCDULL;
acc *= 0xC4CEB9FE1A85EC53ULL;
```
### Lines Changed: **Lines 37, 39**
### Output
```
xBUbO7bI+s8=
```

---

## C++ (`main.cpp`)
### Buggy Lines
```cpp
acc += 0xFF51AFD7ED558CCDULL;
acc += 0xC4CEB9FE1A85EC53ULL;
```
### Fixed Lines
```cpp
acc *= 0xFF51AFD7ED558CCDULL;
acc *= 0xC4CEB9FE1A85EC53ULL;
```
### Lines Changed: **Lines 40, 42**
### Output
```
xBUbO7bI+s8=
```

---

## JavaScript (`main.js`)
### Buggy Lines
```js
acc = BigInt.asUintN(64, acc + 0xFF51AFD7ED558CCDn);
acc = BigInt.asUintN(64, acc + 0xC4CEB9FE1A85EC53n);
```
### Fixed Lines
```js
acc = BigInt.asUintN(64, acc * 0xFF51AFD7ED558CCDn);
acc = BigInt.asUintN(64, acc * 0xC4CEB9FE1A85EC53n);
```
### Lines Changed: **Lines 6, 8**
### Output
```
xBUbO7bI+s8=
```
