#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<sys/ioctl.h>
 
#define WR_VALUE _IOW('a','a',int32_t*)
#define RD_VALUE _IOR('a','b',int32_t*)
 
int main()
{
        int fd;
        int32_t value, number;
        printf("*******Userspace application*******\n");
 
        printf("\nOpening Driver....\n");
        fd = open("/dev/ts_device", O_RDWR);//here if we try to chahnge any of the file name we will get different errors like 
        if(fd < 0) //fd is not valid when fd is other than 0 or -1 as open will return these two.
		{           //EINVAL when arg or command is not valid.
                printf("Cannot open device file...\n");
                return 0;
        }
 
		while(1)
		{
			printf("--------------------------------------------\n");
			printf(" 1.Read\n 2.Write\n 3.Exit\n");
			printf("Enter the IOCTL operation to perform:");
			scanf("%d",&number);
			//return value of printf is number if characters that are printed and scanf is no.of inputs scanned successfully upto eof
			switch(number)
			{
				case 1:
					printf("Reading Value from Driver\n");
					ioctl(fd, RD_VALUE, (int32_t*) &value);
					printf("Value is %d\n", value);
					break;
				case 2:
					printf("Enter the Value to send\n");
					scanf("%d",&value);
					printf("Writing Value to Driver\n");
					ioctl(fd, WR_VALUE, (int32_t*) &value); //when adress or any ioctl command is not given correctly it will return -1
					break;
				case 3:
					printf("Closing Driver\n");
					close(fd);
					return 0;//here exit function can be used.{exit(0)-for normal termination of program,exit(1)-for abnormal termination}
				default:
					printf("Enter between 1-3 \n");
				
			}
		}
        return 0;//this means that the program executed successfully whereas 1 means some error while executing.
}
