/*
  RIFF形式のwavファイルを読み込むプログラム，
  勉強用に作成
  使用予定は無し
  「C言語で始める 音のプログラミング」を元に作成
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



  pcm1.fs = pcm0.fs;
  pcm1.bits = pcm0.bits;
  pcm1.length = pcm0.length;
  pcm1.s = calloc(pcm1.length, sizeof(double));
  for (n = 0; n < pcm1.length; n++)
  {
    pcm1.s[n] = pcm0.s[n];
  }
  
  //mono_wave_write(&pcm1, "/Users/shugoto/test_origcopy.wav"); 
  
  free(pcm0.s); 
  free(pcm1.s); 
  
  return 0;
}
