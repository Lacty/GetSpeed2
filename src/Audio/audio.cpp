
#include "Audio.hpp"
#include <iostream>


Audio::Audio() {
  device_  = alcOpenDevice(nullptr);
  context_ = alcCreateContext(device_, nullptr);
  alcMakeContextCurrent(context_);
}

Audio::~Audio() {
  alcMakeContextCurrent(nullptr);
  alcDestroyContext(context_);
  alcCloseDevice(device_);
}


Media::Media(const std::string& _path) :
source_(_path.c_str())
{
  alGenBuffers(1, &buf_id_);
  alGenSources(1, &src_id_);

  // buf_idÇ…ÉfÅ[É^ÇåãÇ—Ç¬ÇØÇÈ
  alBufferData(buf_id_,
               source_.isStereo()
               ? AL_FORMAT_STEREO16
               : AL_FORMAT_MONO16,
               source_.data(),
               source_.size(),
               source_.sampleRate());

  // src_idÇ…buf_idÇåãÇ—Ç¬ÇØÇÈ
  alSourcei(src_id_, AL_BUFFER, buf_id_);
}

Media::~Media() {
  alDeleteSources(1, &src_id_);
  alDeleteBuffers(1, &buf_id_);
}

Media& Media::play() {
  alSourcePlay(src_id_);
  return *this;
}

Media& Media::stop() {
  alSourceStop(src_id_);
  return *this;
}

Media& Media::pause() {
  alSourcePause(src_id_);
  return *this;
}

Media& Media::setVolume(const float volume) {
  alSourcef(src_id_, AL_GAIN, volume);
  return *this;
}

Media& Media::setPitch(const float pitch) {
  alSourcef(src_id_, AL_PITCH, pitch);
  return *this;
}

Media& Media::enableLoop() {
  alSourcei(src_id_, AL_LOOPING, true);
  return *this;
}

Media& Media::disableLoop() {
  alSourcei(src_id_, AL_LOOPING, false);
  return *this;
}

const float Media::currentTime() {
  ALfloat current_time;
  alGetSourcef(src_id_, AL_SEC_OFFSET, &current_time);
  return current_time;
}