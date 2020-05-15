#include <dirent.h>
#include <stdio.h>

//ls directory_name 
//char* = string 
int main(int argc,char* argv[]){
	if(argc!=2){
		printf("usage:./ls directory_name\n");
		return 0;
	}
	DIR*			dp;
	struct dirent*	dirp;
	if((dp=opendir(argv[1]))==NULL){
		printf("can not open %s\n",argv[1]);
	}
	while((dirp=readdir(dp))!=NULL){
        char* d_name = dirp->d_name;
		if(d_name[0]=='.')continue;
        printf("%s\n",d_name);
	}

	closedir(dp);
	return 0;
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