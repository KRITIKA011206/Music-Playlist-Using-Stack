#include <stdio.h>
#include <string.h>

#define MAX 50    // max songs
#define LEN 100   // max length of song name

// Global playlist and count
char playlist[MAX][LEN];
int count = 0;

// ---------------- Stack for reversing ----------------
char stack[MAX][LEN];
int top = -1;

void push(char song[]) {
    if (top == MAX - 1) {
        printf("Stack overflow!\n");
        return;
    }
    strcpy(stack[++top], song);
}

void pop(char song[]) {
    if (top == -1) {
        printf("Stack underflow!\n");
        return;
    }
    strcpy(song, stack[top--]);
}

// ---------------- Playlist Functions ----------------

void addSong() {
    if (count == MAX) {
        printf("Playlist full!\n");
        return;
    }

    printf("Enter song name: ");
    getchar();  // <-- this eats the leftover '\n' from scanf("%d", &choice)

    scanf("%[^\n]", playlist[count]);  // now it waits for your full song name
    printf("Song added: \"%s\"\n", playlist[count]);
    count++;
}

void displayPlaylist() {
    if (count == 0) {
        printf(" Playlist empty!\n");
        return;
    }
    printf("\n Current Playlist:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, playlist[i]);
    }
}

void reversePlaylist() {
    if (count == 0) {
        printf(" Playlist empty!\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        push(playlist[i]);
    }
    for (int i = 0; i < count; i++) {
        pop(playlist[i]);
    }
    printf(" Playlist reversed!\n");
}

void shufflePlaylist() {
    if (count < 2) {
        printf("Not enough songs to shuffle!\n");
        return;
    }
    for (int i = 0; i < count - 1; i += 2) {
        char temp[LEN];
        strcpy(temp, playlist[i]);
        strcpy(playlist[i], playlist[i + 1]);
        strcpy(playlist[i + 1], temp);
    }
    printf("Playlist shuffled (neighbor swap)!\n");
}

void rotatePlaylist() {
    if (count == 0) {
        printf("Playlist empty!\n");
        return;
    }
    char temp[LEN];
    strcpy(temp, playlist[count - 1]);  // save last song
    for (int i = count - 1; i > 0; i--) {
        strcpy(playlist[i], playlist[i - 1]);
    }
    strcpy(playlist[0], temp);
    printf("Playlist rotated!\n");
}

// ---------------- Main ----------------
int main() {
    int choice;
    do {
        printf("\n===== MUSIC PLAYLIST MENU =====\n");
        printf("1. Add Song\n");
        printf("2. Display Playlist\n");
        printf("3. Reverse Playlist (using stack)\n");
        printf("4. Shuffle Playlist (swap neighbors)\n");
        printf("5. Rotate Playlist (move last to first)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addSong(); break;
            case 2: displayPlaylist(); break;
            case 3: reversePlaylist(); break;
            case 4: shufflePlaylist(); break;
            case 5: rotatePlaylist(); break;
            case 6: printf(" Exiting... Goodbye!\n"); break;
            default: printf(" Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}
