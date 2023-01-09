#include<stdio.h>
#include<math.h>

float length(float vec[3][3],int a){
	float l=0,len;
	for(int i=0;i<3;i++){
		l+=vec[i][a]*vec[i][a];
	}
	len=sqrt(l);
	return len;
}

float unit_vector(float vec[3][3],int a,float arr[]){
	float l;
	l=length(vec,a);
	if(l==0){
		for(int i=0;i<3;i++){
		arr[i]=0;
		}
	}
	else{
	   for(int i=0;i<3;i++){
 	  arr[i]=vec[i][a]/l;
	   }
	}
}

float dot_prod(float vec[3][3],int a,int b){
	float d;
	for(int i=0;i<3;i++){
		d+=vec[i][a]*vec[i][b];
	}
	return d;
}

float cross_prod(float vec[3][3],int a,int b,float arr[]){
	arr[0]=vec[1][a]*vec[2][b]-vec[1][b]*vec[2][a];
	arr[1]=vec[2][a]*vec[0][b]-vec[2][b]*vec[0][a];
	arr[2]=vec[0][a]*vec[1][b]-vec[0][b]*vec[1][a];
}

float volume(float vec[3][3]){
    float arr[3];
    int a=1,b=2;
	arr[0]=vec[1][a]*vec[2][b]-vec[1][b]*vec[2][a];
	arr[1]=vec[2][a]*vec[0][b]-vec[2][b]*vec[0][a];
	arr[2]=vec[0][a]*vec[1][b]-vec[0][b]*vec[1][a];
	float d;
	for(int i=0;i<3;i++){
		d+=vec[i][0]*arr[i];
	}
	return d;
}
int main(){
    float vectr[3][3];
    for(int i=0;i<3;i++){
         printf("Enter coordinates of vector %d (index is %d) separated by comma's(Ex:1,2,3):",i+1,i);
         scanf("%f,%f,%f",&vectr[0][i],&vectr[1][i],&vectr[2][i]);
    }
    char s[]="1.Length of vector.\n2.Unit vector\n3.Dot product of two vectors\n4.Cross product of two vectors\n5.Volume subtended by three vectors\n0.To exit\n";

int stat=1;

while(stat!=0){
    printf("\n%s",s);
    printf("Enter operation you want to perform:");
    scanf("%d",&stat);
    printf("\n");
    if(stat>0 && stat<6){
    printf("Index of vector 1 is 0 & Index of vector 2 is 1 & so on\n");
    float arr1[3];
    switch(stat){
    case 1:{
        printf("Enter the required vector index:");
        int a;
        scanf("%d",&a);
        if(a==0 || a==1 || a==2){
        printf("Length of vector is:%f\n",length(vectr,a));
        }
        else printf("Invalid input");
        break;
    }
    case 2:{
        printf("Enter the required vector index:");
        int a;
        scanf("%d",&a);
        if(a==0 || a==1 || a==2){
        unit_vector(vectr,a,arr1);
        printf("Unit vector of given vector:%f,%f,%f\n",arr1[0],arr1[1],arr1[2]);
        }
        else printf("Invalid input");
        break;
    }
    case 3:{
        printf("Enter index of the two vectors separated by comma's(Ex:1,2)");
        int a,b;
        scanf("%d,%d",&a,&b);
        if(a==0 || a==1 || a==2 || b==0 || b==1 || b==2){
        printf("Dot product of vectors:%f\n",dot_prod(vectr,a,b));
        }
        else printf("Invalid input");
        break;
    }
    case 4:{
        printf("Enter index of the two vectors separated by comma's(Ex:1,2)");
        int a,b;
        scanf("%d,%d",&a,&b);
        if(a==0 || a==1 || a==2 || b==0 || b==1 || b==2){
        cross_prod(vectr,a,b,arr1);
        printf("Cross product of vectors:%f,%f,%f\n",arr1[0],arr1[1],arr1[2]);
        }
        else printf("Invalid input");
        break;
    }
    case 5:{
        printf("Volume subtended by three vectors:%f\n",volume(vectr));
    }
    }
 }
    else printf("Invalid input");
}
}