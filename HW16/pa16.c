#include "pa16.h"

#ifndef MAIN_FUNC

int main(int argc, char **argv){
	// check the arguments
	//   // check radius and epsilon values
	//     // open the BMP file
	//       // convert to gray scale
	//       	// check for error in converting to gray scale
	//
	//       	  // call adaptive threshold function
	//       	    // check for errors after calling adaptive threshold
	//       	    	// write the adaptive threshold image to file
	//       	    		// free all the images
	//
	if(argc!=5)
	{
		printf("Wrong Arguements\n");
		return EXIT_FAILURE;
	}
	int radius = atoi(argv[3]);
	int epsilon = atoi(argv[4]);
	if(radius < 1 || epsilon < 0)
	{
		printf("Wrong Inputs\n");
		return EXIT_FAILURE;
	}
	BMPImage *image = BMP_Open(argv[1]);
	if(image == NULL)
	{
		return EXIT_FAILURE;
	}
	BMPImage *gimage = ImgToGray(image);
	if(gimage == NULL)
		printf("Error converting to Gray image\n");
		return EXIT_FAILURE;
	//BMPImage *aimage = AdaptiveThresholding(gimage,radius,epsilon);
//	if(aimage == NULL)
//		return EXIT_FAILURE;
	
	BMP_Write(argv[2],gimage);
	BMP_Free(image);
	BMP_Free(gimage);
	//BMP_Free(aimage);       	    			       	    			
	return EXIT_SUCCESS;
}
#endif 
