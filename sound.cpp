/*
 *  Пример отправки данных на звуковое устройство по 1024 байта
 *  g++ -o sound sound.cpp -lasound
 */
 
#include <alsa/asoundlib.h>
#include <fstream>
#include <iostream>
using namespace std;

char device[] = "default";            /* playback device */

 
int main(int argc, char** argv)
{
    int err;
    unsigned int i;
    snd_pcm_t *handle;
    snd_pcm_sframes_t frames;
    if (argc!=2){
        printf("Usage: sound filename.wav\n");
        return 1;
    }
    ifstream fs;
    fs.open(argv[1], ios::in | ios::binary);
    fs.seekg(0,ios_base::end);
    int bufsize = fs.tellg();
    fs.seekg(0);

    char *buffer = new char[bufsize];              /*буфер с данными из файла*/
    fs.read(buffer,bufsize);
    fs.close();
    if ((err = snd_pcm_open(&handle, device, SND_PCM_STREAM_PLAYBACK, 0)) < 0) {
        printf("Playback open error: %s\n", snd_strerror(err));
        exit(EXIT_FAILURE);
    }
    if ((err = snd_pcm_set_params(handle,
                      SND_PCM_FORMAT_U8,
                      SND_PCM_ACCESS_RW_INTERLEAVED,
                      1,
                      44100,
                      1,
                      500000)) < 0) {   /* 0.5sec */
        printf("Playback open error: %s\n", snd_strerror(err));
        exit(EXIT_FAILURE);
    }
    int offset=0;
    /* Цикл пока данные не кончатся */
    while (offset<bufsize) {

        frames = snd_pcm_writei(handle, (buffer+offset), 1024); //смещается указатель на актуальные данные
        offset+=frames;
        printf("offset: %d \n", offset);
        if (frames<0){
            frames = snd_pcm_recover(handle, frames, 0);
            printf("snd_pcm_writei failed: %s\n", snd_strerror(frames));
            break;
        }

    }
 
    err = snd_pcm_drain(handle);
    if (err < 0)
        printf("snd_pcm_drain failed: %s\n", snd_strerror(err));
    snd_pcm_close(handle);
    return 0;

}