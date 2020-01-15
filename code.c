#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

# define BUF_SIZE 1024
 int main( int argc, char* argv[])
 {
     int fp,fq;
     ssize_t bytesRead,bytesWritten;//no of bytes returend by read and write
     char buffer[BUF_SIZE];
     mode_t mode=S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IROTH | S_IXOTH;

     fp=open(argv[1], O_RDONLY);
     if(fp==-1)
     {   
         perror("THE SOURCE FILE CANNOT BE OPENED IN READ MODE");
         return 1;
        
     }
     else
     {
         printf("sucessful read");

     }
     fq=open(argv[2],O_WRONLY | O_CREAT,mode);//O_EXCL
     if(fq==-1)
     {
         perror("FILE COULD NOT BE OPENED");
         return 2;
     }
     while ((bytesRead=read(fp,&buffer,BUF_SIZE)>0))
     {   
        bytesWritten=write(fq,&buffer,(ssize_t)bytesRead);

     }
    //  for(int i=0;i<1;i++){
    //      bytesRead=read(fp,&buffer,BUF_SIZE);
    //      bytesWritten=write(fq,&buffer,bytesRead);


    //  }
     close(fp);
     close(fq);
     return 0;
     

 }
