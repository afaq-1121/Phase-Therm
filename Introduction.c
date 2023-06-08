#include"Introduction.h"

// FUNCTION TO DISPLAY PROJECT INFORMATION.

void introduction(void)
{
    int option;
    
    char characters[1000];
    
    FILE *information = fopen("ProjectInformation.txt", "w+");
    
    if (information == NULL)
    {
        printf("Failed to open information.");
        
        return;
    }
    
    fprintf(information, "Welcome to my project, an innovative tool designed to provide precise temperature information for phase transformations in steel. Developed using C language, this program is a valuable resource for researchers, and students in the fields of computer science, engineering, and related areas.The program offers a wide range of functions that help you calculate and understand the temperature requirements for phase transformations in steel. With its user-friendly interface, you can easily access the Martensite start and finish temperatures, Bainite start and finish temperatures, and Austenite start and finish temperatures, all by using various formulas. These functions provide a comprehensive understanding of the complex temperature requirements that are necessary for successful phase transformations in steel.\n\nOne of the standout features of this program is its information management system. With this system, you can efficiently store, access, and manage data for future reference. The program also includes search and delete functions that allow you to filter and manipulate data according to your needs.Moreover, each page in the program provides detailed information about the steel whose temperature you are interested in. The information includes the chemical composition of the steel, its microstructure, and its mechanical properties. This feature allows you to access relevant data quickly and efficiently, thus making your research process more streamlined.It is essential to emphasize that this program is for educational purposes only, and should not be used for industrial applications without appropriate expert supervision and without appropriate testing and validation. Please use this program responsibly and within the confines of academic study.\n\nIn summary, my project is a powerful tool that offers a broad range of functions, information management capabilities, and detailed information about steel. Its user-friendly interface, coupled with its wide-ranging capabilities, make it an invaluable resource for anyone interested in the complex processes of phase transformation in steel. We are confident that our program will prove an invaluable resource to your research and study, and we look forward to your feedback and suggestions.\n\n\n");
    
    fprintf(information, "NOTE: The formulas used in this project are for demonstration purposes only and may not be accurate or correct. Please use them with caution and verify their results before making any decisions. We do not guarantee the correctness or reliability of the formulas used, and we are not responsible for any negative consequences that may result from their use. This project is for educational purposes only, and we do not recommend using its results for any practical applications without further testing and verification.\n");
    
    fseek(information, 0, SEEK_SET);
    
    while (fgets(characters, 1000, information) != NULL)
    {
        printf("%s", characters);
    }
    
    fclose(information);

    do
    {
        printf("\n \t\t\t\t\t\t\t\t\t\t\tWOULD YOU LIKE TO PROCEED FURTHUR IN THE CODE\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t1: Continue\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t2: Seek File Managment\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t3: Cancel\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tChoice: ");
        
        if(scanf("%d", &option)==1)
        {
            
            switch (option)
            {
                case 1:
                    
                    selection();
                    
                    break;
                    
                case 2:
                    
                    fileManagment();
                    
                    break;
                    
                case 3:
                    
                    return;
                    
                default:
                    
                    printf("Invalid option. Please try again.\n");
                    
            }
        }
        else
        {
            printf("Invalid Input\n");
            return;
        }
    } while (option != 3);
}
int main()
{
    introduction();
    return 0;
}

