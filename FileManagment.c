#include "FileManagment.h"

void addRecord(void)
{
    int option;
    
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\tChoosing this function may take you to the Selection Page\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t1: CONTINUE\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t2: CANCEL\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tCHOICE: ");
    
    scanf("%d",&option);
    
    if(option == 2)
    {
        return;
    }
    
    else
    {
        do
        {
            switch(option)
            {
                case 1:
                    
                    selection();
                    
                    break;
                    
            }
            
        }while(option != 3);
        
    }
    
}

void fileManagment(void)
{
    int option,flag=0;
    
    char characters[1000];
    
    FILE *information = fopen("ManagmentInformation.txt", "w+");
    
    if (information == NULL)
    {
        printf("Failed to open information.");
        
        return;
    }
    
    fprintf(information,"Welcome to the file management system, an essential component of our project that enables efficient and organized storage, access, and management of data.With our file management system, you can easily add new records with detailed information about the steel and its phase transformation temperature requirements. This feature allows you to keep track of your research progress and ensure that all relevant data is conveniently accessible in one place.In addition to adding new records, you can search for a specific record by using keywords such as the Unique ID. You can also delete a record that you no longer need, thus keeping your data organized and up to date.\n\nFurthermore, our file management system allows you to search for and display the details of a specific record, ensuring that you can easily access relevant data when you need it. If you want to view all the records that you have added, our system allows you to display all records in one place, making it easy to review your research progress.Lastly, if you no longer need the records, our system also offers the option to delete all the records, ensuring that you can maintain a clean and organized workspace.\n\nWe hope that our file management system will provide you with the necessary tools to streamline your research process and ensure that your data is always accessible and up to date.\n");
    
    fseek(information, 0, SEEK_SET);
    
    while (fgets(characters, 1000, information) != NULL)
    {
        printf("%s", characters);
    }
    
    fclose(information);
    
    do
    {
        printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\tWHAT WOULD YOU LIKE TO PROCEED WITH FURTHUR IN THE CODE\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t1: Add new Record\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t2: Search Record\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t3: Search And Display Record\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t4: Display All Record\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t5: Display And Delete Record\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t6: Delete All Records\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tCHOICE: ");
        
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                
                addRecord();
                
                break;
                
            case 2:
                
                flag=searchRecord();
                
                if(flag == 1)
                {
                    printf("\nData Found");
                }
                
                else
                {
                    printf("\nData Not Found");
                }
                
                break;
                
            case 3:
                
                searchAndDisplay();
                
                break;
                
            case 4:
                
                displayAllRecord();
                
                break;
                
            case 5:
                
                displayAndDelete();
                
                break;
                
            case 6:
                
                deleteAllRecords();
                
                break;
                
            default:
                
                printf("Invalid option. Please try again.\n");
                
        }
        
    } while (option != 7);
    
}
