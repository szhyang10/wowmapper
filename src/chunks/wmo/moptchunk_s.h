#pragma once

#include "../chunk_c.h"

struct MoptChunk_s : public Chunk_c {
  MoptChunk_s(Chunk_c *parent, off_t off)
      : Chunk_c(parent, off) {

  }
};
