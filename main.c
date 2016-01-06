#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    FILE *fp;
    char filename[] = "names.txt";
    char string[40][100];

    fp = fopen (filename, "r");
    int i=0;
    int n=0;
    while(!feof(fp))
    {
        fgets (string[n], sizeof(string[n]), fp);
        strtok(string[n], "\n");
        fscanf(fp,"\n");
        n++;
    }
    fclose (fp);
    for(i=0; i<n; i++)
    {
        printf ("%s\n", string[i]);
        CreateDirectory(string[i],NULL);
    }

    printf("\nnumber of folders created: %d",n);
    return 0;
}

/*

void LoadFile()
{
    char kbd;
    n = 0;
    strcpy(filename, "Contacts.txt");
    fptr = fopen(filename, "r");
    while (fptr == NULL)
    {
        printf("Loaded File doesn't exist. Would you like to create or Load another one?\n");
        printf("Press L to Load \nPress W to Create a new file: ");
        scanf("\n");
        kbd = getchar();
        switch(kbd)
        {
        case 'L':
            printf("Enter File path: ");
            scanf(" %[^\n]",fptr);
            scanf("\n");
            getchar();
            break;
        case 'W':
            printf("Enter File Name: ");
            scanf("%s",filename);
            strcat(filename,".txt");
            fptr = fopen(filename, "w");
            printf("File created successfully.");
            MainMenu();
        }

    }

    while(!feof(fptr))
    {
        fscanf(fptr,"%[^,],%[^,],%[^,],%[^,],%s",person[n].LastName,
               person[n].FirstName,
               person[n].City,
               person[n].Address,
               person[n].PhoneNumber);
        fscanf(fptr,"\n");
        n++;
    }
    if(strcmp(person[0].LastName,"\000")==0)
        n = 0;
    fclose(fptr);
}
*/
