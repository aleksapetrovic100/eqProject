#include "coeficients.h"
#include "result.h";

#include stdio.h
#include stdlib.h
#include string.h
#include unistd.h
#include math.h

#define PACKAGE_LENGTH 1024
#define NUMBER_OF_PACKAGES 215
#define NUMBER_OF_AMPLIFICATIONS 10
#define NUMBER_OF_BOUNDARIES 9

int main(void)
{
    FILE* fp1, fp2;
    int i, j;
    unsigned int* hardware_res;

    for(i = 0; i < (NUMBER_OF_AMPLIFICATIONS+NUMBER_OF_BOUNDARIES); i++)
    {
        fp1 = fopen("/dev/my_IP", "w");
        if(fp1 == NULL)
        {
            printf("Cannot open /dev/my_IP for write\n");
				return -1
        }
        if(i < NUMBER_OF_AMPLIFICATIONS)
            fprintf(fp1,"%d,%#08x\n",i,p[i]);
        else
            fprintf(fp1,"%d,%#08x\n",i,pr[i - 10]);
        fclose(fp1);
		if(fp1 == NULL)
		{
			printf("Cannot close /dev/my_IP\n");
			return -1;
		}
    }

    for(i = 0; i < 1; i++) // kada testiramo sve pakete for(i = 0; i < NUMBER_OF_PACKAGES; i++)
    {
        for(j = 0; j < PACKAGE_LENGTH; j++)
        {
            fp2 = fopen("/dev/data_mover", "w");
            if(fp2 == NULL)
            {
                printf("Cannot open /dev/data_mover for write\n");
				return -1
            }
            fprintf(fp2,"%d,%#08x\n",j,audio[(i*PACKAGE_LENGTH) + j]);
            fclose(fp2);
		    if(fp2 == NULL)
		    {
			    printf("Cannot close /dev/data_mover\n");
			    return -1;
		    }
        }
        hardware_res =  = (unsigned int *) malloc(PACKAGE_LENGTH*sizeof(unsigned int));

        for(j = 0; j < PACKAGE_LENGTH; j++)
        {
            fp2 = fopen("/dev/data_mover", "r");
            if(fp2 == NULL)
            {
                printf("Cannot open /dev/data_mover for read\n");
				return -1
            }
            fscanf(fp2,"%#08x\n",hardware_res[j]);
            fclose(fp2);
		    if(fp2 == NULL)
		    {
			    printf("Cannot close /dev/data_mover\n");
			    return -1;
		    }
        }
        for (j = 0; j != PACKAGE_LENGTH; ++j)
		{
            if(abs(result[j] - hardware_res[j]) > error_tolerance)
			{
                printf("Test %d failed.\n", i);
                printf("Element with index %d\n", j);
                printf("Expected value %#08x\n", result[j]);
                printf("Received value %#08x\n", hardware_res[j]);
                return;
			}
		}
		printf("Test %d passed.\n", i);
    }
    return 0;
}