//DSPE_2012706141_한성균_Assignment11
#include "head.h"

void main()
{
	FILE *fin = fopen("Suzie_CIF_150_30.rgb", "rb");
	FILE *fyuv = fopen("[YUV]Suzie_CIF_150_30.rgb", "wb");
	FILE *frgb = fopen("[RGB]Suzie_CIF_150_30.rgb", "wb");

	uchar *in, *out;
	int num = 1;

	in = (uchar *)malloc(sizeof(uchar)*WIDTH*HEIGHT * 3);
	out = (uchar *)malloc(sizeof(uchar)*WIDTH*HEIGHT * 3);
	
	while (num = ReadFrame(fin, in, WIDTH, HEIGHT * 3))
	{				//프레임 읽기(프레임 읽기 실패 시 0 반환되며 자동으로 while 빠져나옴
		RGB2YUV444(in, out, WIDTH, HEIGHT);				
		WriteFrame(fyuv, out, WIDTH, HEIGHT * 3);
		YUV4442RGB(out, in, WIDTH, HEIGHT);
		WriteFrame(frgb, in, WIDTH, HEIGHT * 3);
	}

	free(in);
	free(out);
	
	fcloseall();
}