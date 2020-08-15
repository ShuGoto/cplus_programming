/*
  RIFF�`����wav�t�@�C����ǂݍ��ރv���O�����C
  �׋��p�ɍ쐬
  �g�p�\��͖���
*/



#include <stdio.h>
#include <stdlib.h>
#include "wave.h"

int main(void)
{
  MONO_PCM pcm0, pcm1;
  int n;
  const char* x = "/Users/shugoto/test-orig.wav";
  printf("%p", x);
  mono_wave_read(&pcm0, "/Users/shugoto/test-orig.wav"); 
  for(int i=0;i<100000;++i){
    printf("%f\n", pcm0.s[i]);
  }



  pcm1.fs = pcm0.fs; /* ?��W?��{?��?��?��?��?��g?��?�� */
  pcm1.bits = pcm0.bits; /* ?��ʎq?��?��?��?��?��x */
  pcm1.length = pcm0.length; /* ?��?��?��f?��[?��^?��̒�?��?�� */
  pcm1.s = calloc(pcm1.length, sizeof(double)); /* ?��?��?��?��?��?��?��̊m?��?�� */
  for (n = 0; n < pcm1.length; n++)
  {
    pcm1.s[n] = pcm0.s[n]; /* ?��?��?��f?��[?��^?��̃R?��s?��[ */
  }
  
  //mono_wave_write(&pcm1, "/Users/shugoto/test_origcopy.wav"); /* WAVE?��t?��@?��C?��?��?���??��?��m?��?��?��?��?��̉�?��f?��[?��^?��?��?��o?��͂�?��?�� */
  
  free(pcm0.s); /* ?��?��?��?��?��?��?��̉�?�� */
  free(pcm1.s); /* ?��?��?��?��?��?��?��̉�?�� */
  
  return 0;
}
