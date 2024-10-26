#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char name[100];
    int age;
    int height;
    int weight;
} Person;

// Function declarations

void swap(Person *a, Person *b)
{
    Person temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyMin(Person *students, int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && students[left].age < students[smallest].age)
        smallest = left;

    if (right < n && students[right].age < students[smallest].age)
        smallest = right;

    if (smallest != i)
    {
        swap(&students[i], &students[smallest]);
        heapifyMin(students, n, smallest);
    }
}

void heapifyMax(Person *students, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && students[left].weight > students[largest].weight)
        largest = left;

    if (right < n && students[right].weight > students[largest].weight)
        largest = right;

    if (largest != i)
    {
        swap(&students[i], &students[largest]);
        heapifyMax(students, n, largest);
    }
}

void readData(Person **students, int *n)
{
    FILE *file = fopen("text.txt", "r");
    if (file == NULL)
    {
        printf("Error: Could not open file.\n");
        return;
    }

    fscanf(file, "%d", n);
    *students = (Person *)malloc(*n * sizeof(Person));

    printf("Id Name\tAge Height Weight(pound)\n");
    for (int i = 0; i < *n; i++)
    {
        fscanf(file, "%d %s %d %d %d",
               &(*students)[i].id, (*students)[i].name,
               &(*students)[i].age, &(*students)[i].height,
               &(*students)[i].weight);
        printf("%d %s %d %d %d\n",
               (*students)[i].id, (*students)[i].name,
               (*students)[i].age, (*students)[i].height,
               (*students)[i].weight);
    }

    fclose(file);
}

void createMaxHeapWeight(Person *students, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapifyMax(students, n, i);
    }
}

void createMinHeapAge(Person *students, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapifyMin(students, n, i);
    }
}

int findYoungestWeight(Person *students, int n)
{
    if (n == 0)
    {
        printf("No students available.\n");
        return -1;
    }
    return students[0].weight;
}

int findAge(Person *students, int n)
{
    if (n == 0)
    {
        printf("No students available.\n");
        return -1;
    }
    return students[0].age;
}

void insertIntoMinHeap(Person **students, int *n, Person newPerson)
{
    *students = (Person *)realloc(*students, (*n + 1) * sizeof(Person));
    (*students)[*n] = newPerson;
    (*n)++;
    // Heapify upwards
    int i = *n - 1;
    while (i != 0 && (*students)[i].age < (*students)[(i - 1) / 2].age)
    {
        swap(&(*students)[i], &(*students)[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void deleteOldest(Person **students, int *n)
{
    if (*n == 0)
    {
        printf("No students to delete.\n");
        return;
    }
    (*students)[0] = (*students)[*n - 1];
    (*n)--;
    *students = (Person *)realloc(*students, (*n) * sizeof(Person));
    heapifyMin(*students, *n, 0);
}

int main()
{
    Person *students = NULL;
    int n = 0;
    int choice;

    printf("\nMAIN MENU (HEAP)\n");
    printf("1. Read Data\n");
    printf("2. Create a Min-heap based on the age\n");
    printf("3. Create a Max-heap based on the weight\n");
    printf("4. Display weight of the youngest person\n");
    printf("5. Display age of the person with max weight\n");
    printf("6. Insert a new person into the Min-heap\n");
    printf("7. Delete the oldest person\n");
    printf("8. Exit\n");
    do
    {
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            readData(&students, &n);
            break;
        case 2:
            createMinHeapAge(students, n);
            break;
        case 3:
            createMaxHeapWeight(students, n);
            break;
        case 4:
        {
            int weight = findYoungestWeight(students, n);
            if (weight != -1)
                printf("Weight of youngest student: %.2f kg\n", weight * 0.453592); // Convert pounds to kg
            break;
        }
        case 5:
        {
            int age = findAge(students, n);
            printf("Age of person with max weight: %d\n", age);
            break;
        }
        case 6:
        {
            Person newPerson;
            printf("Enter details of new person (ID, Name, Age, Height, Weight):\n");
            scanf("%d %s %d %d %d", &newPerson.id, newPerson.name, &newPerson.age, &newPerson.height, &newPerson.weight);
            insertIntoMinHeap(&students, &n, newPerson);
            break;
        }
        case 7:
            deleteOldest(&students, &n);
            break;
        case 8:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid option. Try again.\n");
        }
    } while (choice != 8);

    free(students);
    return 0;
}