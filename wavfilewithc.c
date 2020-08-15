/*
  RIFF形式のwavファイルを読み込むプログラム，
  勉強用に作成
  使用予定は無し
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



  pcm1.fs = pcm0.fs; /* ?ｿｽW?ｿｽ{?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽg?ｿｽ?ｿｽ */
  pcm1.bits = pcm0.bits; /* ?ｿｽﾊ子?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽx */
  pcm1.length = pcm0.length; /* ?ｿｽ?ｿｽ?ｿｽf?ｿｽ[?ｿｽ^?ｿｽﾌ抵ｿｽ?ｿｽ?ｿｽ */
  pcm1.s = calloc(pcm1.length, sizeof(double)); /* ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽﾌ確?ｿｽ?ｿｽ */
  for (n = 0; n < pcm1.length; n++)
  {
    pcm1.s[n] = pcm0.s[n]; /* ?ｿｽ?ｿｽ?ｿｽf?ｿｽ[?ｿｽ^?ｿｽﾌコ?ｿｽs?ｿｽ[ */
  }
  
  //mono_wave_write(&pcm1, "/Users/shugoto/test_origcopy.wav"); /* WAVE?ｿｽt?ｿｽ@?ｿｽC?ｿｽ?ｿｽ?ｿｽﾉ??ｿｽ?ｿｽm?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽﾌ会ｿｽ?ｿｽf?ｿｽ[?ｿｽ^?ｿｽ?ｿｽ?ｿｽo?ｿｽﾍゑｿｽ?ｿｽ?ｿｽ */
  
  free(pcm0.s); /* ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽﾌ会ｿｽ?ｿｽ */
  free(pcm1.s); /* ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽﾌ会ｿｽ?ｿｽ */
  
  return 0;
}
