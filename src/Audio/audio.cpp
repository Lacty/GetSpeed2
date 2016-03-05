
#include "Audio.hpp"
#include <iostream>


Audio::Audio() {
  device  = alcOpenDevice(nullptr);
  context = alcCreateContext(device, nullptr);
  alcMakeContextCurrent(context);
}

Audio::~Audio() {
  alcMakeContextCurrent(nullptr);
  alcDestroyContext(context);
  alcCloseDevice(device);
}


Media::Media(const std::string& _path) :
source(_path.c_str())
{
  alGenBuffers(1, &buf_id);
  alGenSources(1, &src_id);

  // buf_idÇ…ÉfÅ[É^ÇåãÇ—Ç¬ÇØÇÈ
  alBufferData(buf_id,
               source.isStereo()
               ? AL_FORMAT_STEREO16
               : AL_FORMAT_MONO16,
               source.data(),
               source.size(),
               source.sampleRate());

  // src_idÇ…buf_idÇåãÇ—Ç¬ÇØÇÈ
  alSourcei(src_id, AL_BUFFER, buf_id);
}

Media::~Media() {
  alDeleteSources(1, &src_id);
  alDeleteBuffers(1, &buf_id);
}

Media* Media::play() {
  alSourcePlay(src_id);
  return this;
}

Media* Media::stop() {
  alSourceStop(src_id);
  return this;
}

Media* Media::pause() {
  alSourcePause(src_id);
  return this;
}

Media* Media::setVolume(const float _volume) {
  alSourcef(src_id, AL_GAIN, _volume);
  return this;
}

Media* Media::setPitch(const float _pitch) {
  alSourcef(src_id, AL_PITCH, _pitch);
  return this;
}

Media* Media::enableLoop() {
  alSourcei(src_id, AL_LOOPING, true);
  return this;
}

Media* Media::disableLoop() {
  alSourcei(src_id, AL_LOOPING, false);
  return this;
}

Wav* Media::get() { return &source; }

void Media::show() {
  ALint a;
  alGetIntegerv(AL_BYTE_OFFSET, &a);
  std::cout << a << std::endl;
}