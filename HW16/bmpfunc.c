#include "bmpfunc.h"
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#ifndef FUNC_GIVEN

int RGB2Gray(unsigned char red, unsigned char green, unsigned char blue){
	// this is a commonly used formula
	double gray = 0.2989 * red + 0.5870 * green + 0.1140 * blue;
	return (int) gray;


}

#endif


#ifndef IMG_TO_GRAY

BMPImage * ImgToGray(BMPImage * image){

	// allocate space for the image
	// the image has the same size
	// therefore the header has to stay the same
	BMPImage* gray_image = malloc(sizeof(BMPImage));
	int i = 0;
	if(gray_image == NULL){
		return NULL;
	}
	gray_image -> data = malloc(sizeof(unsigned char)* ((image->header).imagesize));
	if(gray_image ->data == NULL){
		return NULL;
	}
	gray_image -> header = image -> header;
	for(i = 0;i<(image->header).imagesize;i += 3){
		gray_image->data[i] = (char)RGB2Gray(gray_image->data[i+2],gray_image->data[i+1],gray_image->data[i]);
		gray_image->data[i+1] = (char)RGB2Gray(gray_image->data[i+2],gray_image->data[i+1],gray_image->data[i]);
		gray_image->data[i+2] = (char)RGB2Gray(gray_image->data[i+2],gray_image->data[i+1],gray_image->data[i]);
	}
	//printf("Error converting to Gray image\n");

	return gray_image;

}

#endif


#ifndef ADAPTIVE_THRESHOLDING
/*
   BMPImage * AdaptiveThresholding(BMPImage * grayImage, int radius, int epsilon){
// allocate space for the image
// the image has the same size
// therefore the header has to stay the same
int i = 0;
int row = 0;
int j = 0; 
int col = 0;
int k = 0;
int l = 0;  
BMPImage* adaptive=malloc(sizeof(BMPImage));
if(adaptive==NULL){
return NULL;
}
adaptive->header=grayImage->header;
int rows=adaptive->header.height;
int cols=adaptive->header.width;
int **image =malloc(sizeof(int*)*rows);
for(i=0;i<rows;i++){
image[i]=malloc(sizeof(int*)*cols);
}
int byte=0;
for(row=0;row<rows;row++){
for(col=0;col<cols;col++){
image[row][col]=grayImage->data[byte];
byte=byte+3;
}

}
adaptive->data=malloc(sizeof(unsigned char)*adaptive->header.imagesize);
int pixel=0;
for(i=0;i<rows;i++){
for(j=0;j<cols;j++){
int startRow=i-radius;
int startCol=j-radius;
int endRow=i+radius;
int endCol=j+radius;
if(startRow<0){
startRow=0;
}
if(startCol<0){
startCol=0;
}
if(endRow>=rows){
endRow=rows-1;
}
if(endCol>=cols){
endCol=cols-1;
}
int key=image[i][j];
int sum=0;
int counter=0;
for(k=startRow;k<=endRow;k++){
for(l=startCol;l<=endCol;l++){
counter++;
sum+=image[k][l];
}
}
double light=sum/counter;
if(key<=(light-epsilon)){
adaptive->data[pixel]=0x00;
adaptive->data[pixel+1]=0x00;
adaptive->data[pixel+2]=0x00;
}
else{
adaptive->data[pixel]=0xff;
adaptive->data[pixel+1]=0xff;
adaptive->data[pixel+2]=0xff;
}
pixel=pixel+3;
}
}
for(i=0;i<rows;i++){
	free(image[i]);
}
free(image);

return adaptive;

}
*/

#endif
