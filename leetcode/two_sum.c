#define TABLE_SIZE 10007

struct Node {
    int key; // nums[i]
    int value; // index i
    struct Node *next;
};

struct Node *find(struct Node **hashTable, int key);
int insert(struct Node **hashTable, int key, int value);
int hash(int key);
void freeTable(struct Node **hashTable);

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    if (nums == NULL || numsSize < 2 || returnSize == NULL) {
        return NULL;
    }
    
    struct Node *hashTable[TABLE_SIZE] = {0};
    
    *returnSize = 0; 

    int *sol = malloc(2 * sizeof *sol);
    if (sol == NULL) {
        return NULL;
    }

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        struct Node *found = find(hashTable, complement);
        
        if (found != NULL) {
            sol[0] = found->value;
            sol[1] = i;
            *returnSize = 2;
            freeTable(hashTable);
            return sol;
        }

        if (!insert(hashTable, nums[i], i)) {
            freeTable(hashTable);
            free(sol);
            return NULL;
        }
    }

    freeTable(hashTable);
    free(sol);
    return NULL;
}

struct Node *find(struct Node **hashTable, int key)
{
    int idx = hash(key);
    struct Node *cur = hashTable[idx];

    while (cur != NULL) {
        if (cur->key == key) {
            return cur;
        }
        cur = cur->next;
    }

    return NULL;
}

int insert(struct Node **hashTable, int key, int value)
{
    int idx = hash(key);
    
    struct Node *newNode = malloc(sizeof *newNode);
    if (newNode == NULL) {
        return 0;
    }

    newNode->key = key;
    newNode->value = value;
    newNode->next = hashTable[idx];
    hashTable[idx] = newNode;

    return 1;
}

int hash(int key)
{
    if (key < 0) {
        key = -key;
    }

    return key % TABLE_SIZE;
}

void freeTable(struct Node **hashTable)
{
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct Node *cur = hashTable[i];
        while (cur != NULL) {
            struct Node *temp = cur;
            cur = cur->next;
            free(temp);
        }
    }
}