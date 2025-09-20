#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void) {
    const char *parts[] = {"hydraulic pump", "PLC module", "servo motor"};
    const int part_count = sizeof(parts) / sizeof(parts[0]);

    char input[256];

    printf("Hej. Welcome to the spare parts inventory!\n");
    printf("Which part do you need?\n");

    while (true) {
        if (!fgets(input, sizeof(input), stdin)) {
            break;
        }
        input[strcspn(input, "\r\n")] = '\0';

        // Check for exact part match
        for (int i = 0; i < part_count; ++i) {
            if (strcmp(input, parts[i]) == 0) {
                printf("I have got %s here for you 😊. Bye!\n", parts[i]);
                return 0;
            }
        }

        // Special queries
        if (strcmp(input, "Do you actually have any parts?") == 0 ||
            strcmp(input, "Is there anything in stock at all?") == 0) {
            printf("We have %d part(s)!\n", part_count);
            for (int i = 0; i < part_count; ++i) {
                printf("%s\n", parts[i]);
            }
        } else {
            printf("I am afraid we don’t have any %s in the inventory 😔\n", input);
        }

        printf("Which part do you need?\n");
    }

    return 0;
}