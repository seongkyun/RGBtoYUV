#pragma once
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define WIDTH 352
#define HEIGHT 288
#define Clamp(x)(x<0?0:(x>255?255:x))

typedef unsigned char uchar;

int ReadFrame(FILE *fin, uchar *in, int width, int height);
void WriteFrame(FILE *fout, uchar *in, int width, int height);
void RGB2YUV444(uchar *rgb, uchar *yuv, int width, int height);
void YUV4442RGB(uchar *yuv, uchar *rgb, int width, int height);