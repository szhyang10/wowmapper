#pragma once

#include "../chunk_c.h"

/*! \brief MMDX: Map Chunk M2 Names. */
struct MmdxChunk_s : public Chunk_c {
  std::string m2_names;


  MmdxChunk_s(Chunk_c *parent, off_t off)
      : Chunk_c(parent, off) {
    size_t name_size = GetSize();
    Buffer_t names(name_size);
    CopyVector(GetBuffer(), GetCurOffset()+DATA_OFFSET, name_size, &names);
    m2_names.assign(names.begin(), names.end());
  }
};
