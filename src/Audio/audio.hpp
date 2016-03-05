
#pragma once
#include <memory>

#include <OpenAL/al.h>
#include <OpenAL/alc.h>

#include "wav.hpp"


class Audio {
private:
  ALCdevice*  device;
  ALCcontext* context;

public:
  Audio();
  ~Audio();

  Audio(const Audio& src) = delete;
  Audio& operator=(const Audio& src) = delete;
};

class Media {
private:
  Wav source;

  ALuint buf_id;
  ALuint src_id;

public:
  explicit Media(const std::string& _path);
  ~Media();

  Media(const Media& src) = delete;
  Media& operator=(const Audio& src) = delete;

  Media* play();
  Media* stop();
  Media* pause();
  Media* setVolume(const float _volume);
  Media* setPitch(const float _pitch);
  Media* enableLoop();
  Media* disableLoop();

  // ‚Æ‚è‚ ‚¦‚¸Wavæ“¾‚Å‚«‚éŠÖ”—pˆÓ
  Wav* get();

  void show();
};