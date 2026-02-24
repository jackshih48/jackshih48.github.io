#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. 定義必須放在 main 之前
struct Role{
    int roleType; // 0: student, 1: teacher
    union {
        float GPA;
        int salary;
    } roleInfo;
};

struct Person {
    char name[20];
    struct Role role;
    struct Person *link; // 指向下一個人的指標
};

void printPeople(struct Person *p);
void freePeople(struct Person *p);

int main(void)
{
    char choice = '1';
    struct Person *head = NULL; // 鏈結串列的頭
    struct Person *current = NULL; // 目前正在處理的節點

    do {
        // 2. 每次迴圈都要分配"新"的記憶體給新的人
        struct Person *newNode = malloc(sizeof(struct Person));
        if (newNode == NULL) {
            fprintf(stderr, "Insufficient memory.\n");
            exit(EXIT_FAILURE);
        }
        newNode->link = NULL; // 初始化新節點的 link

        // 3. 處理鏈結串列的連接邏輯
        if (head == NULL) {
            head = newNode;     // 第一個節點
            current = newNode;
        } else {
            current->link = newNode; // 把上一個節點連到新節點
            current = newNode;       // 移動 current 指標
        }

        // 4. 輸入資料
        printf("\nEnter the name: ");
        scanf("%s", current->name); // 字串不需要 &

        printf("Enter the role (0 for student, 1 for teacher): ");
        scanf("%d", &current->role.roleType);

        if (current->role.roleType == 1) { // Teacher
            printf("Enter the salary: ");
            // 5. 存取 union 必須指定成員 (.salary)
            scanf("%d", &current->role.roleInfo.salary);
        } else { // Student
            printf("Enter the GPA: ");
            // 5. 存取 union 必須指定成員 (.GPA)，且 scanf 用 %f (不是 %.2f)
            scanf("%f", &current->role.roleInfo.GPA);
        }

        printf("Enter 0 to leave or 1 to continue: ");
        // 6. 解決緩衝區問題：前面的 scanf 留下了 \n
        // 使用 " %c" (前面加空白) 可以吃掉換行符號
        scanf(" %c", &choice); 

    } while (choice == '1'); // 7. 比較字元 '1' 而不是整數 1

    printf("\n--- List Output ---\n");
    printPeople(head);
	freePeople(head);
    
    return 0;
}

void printPeople(struct Person *p)
{
    // 8. 修正遍歷邏輯：只要 p 不是 NULL 就要印
    while (p != NULL) {
        printf("Name: %s\t", p->name);
        
        if (p->role.roleType == 1) { // Teacher
            // 讀取 union 的 salary
            printf("Role: Teacher\tSalary: %d\n", p->role.roleInfo.salary);
        } else { // Student
            // 讀取 union 的 GPA
            printf("Role: Student\tGPA: %.2f\n", p->role.roleInfo.GPA);
        }
        
        p = p->link; // 移動到下一個
    }
}

void freePeople(struct Person *p)
{
	struct Person *temp;
    while (p != NULL) {
        temp = p->link; // 移動到下一個
		free(p);
		p = temp;
    }
}