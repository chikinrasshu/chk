#pragma once

#include <chk/types.h>

typedef struct renderer {
  s32_t _unused;
} renderer_t;

bool renderer_create(renderer_t *r, size_t max_cmds);
bool renderer_destroy(renderer_t *r);

bool renderer_begin_frame(renderer_t *r);
bool renderer_end_frame(renderer_t *r);
