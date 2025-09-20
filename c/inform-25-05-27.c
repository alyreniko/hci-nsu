#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// === Вспомогательные функции для строк ===

void writeString(FILE *file, const char *str) {
    int len = strlen(str);
    fwrite(&len, sizeof(int), 1, file);
    fwrite(str, sizeof(char), len, file);
}

char *readString(FILE *file) {
    int len;
    if (fread(&len, sizeof(int), 1, file) != 1) {
        return NULL;
    }
    char *str = malloc(len + 1);
    fread(str, sizeof(char), len, file);
    str[len] = '\0';
    return str;
}

// === Reader ===

struct Reader {
    char *lastName;
    char *firstName;
    char *patronymic;
    char gender; // 'M' или 'F'
    int yearRegistered;
};

void writeSampleReaders(const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Ошибка при создании файла читателей");
        return;
    }

    struct Reader readers[] = {
        {"Иванов", "Иван", "Иванович", 'M', 2015},
        {"Петрова", "Анна", "Сергеевна", 'F', 2020},
        {"Сидоров", "Алексей", "Николаевич", 'M', 2017}
    };
    size_t count = sizeof(readers) / sizeof(struct Reader);
    fwrite(&count, sizeof(size_t), 1, file);

    for (size_t i = 0; i < count; ++i) {
        writeString(file, readers[i].lastName);
        writeString(file, readers[i].firstName);
        writeString(file, readers[i].patronymic);
        fwrite(&readers[i].gender, sizeof(char), 1, file);
        fwrite(&readers[i].yearRegistered, sizeof(int), 1, file);
    }

    fclose(file);
}

void readReadersFromFile(const char *filename, struct Reader **readers, size_t *count) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Ошибка открытия файла читателей");
        *readers = NULL;
        *count = 0;
        return;
    }

    if (fread(count, sizeof(size_t), 1, file) != 1) {
        fclose(file);
        *readers = NULL;
        *count = 0;
        return;
    }

    *readers = malloc(*count  *sizeof(struct Reader));
    if (*readers == NULL) {
        perror("Ошибка выделения памяти для читателей");
        fclose(file);
        *count = 0;
        return;
    }

    for (size_t i = 0; i < *count; ++i) {
        (*readers)[i].lastName = readString(file);
        (*readers)[i].firstName = readString(file);
        (*readers)[i].patronymic = readString(file);
        fread(&(*readers)[i].gender, sizeof(char), 1, file);
        fread(&(*readers)[i].yearRegistered, sizeof(int), 1, file);
    }

    fclose(file);
}

void findLongTermMaleReaders(const struct Reader *readers, size_t count) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int currentYear = tm.tm_year + 1900;

    printf("Читатели-мужчины, пользующиеся библиотекой 5 лет и более:\n");

    for (size_t i = 0; i < count; ++i) {
        int yearsUsing = currentYear - readers[i].yearRegistered;
        if (readers[i].gender == 'M' && yearsUsing >= 5) {
            printf("- %s %s %s (с %d года)\n",
                   readers[i].lastName,
                   readers[i].firstName,
                   readers[i].patronymic,
                   readers[i].yearRegistered);
        }
    }
}

void freeReaders(struct Reader *readers, size_t count) {
    for (size_t i = 0; i < count; ++i) {
        free(readers[i].lastName);
        free(readers[i].firstName);
        free(readers[i].patronymic);
    }
    free(readers);
}

// === Buyer ===

struct Buyer {
    char *lastName;
    char *city;
    char *accountNumber;
};

void writeSampleBuyers(const char *filename) {
    struct Buyer buyers[] = {
        {"Иванов", "Новосибирск", "123400"},
        {"Петров", "Москва", "555500"},
        {"Сидоров", "Новосибирск", "987600"},
        {"Кузнецова", "Новосибирск", "123456"},
        {"Васильев", "Новосибирск", "111100"},
        {"Орлов", "Екатеринбург", "222200"},
    };
    size_t count = sizeof(buyers) / sizeof(struct Buyer);

    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Ошибка создания файла покупателей");
        return;
    }

    fwrite(&count, sizeof(size_t), 1, file);

    for (size_t i = 0; i < count; i++) {
        writeString(file, buyers[i].lastName);
        writeString(file, buyers[i].city);
        writeString(file, buyers[i].accountNumber);
    }

    fclose(file);
}

void readBuyersFromFile(const char *filename, struct Buyer **buyers, size_t *count) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Ошибка открытия файла покупателей");
        *buyers = NULL;
        *count = 0;
        return;
    }

    if (fread(count, sizeof(size_t), 1, file) != 1) {
        fclose(file);
        *buyers = NULL;
        *count = 0;
        return;
    }

    *buyers = malloc(*count  *sizeof(struct Buyer));
    if (*buyers == NULL) {
        perror("Ошибка выделения памяти для покупателей");
        fclose(file);
        *count = 0;
        return;
    }

    for (size_t i = 0; i < *count; i++) {
        (*buyers)[i].lastName = readString(file);
        (*buyers)[i].city = readString(file);
        (*buyers)[i].accountNumber = readString(file);
        if (!(*buyers)[i].lastName || !(*buyers)[i].city || !(*buyers)[i].accountNumber) {
            *count = i;
            break;
        }
    }

    fclose(file);
}

void findBuyersNovosibirskWithAccountEnding00(const struct Buyer *buyers, size_t count) {
    printf("\nПокупатели из Новосибирска с номерами счетов, оканчивающимися на '00':\n");
    int found = 0;

    for (size_t i = 0; i < count; i++) {
        const char *city = buyers[i].city;
        const char *account = buyers[i].accountNumber;

        size_t len = strlen(account);
        if (strcmp(city, "Новосибирск") == 0 && len >= 2 &&
            account[len - 1] == '0' && account[len - 2] == '0') {
            printf("- %s, город: %s, счет: %s\n", buyers[i].lastName, city, account);
            found = 1;
        }
    }

    if (!found) {
        printf("Не найдено подходящих покупателей.\n");
    }
}

void freeBuyers(struct Buyer *buyers, size_t count) {
    for (size_t i = 0; i < count; i++) {
        free(buyers[i].lastName);
        free(buyers[i].city);
        free(buyers[i].accountNumber);
    }
    free(buyers);
}

// === Team ===

typedef struct {
    char *name;
    char *city;
    int points;
} Team;

void writeSampleTeams(const char *filename) {
    Team teams[] = {
        {"Команда А", "Казань", 15},
        {"Команда Б", "Москва", 20},
        {"Команда В", "Казань", 8},
        {"Команда Г", "Новосибирск", 10},
        {"Команда Д", "Казань", 25},
        {"Команда Е", "Казань", 5}
    };
    size_t count = sizeof(teams) / sizeof(Team);

    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Ошибка создания файла команд");
        return;
    }

    fwrite(&count, sizeof(size_t), 1, file);

    for (size_t i = 0; i < count; i++) {
        writeString(file, teams[i].name);
        writeString(file, teams[i].city);
        fwrite(&teams[i].points, sizeof(int), 1, file);
    }

    fclose(file);
}

void readTeamsFromFile(const char *filename, Team **teams, size_t *count) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Ошибка открытия файла команд");
        *teams = NULL;
        *count = 0;
        return;
    }

    if (fread(count, sizeof(size_t), 1, file) != 1) {
        fclose(file);
        *teams = NULL;
        *count = 0;
        return;
    }

    *teams = malloc(*count  *sizeof(Team));
    if (*teams == NULL) {
        perror("Ошибка выделения памяти для команд");
        fclose(file);
        *count = 0;
        return;
    }

    for (size_t i = 0; i < *count; i++) {
        (*teams)[i].name = readString(file);
        (*teams)[i].city = readString(file);
        fread(&(*teams)[i].points, sizeof(int), 1, file);
        if (!(*teams)[i].name || !(*teams)[i].city) {
            *count = i;
            break;
        }
    }

    fclose(file);
}

int countTeamsKazanWithMaxPoints(const Team *teams, size_t count, int maxPoints) {
    int result = 0;
    for (size_t i = 0; i < count; i++) {
        if (strcmp(teams[i].city, "Казань") == 0 && teams[i].points <= maxPoints) {
            result++;
        }
    }
    return result;
}

void freeTeams(Team *teams, size_t count) {
    for (size_t i = 0; i < count; i++) {
        free(teams[i].name);
        free(teams[i].city);
    }
    free(teams);
}

// === Структура Государство ===

struct Country {
    char *name;
    char *capital;
    int population;
    int area;
};

void writeSampleCountries(const char *filename) {
    struct Country countries[] = {
        {"Россия", "Москва", 146000, 17098},
        {"Финляндия", "Хельсинки", 5500, 338},
        {"Канада", "Оттава", 38000, 9985},
        {"Сингапур", "Сингапур", 5700, 1},
        {"Монголия", "Улан-Батор", 3300, 1565}
    };
    size_t count = sizeof(countries) / sizeof(struct Country);

    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Ошибка создания файла стран");
        return;
    }

    fwrite(&count, sizeof(size_t), 1, file);

    for (size_t i = 0; i < count; i++) {
        writeString(file, countries[i].name);
        writeString(file, countries[i].capital);
        fwrite(&countries[i].population, sizeof(int), 1, file);
        fwrite(&countries[i].area, sizeof(int), 1, file);
    }

    fclose(file);
}

void readCountriesFromFile(const char *filename, struct Country **countries, size_t *count) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Ошибка открытия файла стран");
        *countries = NULL;
        *count = 0;
        return;
    }

    if (fread(count, sizeof(size_t), 1, file) != 1) {
        fclose(file);
        *countries = NULL;
        *count = 0;
        return;
    }

    *countries = malloc(*count  *sizeof(struct Country));
    if (*countries == NULL) {
        perror("Ошибка выделения памяти для стран");
        fclose(file);
        *count = 0;
        return;
    }

    for (size_t i = 0; i < *count; i++) {
        (*countries)[i].name = readString(file);
        (*countries)[i].capital = readString(file);
        fread(&(*countries)[i].population, sizeof(int), 1, file);
        fread(&(*countries)[i].area, sizeof(int), 1, file);
        if (!(*countries)[i].name || !(*countries)[i].capital) {
            *count = i;
            break;
        }
    }

    fclose(file);
}

void findCountriesByPopArea(const struct Country *countries, size_t count, int minPop, int maxArea) {
    printf("\nСтраны с населением не менее %d тыс. и площадью не более %d тыс. кв. км:\n", minPop, maxArea);
    int found = 0;
    for (size_t i = 0; i < count; i++) {
        if (countries[i].population >= minPop && countries[i].area <= maxArea) {
            printf("- %s (столица: %s), население: %d тыс., площадь: %d тыс. кв.км\n",
                countries[i].name, countries[i].capital, countries[i].population, countries[i].area);
            found = 1;
        }
    }
    if (!found) {
        printf("Нет подходящих стран.\n");
    }
}

void freeCountries(struct Country *countries, size_t count) {
    for (size_t i = 0; i < count; i++) {
        free(countries[i].name);
        free(countries[i].capital);
    }
    free(countries);
}

// ======== Главная функция ========

int main() {
    // --- Readers ---
    const char *readersFile = "readers.bin";
    writeSampleReaders(readersFile);

    struct Reader *readers = NULL;
    size_t readersCount = 0;
    readReadersFromFile(readersFile, &readers, &readersCount);

    if (readers) {
        findLongTermMaleReaders(readers, readersCount);
        freeReaders(readers, readersCount);
    }

    // --- Buyers ---
    const char *buyersFile = "buyers.bin";
    writeSampleBuyers(buyersFile);

    struct Buyer *buyers = NULL;
    size_t buyersCount = 0;
    readBuyersFromFile(buyersFile, &buyers, &buyersCount);

    if (buyers) {
        findBuyersNovosibirskWithAccountEnding00(buyers, buyersCount);
        freeBuyers(buyers, buyersCount);
    }

    // --- Teams ---
    const char *teamsFile = "teams.bin";
    writeSampleTeams(teamsFile);

    Team *teams = NULL;
    size_t teamsCount = 0;
    readTeamsFromFile(teamsFile, &teams, &teamsCount);

    if (teams) {
        int maxPoints;
        printf("\nВведите максимальное количество очков для поиска команд из Казани: ");
        if (scanf("%d", &maxPoints) == 1) {
            int count = countTeamsKazanWithMaxPoints(teams, teamsCount, maxPoints);
            printf("Количество команд из Казани с очками не более %d: %d\n", maxPoints, count);
        } else {
            printf("Некорректный ввод.\n");
        }
        freeTeams(teams, teamsCount);
    }

    // --- Countries ---
    const char *countriesFile = "countries.bin";
    writeSampleCountries(countriesFile);

    struct Country *countries = NULL;
    size_t countriesCount = 0;
    readCountriesFromFile(countriesFile, &countries, &countriesCount);

    if (countries) {
        int N, M;
        printf("\nВведите минимальное население (тыс. чел.): ");
        if (scanf("%d", &N) != 1) {
            printf("Некорректный ввод\n");
            freeCountries(countries, countriesCount);
            return 1;
        }
        printf("Введите максимальную площадь (тыс. кв. км): ");
        if (scanf("%d", &M) != 1) {
            printf("Некорректный ввод\n");
            freeCountries(countries, countriesCount);
            return 1;
        }

        findCountriesByPopArea(countries, countriesCount, N, M);
        freeCountries(countries, countriesCount);
    }

    return 0;
}
