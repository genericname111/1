#include <stdio.h>
#include <stdlib.h>

struct sixty_four_num_struct {
    unsigned long long number : 64;
};

struct Info {
    char genre[11];
    int num_players;
};

struct Game {
    float cost;
    char* title;
    struct Info info;
};

int bite_field() {
    struct sixty_four_num_struct s;
    unsigned  long long int temp;
    printf("enter the number ");
    scanf("%lld", &temp);
    s.number = temp;
    return  (temp << 61) >> 61;
}
void inputGame(struct Game* game) {
    int capacity = 10;
    int size = 0;
    char ch;
    while ((ch = getchar()) != '\n');
    game->title = (char*)malloc(capacity);

    printf("Enter game title: ");
    while ((ch = getchar()) != '\n') {
        if (size >= capacity - 1) {
            capacity++;
            game->title = (char*)realloc(game->title, capacity);
        }
        game->title[size++] = ch;
    }
    game->title[size] = '\0';

    printf("Enter game cost: ");
    scanf("%f", &game->cost);

    ch = getchar();
    printf("Enter game genre: ");
    size = 0;
    while ((ch = getchar()) != '\n'&& size < 10) {
        game->info.genre[size++] = ch;
    }
    game->info.genre[size] = '\0';

    printf("Enter number of players: ");
    scanf("%d", &game->info.num_players);

    while ((ch = getchar()) != '\n');
}

void displayGames(struct Game* games, int count) {
    printf("\nGame List:\n");
    for (int i = 0; i < count; i++) {
        printf("\nGame #%d:\n", i + 1);
        printf("Title: %s\n", games[i].title);
        printf("Cost: %.2f\n", games[i].cost);
        printf("Genre: %s\n", games[i].info.genre);
        printf("Number of players: %d\n", games[i].info.num_players);
    }
}

void freeGames(struct Game* games, int count) {
    for (int i = 0; i < count; i++) {
        free(games[i].title);
    }
    free(games);
}

void displayMenu() {
    printf("\n1. Add new games\n");
    printf("2. Display all games\n");
    printf("3. find games\n");
    printf("4. delete games\n");
    printf("5. exit\n");

    printf("Enter your choice: ");
}

void findGameByTitle(struct Game* games, int count) {
    char searchTitle[100];
    int found = 0, i = 0, j;
    char ch;
    while (getchar()!= '\n');
    printf("Enter game title to search: ");
    while ((ch = getchar()) != '\n') {
        searchTitle[i] = ch;
        i++;
    }
    searchTitle[i] = '\0';
    for (i = 0; i < count; i++) {
        char* currentTitle = games[i].title;
        for (j = 0;
            currentTitle[j] != '\0' &&  searchTitle[j] != '\0' && currentTitle[j] == searchTitle[j];
            j++);

        if (currentTitle[j] == '\0' && searchTitle[j] == '\0') {
            printf("\nGame found:\n");
            printf("Title: %s\n", games[i].title);
            printf("Cost: %.2f\n", games[i].cost);
            printf("Genre: %s\n", games[i].info.genre);
            printf("Number of players: %d\n", games[i].info.num_players);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Game not found");
    }
}
void deleteGameByCost(struct Game** games, int* count, float targetCost) {
    int found = 0;
    int matches = 0;
    for (int i = 0; i < *count; i++) {
        if ((*games)[i].cost == targetCost) {
            matches++;
        }
    }

    if (matches == 0) {
        printf("No games found\n");
        return;
    }
    struct Game* newGames = malloc((*count - matches) * sizeof(struct Game));
    int newIndex = 0;
    for (int i = 0; i < *count; i++) {
        if ((*games)[i].cost != targetCost) {
            newGames[newIndex] = (*games)[i];
            newIndex++;
        }
        else {
            
            free((*games)[i].title);
        }
    }
    free(*games);
    *games = newGames;
    *count = newIndex;
}

int main() {
    int numGames = 0;
    struct Game* games = NULL;
    int choice;
    int exitflag = 0;
    char ch;
    int division;
    float  targetCost;
    division = bite_field();
    printf("division = %d\n", division);
    while (!exitflag) {
        displayMenu();
        scanf("%d", &choice);
       

        switch (choice) {
        case 1: 
        
            printf("How many games do you want to enter? ");
            scanf("%d", &numGames);
        
                 games = (struct Game*)malloc(numGames * sizeof(struct Game));

            for (int i = 0; i < numGames; i++) {
                printf("\nGame #%d:\n", i + 1);
                inputGame(&games[i]);
            }
            break;

        case 2: 
            if ( numGames == 0) {
                printf("No games to display.\n");
            }
            else {
                displayGames(games, numGames);
            }
            break;

        case 3:
            if (numGames == 0) {
                printf("No games to search.\n");
            }
            else {
                findGameByTitle(games, numGames);
            }
            break;

        case 4:
            if (numGames == 0) {
                printf("No games to delete\n");
            }
            else {
                printf("enter cost\n");
                scanf("%f", &targetCost);
                deleteGameByCost(&games, &numGames, targetCost);
            }
            break;
        case 5:
                exitflag = 1;
                break;
        }
    }

    if (games != NULL) {
        freeGames(games, numGames);
    }

    return 0;
}
