#ifndef BASEDATA
#define BASEDATA 
#include "texturestorage.h"
#include "soundstorage.h"
#include "fontstorage.h"
#include "musicstorage.h"
#include "uimaster.h"

// this class can be used by classes to access different base datas

struct BaseData
{
    TextureStorage ts;
    FontStorage fs;
    SoundStorage ss;
    MusicStorage ms;
};

void initBD(BaseData& b);
void updateBD(BaseData& b);
void drawBD(BaseData& b);

#endif