/****************************************************************************
 * apps/include/industry/foc/float/foc_angle.h
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

#ifndef __INDUSTRY_FOC_FLOAT_FOC_ANGLE_H
#define __INDUSTRY_FOC_FLOAT_FOC_ANGLE_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <dsp.h>

#include "industry/foc/float/foc_handler.h"

/****************************************************************************
 * Public Type Definition
 ****************************************************************************/

/* Input to angle handler */

struct foc_angle_in_f32_s
{
  FAR struct foc_state_f32_s *state; /* FOC state */
  float                       angle; /* Last angle */
  float                       vel;   /* Last velocity */
  float                       dir;   /* Movement direction */
};

/* Output from angle handler */

struct foc_angle_out_f32_s
{
  float angle;
};

/* Forward declaration */

typedef struct foc_angle_f32_s foc_angle_f32_t;

/* Angle operations */

struct foc_angle_ops_f32_s
{
  /* Initialize */

  CODE int (*init)(FAR foc_angle_f32_t *h);

  /* Deinitialize */

  CODE void (*deinit)(FAR foc_angle_f32_t *h);

  /* Configure */

  CODE int (*cfg)(FAR foc_angle_f32_t *h, FAR void *cfg);

  /* Run angle handler */

  CODE void (*run)(FAR foc_angle_f32_t *h,
                   FAR struct foc_angle_in_f32_s *in,
                   FAR struct foc_angle_out_f32_s *out);
};

/* Angle handler - sensor or sensorless */

struct foc_angle_f32_s
{
  FAR struct foc_angle_ops_f32_s *ops;
  FAR void                       *data;
};

#ifdef CONFIG_INDUSTRY_FOC_ANGLE_OPENLOOP
/* Open-loop configuration data */

struct foc_openloop_cfg_f32_s
{
  float per;                    /* Controller period */
};
#endif  /* CONFIG_INDUSTRY_FOC_ANGLE_OPENLOOP */

/****************************************************************************
 * Public Data
 ****************************************************************************/

#ifdef CONFIG_INDUSTRY_FOC_ANGLE_OPENLOOP
/* Open-loop angle operations (float) */

extern struct foc_angle_ops_f32_s g_foc_angle_ol_f32;
#endif

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Name: foc_angle_init_f32
 ****************************************************************************/

int foc_angle_init_f32(FAR foc_angle_f32_t *h,
                       FAR struct foc_angle_ops_f32_s *ops);

/****************************************************************************
 * Name: foc_angle_deinit_f32
 ****************************************************************************/

int foc_angle_deinit_f32(FAR foc_angle_f32_t *h);

/****************************************************************************
 * Name: foc_angle_cfg_f32
 ****************************************************************************/

int foc_angle_cfg_f32(FAR foc_angle_f32_t *h, FAR void *cfg);

/****************************************************************************
 * Name: foc_angle_run_f32
 ****************************************************************************/

void foc_angle_run_f32(FAR foc_angle_f32_t *h,
                       FAR struct foc_angle_in_f32_s *in,
                       FAR struct foc_angle_out_f32_s *out);

#endif /* __INDUSTRY_FOC_FLOAT_FOC_ANGLE_H */
