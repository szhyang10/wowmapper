#pragma once

#include "../chunk_c.h"

/*! \brief MHDR: Map Chunk Header. */
struct MhdrChunk_s : public Chunk_c {
  off_t mcin_off; //!< MCIN offset
  off_t mtex_off; //!< MTEX offset
  off_t mmdx_off; //!< MMDX offset
  off_t mmid_off; //!< MMID offset
  off_t mwmo_off; //!< MWMO offset
  off_t mwid_off; //!< MWID offset
  off_t mddf_off; //!< MDDF offset
  off_t modf_off; //!< MODF offset
  off_t mfbo_off; //!< MFBO offset
  off_t mh2o_off; //!< MH2O offset
  off_t mftx_off; //!< MFTX offset


  MhdrChunk_s(Chunk_c *parent, off_t off)
      : Chunk_c(parent, off) {
    mcin_off = GetValue<off_t>(0x04) + SUB_OFFSET;
    mtex_off = GetValue<off_t>(0x08) + SUB_OFFSET;
    mmdx_off = GetValue<off_t>(0x0c) + SUB_OFFSET;
    mmid_off = GetValue<off_t>(0x10) + SUB_OFFSET;
    mwmo_off = GetValue<off_t>(0x14) + SUB_OFFSET;
    mwid_off = GetValue<off_t>(0x18) + SUB_OFFSET;
    mddf_off = GetValue<off_t>(0x1c) + SUB_OFFSET;
    modf_off = GetValue<off_t>(0x20) + SUB_OFFSET;
    mfbo_off = GetValue<off_t>(0x24) ? GetValue<off_t>(0x24) + SUB_OFFSET : 0;
    mh2o_off = GetValue<off_t>(0x28) ? GetValue<off_t>(0x28) + SUB_OFFSET : 0;
    mftx_off = GetValue<off_t>(0x2c) ? GetValue<off_t>(0x2c) + SUB_OFFSET : 0;
  }

 private:
	const static off_t SUB_OFFSET = 0x14; // relative offset for sub chunks
};