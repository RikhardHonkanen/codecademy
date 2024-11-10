#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 8        // Maximum number of lines to read
#define MAX_LINE_LENGTH 64 // Maximum length of each line

int main()
{
    FILE *file = fopen("data.txt", "r");
    if (file == NULL)
    {
        perror("Unable to open file");
        return 1;
    }

    char *lines[MAX_LINES];
    int line_count = 0;

    while (line_count < MAX_LINES && !feof(file))
    {
        lines[line_count] = malloc(MAX_LINE_LENGTH);
        if (lines[line_count] == NULL)
        {
            perror("Unable to allocate memory for line");
            return 1;
        }
        if (fgets(lines[line_count], MAX_LINE_LENGTH, file) != NULL)
        {
            lines[line_count][strcspn(lines[line_count], "\n")] = '\0'; // Remove newline
            line_count++;
        }
    }

    fclose(file);

    // Check if any data was read
    if (line_count == 0)
    {
        printf("No data found in the file.\n");
        return 1;
    }

    // Create arrays to store planet numbers and relative gravity
    int planet_numbers[MAX_LINES];
    float relative_gravity[MAX_LINES];
    char *planet_names[MAX_LINES];

    // Parse the data and store it in the arrays
    for (int i = 0; i < line_count; i++)
    {
        printf("%s\n", lines[i]);

        int planet_num;
        float gravity;
        char planet_name[MAX_LINE_LENGTH];

        // Parse each line: number, name, and gravity
        sscanf(lines[i], "%d %63s %f", &planet_num, planet_name, &gravity);

        // Allocate memory for the planet name and copy the name into the allocated memory
        planet_names[i] = malloc(strlen(planet_name) + 1); // +1 for null terminator
        if (planet_names[i] == NULL)
        {
            perror("Unable to allocate memory for planet name");
            return 1;
        }
        strcpy(planet_names[i], planet_name); // Copy name into allocated space

        // Store the planet number and gravity
        planet_numbers[i] = planet_num;
        relative_gravity[i] = gravity;
    }

    int user_weight;
    int planet;

    printf("Earth gravity weight: ");
    scanf("%d", &user_weight);
    printf("Choose a planet to fight on (1-%d): ", line_count);
    scanf("%d", &planet);

    // Validate the user input
    if (planet < 1 || planet > line_count)
    {
        printf("Invalid planet number! Please choose a number between 1 and %d.\n", line_count);
        return 1;
    }

    printf("On %s you will weigh %.2f kilograms.\n", planet_names[planet], user_weight * relative_gravity[planet]);

    // Free allocated memory
    for (int i = 0; i < line_count; i++)
    {
        free(lines[i]);        // Free allocated memory for each line
        free(planet_names[i]); // Free memory for each planet name
    }

    return 0;
}