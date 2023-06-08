#include "Selection.h"
#define MAX_CHARS 1000

//FUNCTION  TO SELECT THE CHOICE

void selection(void)
{
    int option = 0;
    
    char characters[MAX_CHARS];
    
    FILE *information = fopen("MetalInformation.txt", "w+");
    
    if (information == NULL)
    {
        
        printf("Failed to open information.");
        
        return;
        
    }
    
    fprintf(information, "Martensite, Bainite, and Austenite are three significant phases in the steel transformation process. Each phase has unique properties and plays a crucial role in determining the final characteristics of the steel.");
    
    fprintf(information, "Martensite is a hard, brittle, and highly stressed phase that forms when steel is rapidly cooled from the austenitic phase. This phase is responsible for the hardness and strength of steel, making it ideal for high-stress applications such as cutting tools, gears, and bearings. However, due to its brittleness, martensite is also highly susceptible to fracture and cracking.");
    
    fprintf(information, "Bainite is a mixture of ferrite and cementite that forms when steel is cooled at a moderate rate. It is stronger and tougher than martensite and is commonly used in applications that require high strength and toughness, such as gears, shafts, and springs. Bainite is less brittle than martensite and can withstand higher levels of stress without fracturing.\n\n");
    
    fprintf(information, "Austenite is a phase that forms when steel is heated to high temperatures. It has a face-centered cubic crystal structure and is non-magnetic. Austenite is relatively soft and ductile and is commonly used in applications that require excellent formability, such as sheet metal fabrication and wire production.");
    
    fprintf(information, "Understanding the properties and characteristics of these three phases is critical to the design and manufacture of steel products. The temperature range and cooling rate necessary to achieve each phase can be calculated using complex mathematical formulas and empirical data. The use of computer programs such as the one described in this project information page can make these calculations more accessible, precise, and user-friendly.");
    
    fprintf(information, "In conclusion, the study and understanding of the martensite, bainite, and austenite phases in steel are crucial to the development of high-performance steel products. The program described in this project information page is an innovative tool designed to provide precise temperature information for phase transformations in steel, making it an invaluable resource for researchers, students, and professionals in the fields of materials science, engineering, and related areas.\n");
    
    fseek(information, 0, SEEK_SET);
    
    while (fgets(characters, MAX_CHARS, information) != NULL)
    {
        
        printf("%s", characters);
        
    }
    
    fclose(information);
    
    do
    {
        printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tCHOOSE THE OPTION TO FIND TEMPERATURE\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t1:Martensite\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t   :- Start\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t   :- Finish\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t2:Bainite\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t   :- Start\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t   :- Finish\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t3:Austenite\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t   :- Start\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t   :- Finish\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t4:File Managment\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t5:EXIT\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tCHOICE: ");
        
        if(scanf("%d", &option)==1)
        {
            
            switch(option)
            {
                    
                case 1:
                    
                    Martensite();
                    
                    break;
                    
                case 2:
                    
                    Bainite();
                    
                    break;
                    
                case 3:
                    
                    Austenite();
                    
                    break;
                    
                case 4:
                    
                    fileManagment();
                    
                    break;
                    
                case 5:
                    
                    return;
                    
                default:
                    
                    printf("Invalid option. Please choose a valid option.\n");
                    
                    break;
                    
            }
        }
        else
        {
            printf("Invalid Input\n");
            return;
        }
        
    } while(option != 5);
    
}
