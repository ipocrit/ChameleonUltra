#pragma once

#include "protocols.h"

extern const protocol em410x_64;
extern const protocol em410x_32;
extern const protocol em410x_16;
extern const protocol em410x_electra;

extern const protocol *em410x_protocols[];
extern size_t em410x_protocols_size;

bool em410x_is_base_type(tag_specific_type_t type);
const protocol *em410x_protocol_for_type(tag_specific_type_t type);

uint8_t em410x_t55xx_writer(uint8_t* uid, uint32_t* blks);
uint8_t em410x_electra_t55xx_writer(uint8_t* uid, uint32_t* blks);
