#include "head.h"

int ReadFrame(FILE *fin, uchar *in, int width, int height)
{
	return fread(in, sizeof(uchar), width*height, fin);	//읽기 성공 시 읽은 크기 반환(width*height)
}
void WriteFrame(FILE *fout, uchar *in, int width, int height)
{
	fwrite(in, sizeof(uchar), width*height, fout);
}
void RGB2YUV444(uchar *rgb, uchar *yuv, int width, int height)
{
	uchar *R, *G, *B;		//포인터 변수 선언

	R = rgb;					//포인터로 R, G, B 분리
	G = rgb + width*height;
	B = rgb + width*height * 2;

	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			yuv[j*width + i] = (uchar)((66 * R[j*width + i] + 129 * G[j*width + i] + 25 * B[j*width + i] + 128) >> 8) + 16;
			yuv[(j + height)*width + i] = (uchar)((-38 * R[j*width + i] - 74 * G[j*width + i] + 112 * B[j*width + i] + 128) >> 8) + 128;
			yuv[(j + height * 2)*width + i] = (uchar)((112 * R[j*width + i] - 94 * G[j*width + i] - 18 * B[j*width + i] + 128) >> 8) + 128;
		}
	}
}
void YUV4442RGB(uchar *yuv, uchar *rgb, int width, int height)
{
	uchar *Y, *U, *V;		//포인터 변수 선언

	Y = yuv;					//포인터로 Y, U, V 분리
	U = yuv + width*height;
	V = yuv + width*height * 2;

	int C, D, E;

	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			C = Y[j*width + i] - 16;
			D = U[j*width + i] - 128;
			E = V[j*width + i] - 128;

			rgb[j*width + i] = Clamp((298 * C + 409 * E + 128) >> 8);
			rgb[(j + height)*width + i] = Clamp((298 * C - 100 * D - 208 * E + 128) >> 8);
			rgb[(j + height * 2)*width + i] = Clamp((298 * C + 516 * D + 128) >> 8);
		}
	}
}