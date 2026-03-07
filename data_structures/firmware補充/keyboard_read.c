#include <stdio.h>
#include <conio.h>  // _getch() 專用

void on_button_a(void) { printf("Attack\n"); }
void on_button_b(void) { printf("Defense\n"); }
void on_button_up(void) { printf("Move Up\n"); }
void on_button_down(void) { printf("Move Down\n"); }
void on_button_left(void) { printf("Move Left\n"); }
void on_button_right(void) { printf("Move Right\n"); }
void on_button_space(void) { printf("Jump\n"); }

int main(void)
{
    int c;
    printf("Press keyboard for playing game. 'q' for leave.\n");

    while (1) {
        c = _getch();

        if (c == 0xE0) {
            // 方向鍵：讀第二個字元
            c = _getch();
            switch (c) {
                case 72: on_button_up();    break;
                case 80: on_button_down();  break;
                case 75: on_button_left();  break;
                case 77: on_button_right(); break;
            }
        } else {
            switch (c) {
                case 'a': on_button_a(); break;
                case 'b': on_button_b(); break;
				case ' ': on_button_space(); break;
                case 'q': return 0;
            }
        }
    }
}