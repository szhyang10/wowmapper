#include "wdt_c.h"

Wdt_c::Wdt_c(Buffer_t *buf, const std::string &name)
    : Chunk_c(buf),
      name_(name),
      mphd_(this, 0xc),
      main_(this, mphd_.GetOffsetToNext()) {
  GenerateAdtNames();
}

void Wdt_c::GenerateAdtNames() {
  // go through all map tiles and retrieve adt positions and their names
  for (int y = 0; y < 64; y++) {
    for (int x = 0; x < 64; x++) {
      if(main_.map_tiles[y*64+x].flags & 1) {
        // create adt filename and push it to the vector
        std::stringstream tile_name;
        tile_name << name_ << "_" << x << "_" << y << ".adt";
        names_.push_back(tile_name.str()); // add name to adt list
      }
    }
  }

  std::cout << "ADTs: " << names_.size() << std::endl;
}