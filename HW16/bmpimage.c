#include "bmpimage.h"

/* check whether a header is valid
 * assume that header has been read from fptr
 * the position of the indicator of fptr is not certain
 * could be at the beginning of the file, end of the file or
 * anywhere in the file
 * note that the check is only for this exercise/assignment
 * in general, the format is more complicated
 */

#ifndef HEADER_VALID

int Is_BMPHeader_Valid(BMPHeader* header, FILE *fptr) {
	// Make sure this is a BMP file
	// skip the two unused reserved fields

	// check the offset from beginning of file to image data
	// essentially the size of the BMP header
	// BMP_HEADER_SIZE for this exercise/assignment
	// printf("header->offset %d\n",header->offset );

	// check the DIB header size == DIB_HEADER_SIZE
	// For this exercise/assignment
	// printf("header->DIB_header_size %d\n",header->DIB_header_size );
	// Make sure there is only one image plane
	// Make sure there is no compression

	// skip the test for xresolution, yresolution

	// ncolours and importantcolours should be 0

	// Make sure we are getting 24 bits per pixel
	// only for this assignment
	// fill in extra to check for file size, image size
	// based on bits, width, and height
	printf("header->offset %d\n",header ->offset);
	printf("header ->DIB_header_size %d\n",header->DIB_header_size);
	fseek(fptr, 0, SEEK_END);
	int num_bytes = ftell((fptr)-1);
	if((header -> type) != 0x4d42){
		return FALSE;
	}
	if((header -> bits) != 24){
		return FALSE;
	}
	if((header -> DIB_header_size) != DIB_HEADER_SIZE){
		return FALSE;
	}

	if((header -> planes) != 1){
		return FALSE;
	}
	if((header -> compression) != 0){
		return FALSE;
	}
	if((header -> ncolours || header -> importantcolours)!=0){
		return FALSE;
	}
	if((header -> offset)!= 54){
		return FALSE;
	}
	if((header -> size) != num_bytes){
		return FALSE;
	}
	if((num_bytes - BMP_HEADER_SIZE) != header-> imagesize){
		return FALSE;
	}
	return TRUE;
}

#endif



#ifndef BMP_OPEN_FILE
/* The input argument is the source file pointer.
 * The function returns an address to a dynamically allocated BMPImage
 * only if the file contains a valid image file
 * Otherwise, return NULL
 * If the function cannot get the necessary memory to store the image,
 * also return NULL
 * Any error messages should be printed to stderr
 */


BMPImage *BMP_Open(const char *filename) {

	// open file 	
	//Allocate memory for BMPImage*;

	//Read the first 54 bytes of the source into the header


	//Compute data size, width, height, and bytes per pixel;


	// Allocate memory for image data


	// read in the image data
	FILE* fp = fopen(filename, "r");
	//int four = 4;
	//char byte = '0';
	BMPImage* bmpImage = malloc(sizeof(BMPImage));
	//unsigned char* data = malloc(sizeof(unsigned char) * four);
	if(fp == NULL){
		fclose(fp);
		return NULL;
	}
	if(bmpImage == NULL){
		fclose(fp);
		return NULL;
	}
	fseek(fp, 0, SEEK_SET);
	if(fread(&(bmpImage -> header), 54,1,fp)!=1){
		fclose(fp);
		return NULL;
	}
	bmpImage->data = malloc(sizeof(unsigned char) * bmpImage->header.imagesize);
	if(fread(bmpImage->data,sizeof(char),bmpImage->header.imagesize,fp)!=(bmpImage->header.imagesize)){
		fclose(fp);
		return NULL;
	}	
	/* 
	//data[0]= ((bmpImage->header).size - BMP_HEADER_SIZE);//datasize
	//data[1] = (bmpImage ->header).width;//width
	//data[2] = (bmpImage -> header).height;//height
	//data[3] = (bmpImage -> header).bits;//bits
	(bmpImage -> data) = data;
	if(fread(bmpImage -> data,sizeof(char),bmpImage -> data[0],fp) != (bmpImage -> data[0])){
	fclose(fp);
	return NULL;
	}
	if(fread(&byte,sizeof(char),1,fp) != 0){
	fclose(fp);
	return NULL;
	}*/
	fclose(fp);
	return bmpImage;
}
#endif


#ifndef BMP_WRITE_FUNC
/* The input arguments are the destination file , BMPImage *image.
 * The function write the header and image data into the destination file.
 */
int BMP_Write(const char * outfile, BMPImage* image){
	// write header to the file
	// write image data to the file
	FILE* fp = fopen(outfile, "w");
	if(fp == NULL){
		return EXIT_FAILURE;
	}
	if(fwrite(&(image->header),BMP_HEADER_SIZE,1,fp) != 1)
	{
		fclose(fp);
		return EXIT_FAILURE;
	}
	if(fwrite(image->data,sizeof(char),((image->header).size-BMP_HEADER_SIZE),fp)!= ((image->header).size-BMP_HEADER_SIZE)){
		fclose(fp);
		return EXIT_FAILURE;
	}
	fclose(fp);
	return EXIT_SUCCESS;
}

#endif



/* The input argument is the BMPImage pointer. The function frees memory of
 * the BMPImage.
 */
#ifndef BMP_FREE_FUNC
void BMP_Free(BMPImage* image) {
	//free the data
	//free(&(image->header));
	free(image -> data);
	free(image);
}

#endif
