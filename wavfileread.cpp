/*
dr_wavを用いてwaveファイル読み込み，テキストファイルに出力
モノラル専用，ステレオは未作成
*/

#include <iostream>
#include <fstream>

#define DR_WAV_IMPLEMENTATION
#include "dr_wav.h"



int main()
{
    drwav wav; //宣言
    int err = drwav_init_file(&wav, "/Users/shugoto/test-orig.wav", nullptr);//ファイル名わたす
    if(err == 0) throw std::runtime_error("drwav error");//エラー処理
    if(wav.channels != 1) throw std::runtime_error("must be one channel");
    int irLength = wav.totalPCMFrameCount;//フレーム数
    float* ir = new float[irLength];//読み込み用の配列
    drwav_read_pcm_frames_f32(&wav, irLength, ir); //読み込み

    //データをテキストファイルに出力
    const char *fileName = "/Users/shugoto/test-orig.text";
    std::ofstream ofs(fileName);
    if (!ofs)
    {
        std::cout << "ファイルが開けませんでした。" << std::endl;
        std::cin.get();
        return 0;
    }
    for (int i = 0; i < irLength ;i++)
    {
        ofs << ir[i] << std::endl;
    }
    

    drwav_uninit(&wav); //開放
}
