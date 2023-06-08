#include "Functioning.h"
#define MAX_CHAR 1000

// STRUCTURE FOR PHASE

typedef struct Phases
{
    
    int ID;
    
    char formulaName1[50];
    float output1;
    
    char formulaName2[50];
    float output2;
    
    char formulaName3[50];
    float output3;
    
    char formulaName4[50];
    float output4;
    
}PH;

PH Phase;

//FUNCTION TO DISPLAY OUTPUT.

void display(PH **phase)
{
    printf("\n\n\n\t\tOUTPUT\n\n");
    printf("ID: %d\n\n",(*phase)->ID);
    
    printf("Formula Name 1: %s\n", (*phase)->formulaName1);
    printf("Output 1: %f\n\n", (*phase)->output1);
    
    printf("Formula Name 2: %s\n", (*phase)->formulaName2);
    printf("Output 2: %f\n\n", (*phase)->output2);
    
    printf("Formula Name 3: %s\n", (*phase)->formulaName3);
    printf("Output 3: %f\n\n", (*phase)->output3);
    
    printf("Formula Name 4: %s\n", (*phase)->formulaName4);
    printf("Output 4: %f\n\n", (*phase)->output4);
}

// FUNCTION TO DELETE ALL RECORDS.

void deleteAllRecords(void)
{
    FILE *fp;
    
    fp = fopen("record.txt", "wb");

    if (fp == NULL)
    {
        printf("\nFile not found.");
        
        return;
    }

    fclose(fp);
    
    printf("\nAll records deleted successfully!");
    
    return;
    
}

// FUNCTION TO DISPLAY AND DELETE RECORDS.


void displayAndDelete(void)
{
    FILE *fp, *temp;
    
    PH *ph;
    
    int no,found=0;
    
    fp = fopen("record.txt", "rb");
    temp = fopen("temp.txt", "wb");

    printf("\nEnter the unique ID number whose data is to be searched and deleted.\n\nNUMBER: ");
    
    scanf("%d", &no);

    if (fp == NULL)
    {
        printf("\nFile not found.");
        
        return;
    }
    else
    {
        if (fseek(fp, 0, SEEK_END) == 0)
        {
            printf("\nFile is empty.");
            
            fclose(fp);
            
            return;
        }
        
        rewind(fp);
        
        while (fread(&Phase, sizeof(PH), 1, fp) == 1)
        {
            if (Phase.ID == no)
            {
                ph = &Phase;
                
                display(&ph);
                
                found = 1;
            }
            else
            {
                fwrite(&Phase, sizeof(PH), 1, temp);
            }
        }
        
        if (!found)
        {
            printf("\nRecord not found.");
        }
        
        fclose(fp);
        
        fclose(temp);
        
        remove("record.txt");
        
        rename("temp.txt", "record.txt");
    }
    
    return;
    
}

// FUNCTION TO DISPLAY ALL RECORDS.


void displayAllRecord(void)
{
    FILE *fp;
    
    PH *ph;
    
    fp = fopen("record.txt", "rb");
    
    if (fp == NULL)
    {
        printf("\nFile not found.");
        
        return;
    }
    
    else
    {
        if (fseek(fp, 0, SEEK_END) == 0)
        {
            printf("\nFile is empty.");
            
            fclose(fp);
            
            return;
        }
        
        rewind(fp);
        
        while (fread(&Phase, sizeof(PH), 1, fp) == 1)
        {
            ph = &Phase;
            display(&ph);
        }
    }
    
    fclose(fp);
    
    return;
    
}

// FUNCTION TO SEARCH AND DISPLAY RECORDS.

void searchAndDisplay(void)
{
    FILE *fp;
    
    PH * ph;
    
    int no;
    
    fp=fopen("record.txt","rb");
    
    printf("\nEnter the unique ID number whose data is to be Searched and Displayed.\n\nNUMBER: ");
    
    scanf("%d",&no);
    
    if(fp == NULL)
    {
        printf("\nFile not found.");
        
        return;
    }
    else
    {
        if (fseek(fp, 0, SEEK_END) == 0)  //
        {
            printf("\nFile is empty.");
            
            fclose(fp);
            
            return;
        }
        
        rewind(fp);
        
        while(fread(&Phase,sizeof(PH),1,fp) == 1)
        {
            if(Phase.ID == no)
            {
                ph=&Phase;
                
                display(&ph);
                
                break;
            }
        }
        
        if (feof(fp))
        {
            printf("\nRecord not found.");
        }
    }
    
    fclose(fp);
    
    return;
    
}

// FUNCTION TO SEARCH RECORDS.

int searchRecord(void)
{
    FILE *fp;
    
    int no,flag=0;
    
    fp=fopen("record.txt","rb");
    
    printf("\nEnter the unique ID number whose data is to be Searched.\n\nNUMBER: ");
    
    scanf("%d",&no);
    
    if(fp == NULL)
    {
        printf("\nFile not found.");
    }
    
    else
    {
        if (fseek(fp, 0, SEEK_END) == 0)
        {
            printf("\nFile is empty.");
            
            fclose(fp);
            
            return 0;
        }
        
        rewind(fp);
        
        while(fread(&Phase,sizeof(PH),1,fp) == 1)
        {
            if(Phase.ID == no)
            {
                flag=1;
                
                break;
            }
        }
    }
    
    fclose(fp);
    
    return flag;
}

// FUNCTION TO ADD RECORDS TO FILE.

void addRecordtoFile(PH** phase)
{
    FILE * fp;
    
    fp=fopen("record.txt", "ab");
    
    if(fp == NULL)
    {
        printf("\nError in opening file.");
        
        return;
    }
    
    else
    {
        fwrite(*phase, sizeof(PH), 1, fp);
    }
    
    fclose(fp);
    
}

// FUNCTION TO FIND CRITICAL TRANSFORMATION TEMPERATURE.

float findA3(float c, float si, float mn, float cr, float ni, float mo)
{
    int option=0;
    
    float A3=0.0;
    
    printf("\nA3 is the temperature at which austenite starts to form when steel is heated. It is also known as the critical transformation temperature.At temperatures below A3, the steel is in the ferrite-pearlite phase, and as the temperature increases above A3, the steel begins to transform into austenite. The exact temperature of A3 depends on the composition of the steel and can be determined using different methods, such as the lever rule and the WRC-1992 diagram. A3 is an essential factor in the heat treatment of steel, as it determines the temperature required to transform the steel into austenite and subsequently into other crystal structures.If you have the value of A3 please provide us or else lets calculate it.");
    
    do
    {
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tDo you have the value of Critical Transformation Temperature?\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t1: Yes, Proceed\n\t\t\t\t\t\t\t\t\t\t\t\t\t2: NO, Let's calculate\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tChoice: ");
        
            scanf("%d", &option);

            switch (option)
            {
                case 1:
                    
                    printf("\nEnter the Critical Transformation Temperature: ");
                    
                    scanf("%f", &A3);
                    
                    break;
                    
                case 2:
                    
                    A3 = 910 - (0.45 * c) - (0.28 * si) - (0.09 * mn) - (0.12 * cr) - (0.14 * ni) - (0.03 * mo);
                    
                    break;
                    
                default:
                    
                    printf("Invalid option. Please choose a valid option.\n");
                    
            }
        
        } while (option != 1 && option != 2);

    return A3;
    
}

// FUNCTION TO FIND AUSTENITE FINISH TEMPERATURE.

PH* austeniteFinish(PH* phase)
{
    int i,no;
    
    float values[7];
    
    char *elements[] = {"Carbon", "Manganese", "Chromium", "Molybdenum", "Nickel", "Silicon", "Phosphorus"};

    printf("\nEnter the ID number for the record: ");
    
    scanf("%d", &no);

    printf("\nEnter the appropriate weight percentage for further calculations:\n\n");

    for (i = 0; i < 7; i++)
    {
        printf("%s: ", elements[i]);
        
        scanf("%f", &values[i]);
    }

    float carbon = values[0];
    float manganese = values[1];
    float chromium = values[2];
    float molybdenum = values[3];
    float nickel = values[4];
    float silicon = values[5];
    float phosphorus = values[6];
    
    phase->ID=no;
    
    strcpy(phase->formulaName1,"Emphirical Formula");
    phase->output1= 723+(0.45*carbon)+(10.5*manganese)+(1.75*nickel)+(0.3*chromium);
    
    strcpy(phase->formulaName2," Low Steel Alloys");
    phase->output2= 910-(400*carbon)-(30*silicon)-(60*manganese)-(15*chromium)-(10*nickel);
    
    strcpy(phase->formulaName3,"High Alloy Steels");
    phase->output3= 1353-(12.6*carbon)-(16.9*manganese)-(10.8*silicon)-(1.01*phosphorus)-(0.8*nickel)-(4.4*chromium)-(2.8*molybdenum);

    strcpy(phase->formulaName4,"Stainless Steels");
    phase->output4= 739+(0.42*carbon)+(0.04*manganese)-(0.004*phosphorus)-(0.06*silicon)+(37*nickel)+(20*chromium)-(2.2*molybdenum);
    
    return phase;

}

// FUNCTION TO FIND AUSTENITE START TEMPERATURE.

PH* austeniteStart(PH* phase)
{
    int i,no;
    
    float A3 = 0.0;
    
    float values[11];
    
    char *elements[] = {"Carbon", "Manganese", "Chromium", "Molybdenum", "Nickel", "Silicon", "Vanadium", "Phosphorus", "Potassium", "Boron", "Copper"};
    
    printf("\nEnter the ID number for the record: ");
    
    scanf("%d", &no);

    printf("\nEnter the appropriate weight percentage for further calculations:\n\n");

    for (i = 0; i < 11; i++)
    {
        printf("%s: ", elements[i]);
        
        scanf("%f", &values[i]);
    }

    float carbon = values[0];
    float manganese = values[1];
    float chromium = values[2];
    float molybdenum = values[3];
    float nickel = values[4];
    float silicon = values[5];
    float vanadium = values[6];
    float phosphorus = values[7];
    float potassium = values[8];
    float boron = values[9];
    float copper = values[10];

    A3 = findA3(carbon,silicon,manganese,chromium,nickel,molybdenum);
    
    phase->ID=no;

    strcpy(phase->formulaName1,"Koistinen and Lu");
    phase->output1= (A3+(150+(4.3*carbon)+(21*silicon)+(25*manganese)+(50*chromium)+(28*nickel)+(21*molybdenum)-(3*vanadium)))/(4.3+(21*silicon)+(25*manganese)+(50*chromium)+(28*nickel)+(21*molybdenum)-(3*vanadium));
    
    strcpy(phase->formulaName2,"Sievert's Law");
    phase->output2= A3+potassium*(carbon/(1-carbon));
    
    strcpy(phase->formulaName3,"Brook and Leslie");
    phase->output3= A3+(660-A3)*(carbon+(silicon/7.5)+(phosphorus/17)+(manganese/6)+(nickel/30)+(chromium/15)+(molybdenum/30)+(copper/30)+(vanadium/20)+(boron/10));

    strcpy(phase->formulaName4,"Miedema's formula");
    phase->output4=A3+40*(carbon+(manganese/6));
    
    return phase;

}

// FUNCTION TO FIND BAINITE FINISH TEMPERATURE.

PH* bainiteFinish(PH* phase)
{
    int i,no;
    
    float carbon, manganese, chromium, molybdenum, nickel, silicon, phosphorus;
    
    char *elements[] = {"Carbon", "Manganese", "Chromium", "Molybdenum", "Nickel", "Silicon", "Phosphorus"};
    float values[7];

    printf("\nEnter the ID number for the record: ");
    
    scanf("%d", &no);

    printf("\nEnter the appropriate weight percentage for further calculations:\n\n");

    for (i = 0; i < 7; i++)
    {
        printf("%s: ", elements[i]);
        
        scanf("%f", &values[i]);
    }

    carbon = values[0];
    manganese = values[1];
    chromium = values[2];
    molybdenum = values[3];
    nickel = values[4];
    silicon = values[5];
    phosphorus = values[6];

    phase->ID=no;

    strcpy(phase->formulaName1,"TTT diagram equation");
    phase->output1= 727+(12.4*carbon)+(18*silicon)+(36*nickel)+(2.9*molybdenum);
    
    strcpy(phase->formulaName2,"Koistinen-Marburger equation");
    phase->output2= 810-(270*carbon)-(90*manganese)-(37*nickel)-(70*chromium)-(83*molybdenum);
    
    strcpy(phase->formulaName3,"Averbach-cohen equation");
    phase->output3= 750-(145*carbon)-(12.5*phosphorus)-(4*silicon)-(22*manganese);

    strcpy(phase->formulaName4,"Bruskiewiez equation");
    phase->output4=541+(273*carbon)-(161*silicon)-(15*manganese)-(29*nickel);
    
    return phase;

}

// FUNCTION TO FIND BAINITE START TEMPERATURE.

PH* bainiteStart(PH* phase)
{
    int i,no;
    
    float values[13];
    
    char *elements[] = {"Carbon", "Manganese", "Chromium", "Molybdenum", "Nickel", "Silicon", "Vanadium", "Tungsten", "Phosphorus", "Nitrogen", "Sulfur", "Aluminium", "Cobalt"};

    printf("\nEnter the ID number for the record: ");
    
    scanf("%d", &no);

    printf("\nEnter the appropriate weight percentage for further calculations:\n\n");

    for (i = 0; i < 13; i++)
    {
        printf("%s: ", elements[i]);
        
        scanf("%f", &values[i]);
    }

    float carbon = values[0];
    float manganese = values[1];
    float chromium = values[2];
    float molybdenum = values[3];
    float nickel = values[4];
    float silicon = values[5];
    float vanadium = values[6];
    float tungsten = values[7];
    float phosphorus = values[8];
    float nitrogen = values[9];
    float sulfur = values[10];
    float aluminium = values[11];
    float cobalt = values[12];
    
    phase->ID=no;

    strcpy(phase->formulaName1,"Kanno Formula for low Alloys");
    phase->output1= 590+(5.75*carbon)+(3.5*silicon)+(10*chromium)+(1.8*molybdenum)+(0.8*vanadium);
    
    strcpy(phase->formulaName2,"Gross Man Formula for High Carbon");
    phase->output2= 737-(10.07*carbon)-(3.08*manganese)-(18.35*chromium)-(1.48*nickel)-(1.25*molybdenum);
    
    strcpy(phase->formulaName3,"Totten Formula");
    phase->output3= 600+(5.5*carbon)+(13*chromium)+(1.5*manganese)+(6*molybdenum)+(50*nitrogen)+(30*nickel)+(12*silicon)+(7*tungsten)-(10*phosphorus)-(10*sulfur);

    strcpy(phase->formulaName4,"Miedema's formula");
    phase->output4=723-(170*carbon)-(30*silicon)-(740*manganese)-(760*chromium)-(210*molybdenum)-(90*vanadium)-(11*nickel)-(9*cobalt)-(500*aluminium);
    
    return phase;

}

// FUNCTION TO FIND MARTENSITE FINISH TEMPERATURE.

PH* martensiteFinish(PH* phase)
{
    int i,no;
    
    float values[7];
    
    char *elements[] = {"Carbon", "Manganese", "Chromium", "Molybdenum", "Nickel", "Silicon", "Vanadium"};

    printf("\nEnter the ID number for the record: ");
    
    scanf("%d",&no);
    
    printf("\nEnter the appropriate weight percentage for further calculations:\n\n");

    for (i = 0; i < 7; i++)
    {
        printf("%s: ", elements[i]);
        
        scanf("%f", &values[i]);
    }
    

    float carbon = values[0];
    float manganese = values[1];
    float chromium = values[2];
    float molybdenum = values[3];
    float nickel = values[4];
    float silicon = values[5];
    float vanadium= values[6];

    phase->ID=no;

    strcpy(phase->formulaName1,"Empirical Formula");
    phase->output1= 1010-(460*carbon)-(50*manganese)-(30*chromium)-(15*nickel)-(10*molybdenum)-(5*silicon);
    
    strcpy(phase->formulaName2,"Low Alloy Steels");
    phase->output2= 540+(5.4*carbon)+(1.8*nickel)+(0.3*molybdenum);
    
    strcpy(phase->formulaName3,"High Alloy Steels");
    phase->output3= 693-(4.3*carbon)-(21*chromium)-(1.5*manganese)-(0.8*molybdenum)-(3.3*vanadium);

    strcpy(phase->formulaName4,"Carbon and Low Alloy Steels");
    phase->output4=386+(1240*carbon)-(830*silicon)-(570*manganese)-(170*chromium)-(100*nickel);
    
    return phase;

}

// FUNCTION TO FIND MARTENSITE START TEMPERATURE.

PH* martensiteStart(PH* phase)
{
    int i, no;
    
    float values[6];
    
    char *elements[] = {"Carbon", "Manganese", "Chromium", "Molybdenum", "Nickel", "Silicon"};
    
    printf("Enter the ID number for the record: ");
    
    scanf("%d", &no);

    printf("\nEnter the appropriate weight percentage for further calculations:\n\n");

    for (i = 0; i < 6; i++)
    {
        printf("%s: ", elements[i]);
        
        scanf("%f", &values[i]);
    }

    float carbon = values[0];
    float manganese = values[1];
    float chromium = values[2];
    float molybdenum = values[3];
    float nickel = values[4];
    float silicon = values[5];
    
    phase->ID=no;

    strcpy(phase->formulaName1,"Savage");
    phase->output1= 500-(300*carbon)-(35*manganese)-(20*chromium)-(15*nickel)-(10*silicon)-(10*molybdenum);
    
    strcpy(phase->formulaName2,"AISI");
    phase->output2= 1050-(500*carbon)-(150*manganese)-(860*chromium)-(380*nickel)-(100*molybdenum)-(60*silicon);
    
    strcpy(phase->formulaName3,"Andrews");
    phase->output3= 990-(540*carbon)-(130*manganese)-(820*chromium)-(420*nickel)-(90*molybdenum)-(60*silicon);

    strcpy(phase->formulaName4,"Andrews 1");
    phase->output4= 539-(423*carbon)-(30*manganese)-(11*nickel)-(9*chromium)-(7*silicon)-(2*molybdenum);
        
    return phase;

}

// FUNCTION TO CALL AUSTENITE START AND FINISH TEMPERATURE.

void Austenite(void)
{
    FILE *information = fopen("AusteniteInformation.txt", "w+");
    
    char characters[MAX_CHAR];
    
    if (information == NULL)
    {
        printf("Failed to open information.");
        
        return;
    }
    
    fprintf(information,"Austenite is a crystal structure of iron and alloys that is formed when steel is heated to high temperatures. It is composed of a face-centered cubic lattice and is known for its high ductility and malleability. Austenite is the only stable phase in iron-carbon alloys at high temperatures, above 912°C.\n\nThe formation of austenite is dependent on the composition of the steel and the temperature at which it is formed. The presence of carbon in the steel increases the temperature required for the formation of austenite. Austenite can be stabilized by the addition of elements such as nickel, manganese, and chromium.\n\nAustenite can be transformed into other crystal structures such as ferrite, pearlite, bainite, and martensite through different cooling rates and heat treatments. The microstructure of austenite can be refined by the addition of alloying elements or by controlling the cooling rate during the formation of other crystal structures.\n\nAustenite has a significant impact on the properties of steel. It increases the ductility and malleability of the steel, making it easier to form and shape. The presence of austenite also affects the hardenability and toughness of steel.\n\nIn summary, austenite is a face-centered cubic lattice crystal structure of iron and alloys that is formed when steel is heated to high temperatures. It is stable at temperatures above 912°C and its formation is dependent on the composition of the steel and the temperature. Austenite can be transformed into other crystal structures through different cooling rates and heat treatments. It plays a significant role in the properties of steel, increasing ductility and malleability while affecting hardenability and toughness.\n");

    fseek(information, 0,SEEK_SET);
    
    while (fgets(characters, MAX_CHAR, information) != NULL)
    {
        printf("%s", characters);
    }
    
    PH *AusteniteStart;
    
    PH *AusteniteFinish;
    
    int option=0,choice=0;
    
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tChoose one of the following:\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t1: Austenite Start Temperature\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t2: Austenite Finish Temperature\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t3: Go Back\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tCHOICE: ");
    
    scanf("%d",&option);
    
    if(option == 4)
    {
        return;
    }
    do
    {
        switch(option)
        {
            case 1:
                
                AusteniteStart=austeniteStart(&Phase);
                
                display(&AusteniteStart);
                
                addRecordtoFile(&AusteniteStart);
                
                printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tDO YOU WANT TO CALCULATE AGAIN\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t1: YES\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t2: NO\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tCHOICE: ");
                
                scanf("%d",&choice);
                
                if(choice == 1)
                {
                    selection();
                }
                
                else
                {
                    return;
                }
                
                break;
                
            case 2:
                AusteniteFinish=austeniteFinish(&Phase);
                
                display(&AusteniteFinish);
                
                addRecordtoFile(&AusteniteFinish);
                
                printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tDO YOU WANT TO CALCULATE AGAIN\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t1: YES\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t2: NO\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tCHOICE: ");
                
                scanf("%d",&choice);
                
                if(choice == 1)
                {
                    selection();
                }
                
                else
                {
                    return;
                }
                
                break;
                
            case 3:
                
                selection();
                
                break;
                
            default:
                
                printf("Invalid option. Please choose a valid option.\n");
                
                break;
                
        }
        
    }while(option != 4);
    
}

// FUNCTION TO CALL BAINITE START AND FINISH TEMPERATURE.

void Bainite(void)
{
    FILE *information = fopen("BainiteInformation.txt", "w+");
    
    char characters[MAX_CHAR];
    
    if (information == NULL)
    {
        printf("Failed to open information.");
        
        return;
    }
    
    fprintf(information, "Bainite is a microstructure that is formed during the cooling of steel. It is composed of two different crystal structures, ferrite and cementite, and is known for its high strength and toughness. Bainite is commonly found in steels that have been quenched at temperatures between 250-550°C. The formation of bainite is dependent on the cooling rate and the temperature at which it is formed. Bainite forms at lower temperatures than martensite, but the cooling rate required is slower. The structure of bainite is made up of fine needle-like ferrite grains that are embedded in a matrix of cementite. This fine microstructure contributes to the high strength and toughness of bainite. Bainite can be further divided into two types: upper bainite and lower bainite. Upper bainite is formed at higher temperatures and has a larger grain size compared to lower bainite. Lower bainite is formed at lower temperatures and has a smaller grain size, which leads to higher strength and toughness. The properties of bainite can be further improved by tempering. Tempering involves heating the steel to a specific temperature, which causes some of the carbon to diffuse out of the cementite and into the ferrite, resulting in a reduction of the hardness and an increase in the toughness of the steel. In summary, bainite is a microstructure of steel that is known for its high strength and toughness. It is formed during the cooling of steel at temperatures between 250-550°C and is composed of fine needle-like ferrite grains embedded in a matrix of cementite. Bainite can be further divided into two types: upper bainite and lower bainite. The properties of bainite can be further improved by tempering, which results in a reduction of hardness and an increase in toughness.");
    
    fseek(information, 0,SEEK_SET);
    
    while (fgets(characters, MAX_CHAR, information) != NULL)
    {
        printf("%s", characters);
    }

    PH *BainiteStart;
    
    PH *BainiteFinish;
    
    int option=0,choice=0;
    
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tChoose one of the following:\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t1: Bainite Start Temperature\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t2: Bainite Finish Temperature\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t3: Go Back\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tCHOICE: ");
    
    scanf("%d",&option);
    
    if(option == 4)
    {
        return;
    }
    do
    {
        switch(option)
        {
            case 1:
                
                BainiteStart=bainiteStart(&Phase);
                
                display(&BainiteStart);
                
                addRecordtoFile(&BainiteStart);
                
                printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tDO YOU WANT TO CALCULATE AGAIN\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t1: YES\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t2: NO\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tCHOICE: ");
                scanf("%d",&choice);
                
                if(choice == 1)
                {
                    selection();
                }
                
                else
                {
                    return;
                }
                
                break;
                
            case 2:
                
                BainiteFinish=bainiteFinish(&Phase);
                
                display(&BainiteFinish);
                
                addRecordtoFile(&BainiteFinish);
                
                printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tDO YOU WANT TO CALCULATE AGAIN\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t1: YES\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t2: NO\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tCHOICE: ");
                
                scanf("%d",&choice);
                
                if(choice == 1)
                {
                    selection();
                }
                
                else
                {
                    return;
                }
                
                break;
                
            case 3:
                
                selection();
                
                break;
                
            default:
                
                printf("Invalid option. Please choose a valid option.\n");
                
                break;
                
        }
        
    }while(option != 4);
    
}

// FUNCTION TO CALL MARTENSITE START AND FINISH TEMPERATURE.

void Martensite(void)
{
    FILE *information = fopen("MartensiteInformation.txt", "w+");
    
    char characters[MAX_CHAR];

    
    if (information == NULL)
    {
        printf("Failed to open information.");
        
        return;
    }
    
    fprintf(information, "Martensite is a type of microstructure that forms in certain steels and other alloys during rapid cooling (quenching) from high temperatures. It is characterized by a highly distorted crystal lattice structure, which gives it unique mechanical and physical properties.\n\nChemical Composition:\nThe chemical composition of martensite varies depending on the type of steel or alloy being used. Generally, it is a highly-carbonized, low-alloy steel that has been quenched from high temperatures.\n\nMicrostructure:\nMartensite is characterized by a needle-like structure that is highly distorted compared to the parent material. The distortion is due to the carbon atoms being trapped in the lattice structure, which causes a significant increase in the strength and hardness of the material. The microstructure of martensite is composed of a highly dense array of dislocations and stacking faults.\n\nMechanical Properties:\nMartensite has exceptional mechanical properties due to its highly distorted crystal lattice structure. It is very hard, with a high tensile strength and good wear resistance. However, it is also very brittle and has low ductility and toughness. This makes it unsuitable for some applications, such as structural materials where impact resistance and ductility are important.\n\nOverall, martensite is a unique microstructure that has exceptional mechanical properties but also significant limitations due to its brittleness and low ductility. Understanding its chemical composition, microstructure, and mechanical properties is important in designing and using it effectively in various applications.\n");

    fseek(information, 0,SEEK_SET);
    
    while (fgets(characters, MAX_CHAR, information) != NULL)
    {
        printf("%s", characters);
    }
    
    PH *MartensiteStart;
    
    PH *MartensiteFinish;
    
    int option=0,choice=0;
    
    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tCHOOSE ONE OF THE FOLLOWING:\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t1: Martensite Start Temperature\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t2: Martensite Finish Temperature\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t3: Go Back\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tCHOICE: ");
    
    scanf("%d",&option);
    
    if(option == 4)
    {
        return;
    }
    do
    {
        switch(option)
        {
            case 1:
                
                MartensiteStart=martensiteStart(&Phase);
                
                display(&MartensiteStart);
                
                addRecordtoFile(&MartensiteStart);
                
                printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tDO YOU WANT TO CALCULATE AGAIN\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t1: YES\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t2: NO\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tCHOICE: ");
                
                scanf("%d",&choice);
                
                if(choice == 1)
                {
                    selection();
                }
                else
                {
                    return;
                }
                
            case 2:
                
                MartensiteFinish=martensiteFinish(&Phase);
                
                display(&MartensiteFinish);
                
                addRecordtoFile(&MartensiteFinish);
                
                printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tDO YOU WANT TO CALCULATE AGAIN\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t1: YES\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t2: NO\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tCHOICE: ");
                
                scanf("%d",&choice);
                
                if(choice == 1)
                {
                    selection();
                }
                else
                {
                    return;
                }
                
            case 3:
                
                selection();
                
                break;
                
            default:
                
                printf("Invalid option. Please choose a valid option.\n");
                
                break;
                
        }
        
    }while(option != 4);
    
}
