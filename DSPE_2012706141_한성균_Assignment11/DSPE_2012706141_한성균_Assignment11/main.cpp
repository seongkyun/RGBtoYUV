//DSPE_2012706141_�Ѽ���_Assignment11
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
	{				//������ �б�(������ �б� ���� �� 0 ��ȯ�Ǹ� �ڵ����� while ��������
		RGB2YUV444(in, out, WIDTH, HEIGHT);				
		WriteFrame(fyuv, out, WIDTH, HEIGHT * 3);
		YUV4442RGB(out, in, WIDTH, HEIGHT);
		WriteFrame(frgb, in, WIDTH, HEIGHT * 3);
	}

	free(in);
	free(out);
	
	fcloseall();
}