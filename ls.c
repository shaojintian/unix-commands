#include <dirent.h>
#include <stdio.h>
void do_ls(int argc, char* target_dp);
//ls directory_name 
//char* = string 
int main(int argc,char* argv[]){
    if(argc==1){
        do_ls(argc,".");
        return 0;
    }else if(argc==2){
        //argc==2
	    do_ls(argc,argv[1]);
        return 0;
    }
    //argc>=3
	//printf("usage:./ls directory_name...\n");
    for (size_t i = 1; i <argc ; i++){
        printf("%s:\n",argv[i]);
        do_ls(argc,argv[i]);
    }
    return 0;        
}

void do_ls(int argc,char* target_dp){
    DIR*			dp;
	struct dirent*	dirp;
    
    if((dp=opendir(target_dp))==NULL){
		printf("can not open %s\n",target_dp);
        return;
	}
	while((dirp=readdir(dp))!=NULL){
        char* d_name = dirp->d_name;
		if(d_name[0]=='.')continue;
        printf("%s\n",d_name);
	}
    //printf("\n");
	closedir(dp);
}



// code like this 
// if(corner case){
// 	.... 
// 	return err;
// }
// do right logic


// DO NOT!!!!!

// if(limited right check bound){
// 	....
// 	...
// 	...
// 	...
// 	...
// 	...
// 	right logic
// }