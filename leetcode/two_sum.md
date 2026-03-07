---
layout: page
title: Two Sum 筆記
---

## 1. 題目

給定一個整數陣列 `nums` 和一個整數 `target`，要找出兩個 index `i, j`，使得：

`nums[i] + nums[j] == target`

條件：

* 每組輸入保證剛好有一組解
* 不能使用同一個元素兩次
* 回傳的是 index `[i, j]`，不是數值
* LeetCode C 版本要求：回傳的答案陣列必須用 `malloc` 配置，caller 之後會 `free`

---

## 2. 解法

### 2.1 Brute force

#### Idea

直接用雙層迴圈枚舉所有 pair：

* 外層固定 `i`
* 內層從 `j = i + 1` 開始找
* 檢查 `nums[i] + nums[j] == target`

找到就回傳 `[i, j]`

#### 複雜度

* Time: `O(n^2)`
* Space: `O(1)`，不算答案陣列

---

### 2.2 Hash table

#### Idea

當我掃到 `nums[i]` 時，我真正想找的是： `target - nums[i]`

如果之前已經出現過這個數，就直接找到答案。

所以 hash table 裡存的是：

* key = 數值本身，也就是 `nums[i]`
* value = 這個數值對應的 index `i`

流程是：

1. 先算 `complement = target - nums[i]`
2. 去 hash table 查 `complement` 是否已存在
3. 若存在，回傳 `[之前的 index, i]`
4. 若不存在，把目前 `(nums[i], i)` 插入 hash table

注意：

* 一定要**先 find 再 insert**
* 否則可能會找到自己，違反「不能用同一個元素兩次」

#### 複雜度

* Average Time: `O(n)`
* Space: `O(n)`

---

### 2.3 Hash table 的實作

我這次是自己用 C 手刻一個 hash table。

#### 基本設計

* hash table 本體是一個 array
* 每個 array 元素 (稱作bucket) 是一個 `struct Node *`
* 如果多個數值被分到同一個 bucket (這個情況稱作collision)，就把它們串成一條 linked list
  
定義：

```c
struct Node {
    int key;
    int value;
    struct Node *next;
};
```

欄位意義：

* `key`: 數值本身，也就是 `nums[i]`
* `value`: 對應的 index `i`
* `next`: collision 時串成 linked list

---

### 2.4 bucket 是什麼

hash table 可以想成：

* 一個 array
* array 的每一格就是一個 bucket

例如：

`hashTable[0] ~ hashTable[9]`

每個 bucket 存的是某條 linked list 的頭指標。

如果不同 key hash 到同一格，就放在同一條 linked list 裡。

---

### 2.5 hash function

```c
TABLE_SIZE = 10
if (key < 0) key = -key;
hash(key) = key % TABLE_SIZE
```

所以不同 key 可能會算到同一個 bucket：

* `5 % 10 = 5`
* `15 % 10 = 5`
* `25 % 10 = 5`

代表 5、15、25 都會進 bucket 5。

這就是 collision。

所以 `hashTable[5]` 不只放一個節點，而是一條 linked list：

`[25, idx] -> [15, idx] -> [5, idx] -> NULL`


補充：

* 這只是教學簡化版
* 真正工程上有更好的 hash function

---

### 2.7 twoSum 主程式整理

1. 檢查輸入是否合法
2. 建立 hash table：`struct Node *hashTable[TABLE_SIZE] = {0};`
3. 配置答案陣列 `sol`
4. 逐一掃描 `nums[i]`

每次迴圈：

* 算 `complement = target - nums[i]`
* `find(hashTable, complement)`
* 如果找到：

  * `sol[0] = found->value`
  * `sol[1] = i`
  * `*returnSize = 2`
  * `freeTable(hashTable)`
  * return `sol`
* 如果沒找到：

  * `insert(hashTable, nums[i], i)`

若 insert 失敗：

* `freeTable(hashTable)`
* `free(sol)`
* `return NULL`

若整個陣列掃完都沒找到：

* `freeTable(hashTable)`
* `free(sol)`
* `return NULL`

雖然題目保證有解，但這樣寫比較完整。

---

### 2.8 find 的概念

`find(hashTable, key)` 的流程：

1. 先算 `idx = hash(key)`
2. 取出 `hashTable[idx]`，也就是 bucket 頭
3. 沿著 linked list 一個一個比對 `cur->key == key`
4. 找到就回傳該 node
5. 找不到就回傳 `NULL`

重點：

* `hashTable[hash(key)]` 只是先找到 bucket
* 不代表一定直接找到答案
* 還要在 bucket 的 linked list 裡逐個比對 key

---

### 2.9 insert 的概念

`insert(hashTable, key, value)` 的流程：

1. 算 `idx = hash(key)`
2. 配置新 node
3. 填入 `key` 和 `value`
4. 用頭插法插入對應 bucket 的 linked list

頭插法核心：

```c
newNode->next = hashTable[idx];
hashTable[idx] = newNode;
```

意思是：

* 新 node 指向原本 bucket 的頭
* 再讓 bucket 頭改成新 node

優點：

* `O(1)`
* 很直觀

---

### 2.10 freeTable 的概念

因為 hash table 的每個 node 都是 `malloc` 出來的，所以最後要全部釋放。

`freeTable(hashTable)` 會：

1. 走訪每個 bucket
2. 對每條 linked list 逐個 free node

重點：

```c
temp = cur;
cur = cur->next;
free(temp);
```

不能先 free 再取 `next`，否則會變成用到已釋放記憶體。

---

## 3. 一些 C 語法重點、疑問與補充

### 3.1 malloc 回傳什麼，需不需要 type cast

`malloc` 回傳的是 `void *`

在 C 裡：

* `void *` 可以自動轉成其他物件指標型別
* 所以可以**不用 cast**

例如這樣寫即可：

```c
int *sol = malloc(2 * sizeof *sol);
```

沒必要：

```c
int *sol = (int *)malloc(2 * sizeof *sol);
```

---

### 3.2 sizeof 是 operator，不是 function

`sizeof` 是一元運算子（unary operator），不是函式。

所以：

* `sizeof(*ptr)` 可以
* `sizeof *ptr` 可以
* `sizeof(int)` 可以
* `sizeof int` 不可以

規則：

* 對 type 時要加括號：`sizeof(int)`
* 對 expression 時可加可不加：`sizeof x`、`sizeof(x)` 都行

---

### 3.3 struct Node *hashTable[] vs struct Node **hashTable

這兩種在**函式參數中等價**。

因為：

```c
struct Node *hashTable[TABLE_SIZE];
```

傳進函式後會 decay 成指向第一個元素的指標。

而陣列元素型別是：

```c
struct Node *
```

所以 decay 後的型別就是：

```c
struct Node **
```

重點區分：

* `struct Node *hashTable[]`

  * hashTable這個陣列，每個元素都是 `struct Node *`

* `struct Node **hashTable`

  * hashtable這個指標，指向 `struct Node *`

* `struct Node *hashTable`

  * 這是「指向單一 `struct Node` 的指標」
  * 與上述兩者不等價

---

### 3.4 {0} 的意思

```c
struct Node *hashTable[TABLE_SIZE] = {0};
```

意思是：

* 第一個元素初始化成 0
* 其他沒寫到的元素也全部自動補成 0

因為元素型別是 pointer，所以全部都會變成 `NULL`

等價概念：

* 每個 bucket 一開始都沒有 linked list

---

### 3.5 為什麼要做 malloc 失敗檢查

因為 C 不會幫你自動處理記憶體錯誤。

如果 `malloc` 失敗會回傳 `NULL`

若不檢查，後面直接用該指標可能造成 crash。

所以像：

* `sol = malloc(...)`
* `newNode = malloc(...)`

都應該檢查是否為 `NULL`

---

### 3.6 為什麼要 cleanup

只要前面有 `malloc` 成功，後面如果中途失敗或提前 return，就要記得釋放已配置資源。

這題裡：

* hash table node 需要 `freeTable(hashTable)`
* `sol` 需要 `free(sol)`

這是 C 很重要的習慣。

---

### 3.7 `hash(key)` 對負數的處理

目前寫法：

```c
if (key < 0) {
    key = -key;
}
```

目的：

* 避免 `% TABLE_SIZE` 得到負索引

因為在 C 裡，負數 `%` 正數，結果還是負的。

不過這個寫法不是最嚴謹的版本，因為：

* 若 `key == INT_MIN`
* `-key` 可能 overflow

這次先當教學版理解即可。

---

## 總結

Brute force 是「枚舉所有 pair」。
Hash table 解法是「我現在缺哪個數，把看過的數記起來，快速查 complement」。
